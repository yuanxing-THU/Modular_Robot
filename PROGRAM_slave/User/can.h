#ifndef CAN_H
#define CAN_H
#include "stm32f10x.h"					//调用的库文件
/*CAN*/
#define CAN_GPIO 								 GPIOA
#define CAN_CLK									 RCC_APB1Periph_CAN1
#define CAN_GPIO_CLK						 RCC_APB2Periph_GPIOA
#define CAN_RX									 GPIO_Pin_11
#define CAN_TX									 GPIO_Pin_12


void CAN_Configuration(void);							   //申明CAN初始化函数
void CAN_SEND(uint8_t ID,int NUM,uint8_t* data);
void Init_RxMes(CanRxMsg *RxMessage);
#endif

