#include "core.h"
extern ServoTypeDef servo[];

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

/* Robot with JSON--------------------------------------------------------*/
bool json_action(char *JSON_STRING, uint16_t token_size) //sizeof(char)*strlen(JSON_STRING)
{
    cJSON *root = cJSON_ParseWithLength(JSON_STRING, token_size);
    if(root == NULL){
        // printf("invalid JSON\r\n"); // Print for debug.
        return false;
    }
		
    for (cJSON *token = root->child;token != NULL;token = token->next){
        if(!strcmp(token->string,"mode")){
            if(cJSON_IsString(cJSON_GetObjectItem(root,"mode")) == false){
                continue;
            }
            if(!strcmp(token->valuestring,"nest")){
								printf("A\r\n");
                // printf("%s:%s\n",token->string,token->valuestring); // Print for debug.
            }
            else if(!strcmp(token->valuestring,"grab")){
								printf("B\r\n");
								// printf("%s:%s\n",token->string,token->valuestring); // Print for debug.
            }
            else if(!strcmp(token->valuestring,"collect")){
								printf("C\r\n");
                // printf("%s:%s\n",token->string,token->valuestring); // Print for debug.
            }
        }

        else if(!strcmp(token->string,"move")){
            if(cJSON_IsNumber(cJSON_GetObjectItem(root,"move")) == true){
							float speed= token->valuedouble; // Desired variable
							// printf("%s:%f\r\n",token->string, speed); // Do some stuff. // Print for debug.
							move(speed);
            }
						else if(cJSON_IsString(cJSON_GetObjectItem(root,"move")) == true){
							if(!strcmp(token->valuestring,"wait")){
								// printf("%s:wait\r\n",token->string); // Do some stuff. // Print for debug.
								// wheels_stop();
								all_pwm_stop();
							}
					}
        }
        
        else if(!strcmp(token->string,"turn")){
            if(cJSON_IsNumber(cJSON_GetObjectItem(root,"turn")) == false){
                continue;
            }
            float speed= token->valuedouble; // Desired variable
            // printf("%s:%f\r\n",token->string, speed); // Do some stuff. // Print for debug.
						turn(speed);
        }
        
        else if(!strcmp(token->string,"rc_servo")){
            cJSON *json_obj = cJSON_GetObjectItem(root, "rc_servo");
            if(json_obj!=NULL){
                if(cJSON_IsObject(json_obj) == false){
                    continue;
                }
								// printf("%s:",token->string); // Print for debug.
                // printf("{"); // Print for debug.
								
                for(cJSON *obj_token = json_obj->child; obj_token!= NULL; obj_token=obj_token->next){
                    uint8_t servo_num= atoi(obj_token->string); // Desired variable
                    if(/*servo_num>=0 &&*/ servo_num<=11){
                      uint8_t pwm_val= obj_token->valueint;
											if(servo_num==1||servo_num==5){
												//servo_pwm_set(&servo[servo_num],pwm_val);
												//servo_wild_set(&servo[servo_num],pwm_val);
												//servo_pwm_set(&servo[servo_num],map(pwm_val,0,100,servo[servo_num].pwm_min,servo[servo_num].pwm_max));
												//shoulder_set(pwm_val);
												//shoulder_set(map(pwm_val,0,100,servo[servo_num].pwm_min,servo[servo_num].pwm_max));
												shoulder_set(map(pwm_val,0,100,servo[servo_num].physical_min,servo[servo_num].physical_max));
											}
											else{
												//servo_pwm_set(&servo[servo_num],pwm_val);
												servo_pwm_set(&servo[servo_num],map(pwm_val,0,100,servo[servo_num].pwm_min,servo[servo_num].pwm_max));
											}
										
											// printf("%d:%d",servo_num,servo[servo_num].pwm_value); // Print for debug.
											// printf("(degree=%g, %d%%)",servo_get_physical(&servo[servo_num]),(int)map(servo[servo_num].pwm_value,servo[servo_num].pwm_min,servo[servo_num].pwm_max,0,100)); // Print for debug.
											
											if(obj_token->next!= NULL){
													// printf(", "); // Print for debug.
											}
                    }
                }
                // printf("}\r\n"); // Print for debug.
            }
        }
				else if(!strcmp(token->string,"rc_servo_degree")){
            cJSON *json_obj = cJSON_GetObjectItem(root, "rc_servo_degree");
            if(json_obj!=NULL){
                if(cJSON_IsObject(json_obj) == false){
                    continue;
                }
								// printf("%s:",token->string); // Print for debug.
                // printf("{"); // Print for debug.
								
                for(cJSON *obj_token = json_obj->child; obj_token!= NULL; obj_token=obj_token->next){
                    uint8_t servo_num= atoi(obj_token->string); // Desired variable
                    if(/*servo_num>=0 &&*/ servo_num<=11){
                        float degree_val= obj_token->valuedouble;
												servo_physical_set(&servo[servo_num],degree_val);
											
                        // printf("%d:%g(pwm=%d)",servo_num,degree_val,servo[servo_num].pwm_value); // Print for debug.
                        if(obj_token->next!= NULL){
                            // printf(", "); // Print for debug.
                        }
                    }
                }
                // printf("}\r\n"); // Print for debug.
            }
        }
        else if(!strcmp(token->string,"adc")){
            //printf("%f\r\n",read_adc()); // send adc value
						//printf("%d\n",(int)map(read_adc(),0,3.26,0,100)); // send adc value by %
						printf("%d\r\n",(int)map((10800000-(float)HAL_GetTick())/10800000,0,1,0,82.5));
        }
        else if(!strcmp(token->string,"rc_request")){
					printf("[");
					for(int i=0; i<=5; i++){
						if(i==2){
							i++;
						}
						printf("%d",(int)map(servo[i].return_pwm,servo[i].pwm_min,servo[i].pwm_max,0,100)); // send pwm value by %
						if(i+1<=5){
							printf(",");
						}
					}
					printf("]\r\n");
        }
    }
    cJSON_Delete(root);
		return 1;
}
