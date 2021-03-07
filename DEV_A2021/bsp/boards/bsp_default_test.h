#ifndef BSP_DEF_H
#define BSP_DEF_H
#include "struct_typedef.h"
#include "main.h"

uint8_t hello[] = "USART2 is ready...\n";
uint8_t recv_buf[13] = {0};
//#define I2C_ACK 1
//#define I2C_NO_ACK  0


extern void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

//extern void bsp_I2C_reset(I2C_TypeDef *I2C);
//extern void bsp_I2C_master_transmit(I2C_TypeDef *I2C, uint16_t I2C_address, uint8_t *data, uint16_t len);
//extern bool_t bsp_I2C_check_ack(I2C_TypeDef *I2C, uint16_t I2C_address);

//extern void I2C2_tx_DMA_init(void);
//extern void I2C2_DMA_transmit(uint16_t DevAddress, uint8_t *pData, uint16_t Size);



#endif
