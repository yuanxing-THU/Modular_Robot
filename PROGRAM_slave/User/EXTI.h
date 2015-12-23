#ifndef EXTI_H
#define EXTI_H
#include "stm32f10x.h"					//调用的库文件

#define S1_GPIO                  GPIOB
#define S1_GPIO_CLK							 RCC_APB2Periph_GPIOB
#define S1_Pin    							 GPIO_Pin_8
#define S2_GPIO                  GPIOB
#define S2_GPIO_CLK							 RCC_APB2Periph_GPIOB
#define S2_Pin    							 GPIO_Pin_9
#define ES_GPIO                  GPIOB
#define ES_GPIO_CLK							 RCC_APB2Periph_GPIOB
#define ES_Pin    							 GPIO_Pin_6
#define ER_GPIO                  GPIOB
#define ER_GPIO_CLK							 RCC_APB2Periph_GPIOB
#define ER_Pin    							 GPIO_Pin_7

void EXTI_Congfiguration(void);

#endif
