#include "bsp_default_test.h"
#include "main.h"



//extern UART_HandleTypeDef huart2;
//extern DMA_HandleTypeDef hdma_usart2_rx;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	/* 判断是哪个串口触发的中断 */
	if(huart ->Instance == USART2)
	{
		//将接收到的数据发送
		HAL_UART_Transmit_IT(huart, (uint8_t*)recv_buf, 13);
		//重新使能串口接收中断
		HAL_UART_Receive_IT(huart, (uint8_t*)recv_buf, 13);
	}
}

//´®¿ÚÖÐ¶Ï
void USART3_IRQHandler(void)
{
    if(huart2.Instance->SR & UART_FLAG_RXNE)//½ÓÊÕµ½Êý¾Ý
    {
        __HAL_UART_CLEAR_PEFLAG(&huart2);
    }
    else if(USART3->SR & UART_FLAG_IDLE)
    {
        static uint16_t this_time_rx_len = 0;

        __HAL_UART_CLEAR_PEFLAG(&huart2);

        if ((hdma_usart2_rx.Instance->CR & DMA_SxCR_CT) == RESET)
        {
            /* Current memory buffer used is Memory 0 */
    
            //disable DMA
            //Ê§Ð§DMA
            __HAL_DMA_DISABLE(&hdma_usart2_rx);

            //get receive data length, length = set_data_length - remain_length
            //»ñÈ¡½ÓÊÕÊý¾Ý³¤¶È,³¤¶È = Éè¶¨³¤¶È - Ê£Óà³¤¶È
            this_time_rx_len = SBUS_RX_BUF_NUM - hdma_usart2_rx.Instance->NDTR;

            //reset set_data_lenght
            //ÖØÐÂÉè¶¨Êý¾Ý³¤¶È
            hdma_usart2_rx.Instance->NDTR = SBUS_RX_BUF_NUM;

            //set memory buffer 1
            //Éè¶¨»º³åÇø1
            hdma_usart2_rx.Instance->CR |= DMA_SxCR_CT;
            
            //enable DMA
            //Ê¹ÄÜDMA
            __HAL_DMA_ENABLE(&hdma_usart2_rx);

            if(this_time_rx_len == RC_FRAME_LENGTH)
            {
                sbus_to_rc(sbus_rx_buf[0], &rc_ctrl);
            }
        }
        else
        {
            /* Current memory buffer used is Memory 1 */
            //disable DMA
            //Ê§Ð§DMA
            __HAL_DMA_DISABLE(&hdma_usart2_rx);

            //get receive data length, length = set_data_length - remain_length
            //»ñÈ¡½ÓÊÕÊý¾Ý³¤¶È,³¤¶È = Éè¶¨³¤¶È - Ê£Óà³¤¶È
            this_time_rx_len = SBUS_RX_BUF_NUM - hdma_usart2_rx.Instance->NDTR;

            //reset set_data_lenght
            //ÖØÐÂÉè¶¨Êý¾Ý³¤¶È
            hdma_usart2_rx.Instance->NDTR = SBUS_RX_BUF_NUM;

            //set memory buffer 0
            //Éè¶¨»º³åÇø0
            DMA1_Stream1->CR &= ~(DMA_SxCR_CT);
            
            //enable DMA
            //Ê¹ÄÜDMA
            __HAL_DMA_ENABLE(&hdma_usart2_rx);

            if(this_time_rx_len == RC_FRAME_LENGTH)
            {
                //´¦ÀíÒ£¿ØÆ÷Êý¾Ý
                sbus_to_rc(sbus_rx_buf[1], &rc_ctrl);
            }
        }
    }
}





