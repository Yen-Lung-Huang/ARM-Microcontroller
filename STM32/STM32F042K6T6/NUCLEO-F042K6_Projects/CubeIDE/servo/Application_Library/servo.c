#include "servo.h"


ServoTypeDef servo_constructor(ServoTypeDef servo_struct)
{
	HAL_TIM_PWM_Start(servo_struct.timer,servo_struct.channel);
	return servo_struct;
}

void servo_pwm_set(ServoTypeDef* servo, unsigned int pwm_value)
{
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_value;
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

/* GPIO_EXTI for adjust the calibration of servo */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_3 && HAL_GetTick()-last_time >= 100){
		last_time = HAL_GetTick();
		if( HAL_GetTick()-sub_last_time >= 300){
			last_time = HAL_GetTick();
			sub_last_time = HAL_GetTick();
			if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==false){
					rotate_dir = true;
				}
			else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==true){
				rotate_dir = false;
			}
		}
		if(servo[selected_servo].pwm_value+rotate_dir*2-1 < servo[selected_servo].pwm_min || servo[selected_servo].pwm_value == 0)
			servo[selected_servo].pwm_value = servo[selected_servo].pwm_min;
		else if(servo[selected_servo].pwm_value+rotate_dir*2-1 > servo[selected_servo].pwm_max || servo[selected_servo].pwm_value == 65535)
			servo[selected_servo].pwm_value = servo[selected_servo].pwm_max;
		else{
			servo[selected_servo].pwm_value += rotate_dir*2-1;
		}
		printf("servo[%d]= %d\r\n",selected_servo,servo[selected_servo].pwm_value);
	}
	if(GPIO_Pin == GPIO_PIN_0){
		selected_servo = 1;
	}
	if(GPIO_Pin == GPIO_PIN_8){
		selected_servo = 2;
	}
	if(GPIO_Pin == GPIO_PIN_9){
		selected_servo = 3;
	}
	if(GPIO_Pin == GPIO_PIN_10){
		selected_servo = 4;
	}
	if(GPIO_Pin == GPIO_PIN_11){
		selected_servo = 5;
	}
	if(selected_servo!=selected_servo_prev){
		printf("servo[%d]= %d\r\n",selected_servo,servo[selected_servo].pwm_value);
		selected_servo_prev=selected_servo;
	}
}


void json2servo(char *JSON_STRING, uint16_t token_size )
{
    jsmntok_t *tokens = malloc(sizeof(jsmntok_t)*token_size);
    jsmn_parser parser;
    jsmn_init(&parser);
    int token_num = jsmn_parse(&parser, JSON_STRING, strlen(JSON_STRING), tokens, sizeof(jsmntok_t)*token_size);
    
	  printf("\nJSON_STRING= %s\n",JSON_STRING);
    printf("strlen(JSON_STRING)= %d\n",strlen(JSON_STRING));
    printf("\nsizeof(jsmntok_t)*token_size= %d*%d = %d\n\n",sizeof(jsmntok_t),token_size,sizeof(jsmntok_t)*token_size);
	
    for (int i = 0; i < token_num; i++)
    {
        // printf("token<%.*s> ", tokens[i].end - tokens[i].start, JSON_STRING + tokens[i].start);
			  printf("\ntoken[%d].start= %d, token[%d].end-1= %d, end-start= %d\n",i,tokens[i].start,i,tokens[i].end-1,tokens[i].end-tokens[i].start);
        printf("%s\r\n\n",substr(JSON_STRING, tokens[i].start, tokens[i].end-1));
			
				printf("%s\r\n",substr(JSON_STRING, tokens[i].start, tokens[i].end-1));
				char *p = substr(JSON_STRING, 2, 6);
				printf("%s\r\n",p);
				if(p){free(p);}

        if (jsoneq(JSON_STRING, &tokens[i], "mode") == 0){
            if (tokens[i + 1].type != JSMN_STRING){
                continue; /* We expect groups to be an array of string */
            }
            char *mode = substr(JSON_STRING, tokens[i + 1].start, tokens[i + 1].end-1); //Desired variable
            printf("mode: ");// Do some stuff.
            if(!strcmp(mode,"nest")){
                printf("%s\n",mode); // Do some stuff.
            }
            else if(!strcmp(mode,"grab")){
                printf("%s\n",mode); // Do some stuff.
            }
            else if(!strcmp(mode,"collect")){
                printf("%s\n",mode); // Do some stuff.
            }

            i++; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "move") == 0){
            if (tokens[i + 1].type != JSMN_PRIMITIVE){
                continue; /* We expect groups to be an array of numeric */
            }
            float speed= atof(substr(JSON_STRING, tokens[i + 1].start, tokens[i + 1].end-1));  //Desired variable

            printf("move: %f\n", speed); // Do some stuff.
            //wheel_l=speed;
            //wheel_r=speed;

            i++; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "turn") == 0){
            if (tokens[i + 1].type != JSMN_PRIMITIVE){
                continue; /* We expect groups to be an array of numeric */
            }
            float speed= atof(substr(JSON_STRING, tokens[i + 1].start, tokens[i + 1].end-1));  //Desired variable

            printf("turn: %f\n", speed); // Do some stuff.

            i++; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "rc_servo") == 0){
            if (tokens[i + 1].type != JSMN_OBJECT){
                continue; /* We expect groups to be an array of json object */
            }
            printf("rc_servo: {");
            for (int j = 0; j < tokens[i + 1].size; j++)
            {
                if (tokens[i + j*2 + 2].type != JSMN_STRING){
                    continue; /* We expect groups to be an array of strings */
                }
                jsmntok_t *tok_key = &tokens[i + j*2 + 2];
                unsigned short int servo_num= atoi(substr(JSON_STRING, tok_key->start, tok_key->end-1));  //Desired variable

                jsmntok_t *tok_val = &tokens[i + j*2 + 3];
                unsigned short int pwm_val= atoi(substr(JSON_STRING, tok_val->start, tok_val->end-1));  //Desired variable

                printf("%d:%d", servo_num, pwm_val); // Do some stuff.
                if(j+1 < tokens[i + 1].size){
                    printf(", ");
                }
            }
            printf("}\n"); // Do some stuff.
            
            i += tokens[i + 1].size*2 + 1; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "adc") == 0){

            printf("adc..\n"); // Do some stuff.

            i++; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "rc_request") == 0){

            printf("rc_request..\n"); // Do some stuff.

            i++; // to next key token.
        }
        else if (tokens[i].type == JSMN_PRIMITIVE){
            short int step_val= atoi(substr(JSON_STRING, tokens[i].start, tokens[i].end-1));  //Desired variable

            printf("step_value= %d\n", step_val); // Do some stuff.
            i++; // to next key token.
        }
    }
}
