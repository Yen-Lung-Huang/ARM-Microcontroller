#include "servo.h"
extern ServoTypeDef servo[];

ServoTypeDef servo_constructor(ServoTypeDef servo_struct)
{
	servo_struct.complementary?
	HAL_TIMEx_PWMN_Start(servo_struct.timer,servo_struct.channel):
	HAL_TIM_PWM_Start(servo_struct.timer,servo_struct.channel);
	return servo_struct;
}

volatile uint32_t* timer_ch2ccr(TIM_HandleTypeDef* timer, uint32_t channel)
{
	switch(channel){
		case TIM_CHANNEL_1:
			return &(timer->Instance->CCR1);
		case TIM_CHANNEL_2:
			return &(timer->Instance->CCR2);
		case TIM_CHANNEL_3:
			return &(timer->Instance->CCR3);
		case TIM_CHANNEL_4:
			return &(timer->Instance->CCR4);
	}
	return &(timer->Instance->CCR1); // A random return value for default, not nesseary.
}

/* Servo Motors Configuration--------------------------------------------------------*/
void servos_init(ServoTypeDef servo[12])
{
	servo[0 ] = servo_init(.timer=&htim2 , .channel=TIM_CHANNEL_2);														// 0 _Base
	servo[1 ] = servo_init(.timer=&htim2 , .channel=TIM_CHANNEL_4, .reverse=true);						// 1 _Shoulder   _L
	servo[2 ] = servo_init(.timer=&htim2 , .channel=TIM_CHANNEL_1, .latch=true);							// 2 _Elbow
	servo[3 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_1); 													// 3 _Wrist
	servo[4 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_2); 													// 4 _End-effecter
	servo[5 ] = servo_init(.timer=&htim14, .channel=TIM_CHANNEL_1, .offset=3); 								// 5 _Shoulder   _R
	servo[6 ] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_2, .offset=-21); 							// 6 _Wheel_Front_L
	servo[7 ] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_3, .offset=8, .reverse=true);														// 7 _Wheel_Front_R
	servo[8 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_3, .offset=3, .reverse=true);	// 8 _Wheel_Rear _L
	servo[9 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_4, .offset=-16); 													// 9 _Wheel_Rear _R
	servo[10] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_1); 													// 10_Wheel_Speed_L
	servo[11] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_4); 													// 11_Wheel_Speed_R
	
	for(int i=0; i<=11; i++){
		servo_pwm_set(&servo[i], servo[i].pwm_value);
	}
	HAL_Delay(1200);
	all_pwm_stop();
}

/* Math--------------------------------------------------------*/
float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double max(double a, double b)
{
	double q = sqrt((a-b)*(a-b));
	return ((a + b) + q) / 2;
}

/* Servo Motors Control--------------------------------------------------------*/
uint16_t reverse_pwm(ServoTypeDef* servo, uint16_t pwm_value)
{
	return servo->pwm_max - (pwm_value - servo->pwm_min);
}

void servo_pwm_stop(ServoTypeDef* servo)
{
	servo_wild_set(servo, 0);
}

void arm_pwm_stop(void)
{
	for(int i=0; i<=5; i++){
		servo_wild_set(&servo[i], 0);
		//printf("servo[%d].pwm_value= %d\r\n",i,servo[i].pwm_value); // debug print
	}
}

void all_pwm_stop(void)
{
	for(int i=0; i<=11; i++){
		servo_wild_set(&servo[i], 0);
	}
}

void servo_pwm_set(ServoTypeDef* servo, uint16_t pwm_value)
{
	const uint16_t duty_cycle_min = 20; // min: 18
	
	if(pwm_value < servo->pwm_min){
		pwm_value = servo->pwm_min;
	}
	else if(pwm_value > servo->pwm_max){
		pwm_value = servo->pwm_max;
	}

	servo->pwm_value = pwm_value;
	servo->return_pwm = pwm_value;
	
	if(servo->reverse == true){
		pwm_value = reverse_pwm(servo,pwm_value);
	}
	
	uint16_t pwm_set_value = pwm_value + servo->offset;
	
	if(pwm_set_value < duty_cycle_min){
		pwm_set_value = duty_cycle_min;
	}
	
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_set_value;
}

void servo_wild_set(ServoTypeDef* servo, uint16_t pwm_value)
{
	servo->pwm_value = pwm_value;
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_value + servo->offset;
}

void servo_degree_set(ServoTypeDef* servo, float degree)
{
	uint16_t pwm_value=map(degree,servo->physical_min,servo->physical_max,servo->pwm_min,servo->pwm_max);
	servo_pwm_set(servo,pwm_value);
}

float servo_get_degree(ServoTypeDef* servo)
{
	return map(servo->pwm_value,servo->pwm_min,servo->pwm_max,servo->physical_min,servo->physical_max);
}

typedef struct{
	uint16_t destination;
	uint16_t current;
	uint16_t difference;
	bool crescendo;
	float interval_time;
	uint16_t last_time;
}PwmTypeDef;

void arm_pwm_set(uint16_t pwm_dest[5])
{
	const float ms_per_pwm = 12.4;
	PwmTypeDef pwm[5];
	uint16_t max_pwm_diff = 0;
	
	for(int i=0;i<=4;i++){
		pwm[i].destination= pwm_dest[i];
		pwm[i].current=servo[i].pwm_value;
		short int raw_pwm_diff = pwm_dest[i]-servo[i].pwm_value;
		pwm[i].difference=abs(raw_pwm_diff);
		pwm[i].crescendo=(raw_pwm_diff>0)?true:false;
		//printf("|%d-%d|= %d\r\n",pwm_dest[i],servo[i].pwm_value,pwm[i].difference); // debug print.
		
		if(max(max_pwm_diff,pwm[i].difference)!=max_pwm_diff){ // Get max_pwm_diff
			max_pwm_diff = pwm[i].difference;
		}
		//printf("max_pwm_diff= %d\r\n",max_pwm_diff); // debug print.
	}
	//printf("certain_max_pwm_diff= %d\n\n",max_pwm_diff); // debug print.
	
	for(int i=0;i<=4;i++){
		pwm[i].interval_time=(float)max_pwm_diff/(float)pwm[i].difference*ms_per_pwm;
		//printf("pwm[%d].interval_time= %g\r\n",i,pwm[i].interval_time); // debug print.
		pwm[i].last_time=HAL_GetTick();
	}
	
	int start_time = HAL_GetTick();
	while(1){
		for(int i=0;i<=4;i++){
			int time_diff = HAL_GetTick()-pwm[i].last_time;
			if(time_diff>=pwm[i].interval_time){
				pwm[i].last_time=HAL_GetTick();
				uint8_t n = 1;
				if(time_diff>=pwm[i].interval_time*2){
					n = 2;
				}
				else if(time_diff>=pwm[i].interval_time*2.4){
					n = 3;
				}
				//printf("pwm[%d] -> [n= %d]\n",i,n); // debug print.
				
				pwm[i].current+=(pwm[i].crescendo*2-1)*n;
				if((pwm[i].crescendo==true && pwm[i].current > pwm[i].destination)
					||(pwm[i].crescendo==false && pwm[i].current < pwm[i].destination)){
					pwm[i].current=pwm[i].destination;
				}
				servo_pwm_set(&servo[i],pwm[i].current);
				if(i==1){
					servo_pwm_set(&servo[5],pwm[i].current);
				}
			}
		}
		if( (pwm[0].current==pwm[0].destination)
			&&(pwm[1].current==pwm[1].destination)
			&&(pwm[2].current==pwm[2].destination)
			&&(pwm[3].current==pwm[3].destination)
			&&(pwm[4].current==pwm[4].destination)
			&& HAL_GetTick()-start_time >= max_pwm_diff*(ms_per_pwm+2.4)){
			break;
		}
	}
}

void arm_set(uint16_t pwm_0, uint16_t pwm_1, uint16_t pwm_2, uint16_t pwm_3, uint16_t pwm_4)
{
	uint16_t pwm[]={pwm_0, pwm_1, pwm_2, pwm_3, pwm_4};
	arm_pwm_set(pwm);
}

void shoulder_set(uint16_t pwm_value)
{
	PwmTypeDef pwm;
	pwm.destination = pwm_value;
	pwm.current = servo[1].pwm_value;
	short int raw_pwm_diff = pwm_value-servo[1].pwm_value;
	pwm.difference=abs(raw_pwm_diff);
	pwm.crescendo=(raw_pwm_diff>0)?true:false;
	
	while(pwm.current!=pwm.destination){
		pwm.current+=pwm.crescendo*2-1;
		if((pwm.crescendo==true && pwm.current > pwm.destination)
			||(pwm.crescendo==false && pwm.current < pwm.destination)){
			pwm.current=pwm.destination;
		}
		servo_pwm_set(&servo[1],pwm.current);
		servo_pwm_stop(&servo[5]);
	}
}

