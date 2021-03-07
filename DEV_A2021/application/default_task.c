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
#include "bsp_usart.h"

#include "mpu6500driver.h"


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
	//wrongD:\RM B&S 2020??\standard\user\APP\INS_task\INS_task.c
	
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
	
	//int rec=0;
  //	int16_t data=20000;
	//fp32 gyro[3], accel[3], temp;
	uint8_t mpu6500_spi_rxbuf[23];
	static mpu6500_real_data_t mpu6500_real_data; //????????MPU6500??
	
	mpu6500_init();
	while(1)
	{
		//led blink test
	  HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11);
	  HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_14);
		
		//usart2 test
	  printf("test\n");
		osDelay(200);
		mpu6500_read_over((mpu6500_spi_rxbuf + 1), &mpu6500_real_data);
		printf("%f\n",mpu6500_real_data.accel[0]);
		
	 //usart_printf("dma test\n");
		
		//scanf("%d",&rec);
		//printf("rec is %d\n",rec);
  	osDelay(50);
		
		//CAN_cmd_chassis(data,data,data,data);
		//osDelay(50);
		
		
		    

    
		

	}
	
}



