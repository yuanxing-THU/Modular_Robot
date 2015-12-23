#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H
#include "stm32f10x.h"					//调用的库文件

#define Motor1_DIR_GPIO       GPIOA
#define Motor1_DIR_Pin        GPIO_Pin_4
#define Motor1_ENB_GPIO       GPIOA
#define Motor1_ENB_Pin		    GPIO_Pin_5
#define Motor1_STEP_GPIO      GPIOA
#define Motor1_STEP_Pin       GPIO_Pin_1

#define Motor2_DIR_GPIO       GPIOB
#define Motor2_DIR_Pin        GPIO_Pin_1
#define Motor2_ENB_GPIO       GPIOB
#define Motor2_ENB_Pin		    GPIO_Pin_2
#define Motor2_STEP_GPIO      GPIOA
#define Motor2_STEP_Pin       GPIO_Pin_7

#define Motor1_ENB	          GPIO_ResetBits(Motor1_ENB_GPIO, Motor1_ENB_Pin)
#define Motor2_ENB            GPIO_ResetBits(Motor2_ENB_GPIO, Motor2_ENB_Pin)
#define Motor1_DISABLE        GPIO_ResetBits(Motor1_ENB_GPIO, Motor1_ENB_Pin)
#define Motor2_DISABLE        GPIO_ResetBits(Motor2_ENB_GPIO, Motor2_ENB_Pin)

#define Motor1_DIR_STATE      GPIO_ReadOutputDataBit(Motor1_DIR_GPIO,Motor1_DIR_Pin)
#define SET_Motor1_STATE_0	  GPIO_ResetBits(Motor1_DIR_GPIO, Motor1_DIR_Pin)
#define SET_Motor1_STATE_1	  GPIO_SetBits(Motor1_DIR_GPIO, Motor1_DIR_Pin)

void motor_GPIO_Congfiguration(void);
void motor_timer_Configuration(void);

#endif
