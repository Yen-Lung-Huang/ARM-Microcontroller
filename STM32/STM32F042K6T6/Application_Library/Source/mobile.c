#include "mobile.h"
extern ServoTypeDef servo[];

/* Servo Motors Control--------------------------------------------------------*/
void wheels_degree_set(float front_left, float front_right, float rear_left, float rear_right)
{
	servo_physical_set(&servo[6],front_left);		// Wheel_Front_L
	servo_physical_set(&servo[7],front_right);	// Wheel_Front_R
	servo_physical_set(&servo[8],rear_left);		// Wheel_Rear _L
	servo_physical_set(&servo[9],rear_right);		// Wheel_Rear _R
}

void wheels_speed_set(float left_speed, float right_speed)
{
	servo_physical_set(&servo[10],left_speed);	// Wheel_Speed_L
	servo_physical_set(&servo[11],right_speed);	// Wheel_Speed_R
}

void wheels_stop(void)
{
	servo_wild_set(&servo[10], 0);
	servo_wild_set(&servo[11], 0);
}

void mobile_pwm_stop(void)
{
	for(int i=6; i<=11; i++){
		servo_wild_set(&servo[i], 0);
	}
}

/* Set Pose--------------------------------------------------------*/
void turn_set(bool turn)
{
	if(turn == true){
		wheels_degree_set(56.35,56.35,65.25,65.25);
	}
	else{
		wheels_degree_set(0,0,0,0);
	}
}

/* Move--------------------------------------------------------*/
void move(float speed)
{
	turn_set(false);
	speed ? wheels_speed_set(speed,speed):wheels_stop();
}

void turn(float speed)
{
	turn_set(true);
	speed ? wheels_speed_set(speed,reverse_physical(&servo[11],speed)):wheels_stop();
}
