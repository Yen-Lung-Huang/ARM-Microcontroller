#include "core.h"


/* Math--------------------------------------------------------*/
//float map(float x, float in_min, float in_max, float out_min, float out_max)
//{
//  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
//}

//double max(double a, double b)
//{
//	double q = sqrt((a-b)*(a-b));
//	return ((a + b) + q) / 2;
//}

/* Debug--------------------------------------------------------*/
void print_binary(uint8_t byteData) {
	int size = sizeof(byteData)* 8;
	char bits[size + 1];
	bits[0] = '\0'; //初始化為空字串
	
  for (int i = 0; i < size; i++) {
    // 判斷 byteData 的第 i 位是 1 還是 0，並將其寫入到 bits 的(倒數)第 i 個元素
    if (byteData & (1 << i)) {
			strcat(bits, "1");
    } else {
			strcat(bits, "0");
    }
	}
	printf("%s\n", bits); // 使用 printf 函數，並使用 %s 格式符來輸出 binary
}


/* Robot with JSON--------------------------------------------------------*/
bool json_action(char *JSON_STRING, uint16_t token_size) //sizeof(char)*strlen(JSON_STRING)
{
    cJSON *root = cJSON_ParseWithLength(JSON_STRING, token_size);
    if(root == NULL){
        printf("invalid JSON\r\n"); // Print for debug.
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
				
				else if(!strcmp(token->string,"74HC595")){
            int size = cJSON_GetArraySize(token); //取得 array 的元素數量
						uint8_t byteData = 0; //宣告一個 uint8_t 變數，並初始化為 0

            for(int i = 0; i < size; i++){ //迴圈遍歷 array 的每個元素
							int value = cJSON_GetArrayItem(token, i)->valueint; //取得第 i 個元素的值
							
							//根據 value 的值，將 byteData 的第 i 位設為 1 或 0
							if (value == 1) {
								byteData |= (1 << i); //使用位元或運算符，將 byteData 的第 i 位設為 1
							} else {
								byteData &= ~(1 << i); //使用位元與運算符，將 byteData 的第 i 位設為 0
							}
            }
						
						//HC595_SendByte(&motor_shield_v1.hc595, byteData); //調用 HC595_SendByte 函數，將 byteData 作為參數傳遞
						print_binary(byteData); // Print for debug.

        }

        else if(!strcmp(token->string,"adc")){
            //printf("%f\r\n",read_adc()); // send adc value
						//printf("%d\n",(int)map(read_adc(),0,3.26,0,100)); // send adc value by %
						printf("%d\r\n",(int)map((10800000-(float)HAL_GetTick())/10800000,0,1,0,82.5));
        }

    }
    cJSON_Delete(root);
		return 1;
}
