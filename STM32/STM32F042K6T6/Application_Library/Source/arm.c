#include "arm.h"
extern ServoTypeDef servo[];

/* Servo Motors Control--------------------------------------------------------*/
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

void arm_set(uint16_t pwm_0, uint16_t pwm_1, uint16_t pwm_2, uint16_t pwm_3, uint16_t pwm_4)
{
	uint16_t pwm[]={pwm_0, pwm_1, pwm_2, pwm_3, pwm_4};
	arm_pwm_set(pwm);
}

void arm_pwm_stop(void)
{
	for(int i=0; i<=5; i++){
		servo_wild_set(&servo[i], 0);
	}
}

/* Pose Set Function--------------------------------------------------------*/

