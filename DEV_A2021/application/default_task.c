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
	
	
void StartDefaultTask(void const * argument)
{
	while(1)
	{
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11);
	  HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_14);
	  printf("test\n");
		printf("hi");
  	osDelay(200);
	}
	
}



