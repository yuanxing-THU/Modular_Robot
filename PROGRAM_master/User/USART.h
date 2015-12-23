#ifndef USART_H
#define USATT_H
#include "stm32f10x.h"					//调用的库文件
/*USART*/
#define USART2_GPIO              GPIOA
#define USART2_CLK               RCC_APB1Periph_USART2
#define USART2_GPIO_CLK          RCC_APB2Periph_GPIOA
#define USART2_RxPin             GPIO_Pin_3
#define USART2_TxPin             GPIO_Pin_2
#define USART2_IRQn              USART2_IRQn
#define USART2_IRQHandler        USART2_IRQHandler

void USART_Configuration(void);
#endif
