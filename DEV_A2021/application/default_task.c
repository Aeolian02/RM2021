/**
  ****************************(C) COPYRIGHT 2019 DJI****************************
  * @file      default_task.c/h
  * @brief      test task
  * @note       
  * @history
  *  Version    Date            Author          Modification
  *  V1.0.0     Nov-11-2021     Aeolian              1. done
  *
  @verbatim
  ==============================================================================

  ==============================================================================
  @endverbatim
  ****************************(C) COPYRIGHT 2019 DJI****************************
  */

#include "default_task.h"
#include "main.h"
#include "cmsis_os.h"

#include "stdio.h"
#include "usart.h"
#include "CAN_receive.h"


#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
/**
  * @brief          test task
  * @param[in]      pvParameters: NULL
  * @retval         none
  */
/**
  * @brief          test»ŒŒÒ
  * @param[in]      pvParameters: NULL
  * @retval         none
  */
	
	//jansson Test
	
void jansson_pack_test(void)
{
cJSON * usr;
//cJSON *arry;

usr=cJSON_CreateObject(); //???????
cJSON_AddStringToObject(usr,"name","fengxin"); //????,????
cJSON_AddStringToObject(usr,"passwd","123");
cJSON_AddNumberToObject(usr,"num",1); //???

char *out = cJSON_Print(usr); //?json????????????
printf("%s\n",out);

// ????
cJSON_Delete(usr);
free(out);

//	/* Like above, ':', ',' and whitespace are ignored */
//	root = json_pack("{s:i, s:i}", "foo", 42, "bar", 7);

//	out = json_dumps(root, JSON_ENCODE_ANY);
//	printf("out:%s\r\n", out);
//	free(root);
//	free(out);
//	
//	/* Build the JSON array [[1, 2], {"cool": true}] */
//	root = json_pack("[[i,i],{s:b}]", 1, 2, "cool", 1);

//	out = json_dumps(root, JSON_ENCODE_ANY);
//	printf("out:%s\r\n", out);
//	free(root);
//	free(out);
//	
//	/* Build a string from a non-null terminated buffer */
//	char buffer[4] = {'t', 'e', 's', 't'};
//	root = json_pack("[s#]", buffer, 4);

//	out = json_dumps(root, JSON_ENCODE_ANY);
//	printf("out:%s\r\n", out);
//	free(root);
//	free(out);
//	
//	/* Concatenate strings together to build the JSON string "foobarbaz" */
//	root = json_pack("[s++]", "foo", "bar", "baz");
//	
//	out = json_dumps(root, JSON_ENCODE_ANY);
//	printf("out:%s\r\n", out);
//	free(root);
//	free(out);
}

	
void StartDefaultTask(void const * argument)
{
	
	
	int16_t data=20000;
	while(1)
	{
		//HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11);
	// HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_14);
	  printf("test\n");
	 //jansson_pack_test();
		
  	//osDelay(20);
		//CAN_cmd_gimbal(10,10,10,10);
		//CAN_cmd_chassis(16333,16333,16333,16333);
		CAN_cmd_gimbal(data,data,data,data);
		//osDelay(50);
		
		
		    

    
		//printf("%c",rx_data[0]);
		//osDelay(200);

	}
	
}



