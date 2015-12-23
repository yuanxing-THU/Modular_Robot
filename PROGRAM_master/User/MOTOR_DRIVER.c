#include "MOTOR_DRIVER.h"

void motor_GPIO_Congfiguration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	/* motor1 */
  GPIO_InitStructure.GPIO_Pin = Motor1_DIR_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(Motor1_DIR_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = Motor1_ENB_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(Motor1_ENB_GPIO, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = Motor1_STEP_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(Motor1_STEP_GPIO, &GPIO_InitStructure);
	
	
//	/* motor2 */
//  GPIO_InitStructure.GPIO_Pin = Motor2_DIR_Pin;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//  GPIO_Init(Motor2_DIR_GPIO, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = Motor2_ENB_Pin;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//  GPIO_Init(Motor2_ENB_GPIO, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = Motor2_STEP_Pin;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(Motor2_STEP_GPIO, &GPIO_InitStructure);
}

void motor_timer_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	/*TIM2*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t) (SystemCoreClock / 24000000) - 1;     
	TIM_TimeBaseStructure.TIM_Period = 11999;   //   ÆµÂÊ 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;      
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;    
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 6000;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC2Init(TIM2, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM2, ENABLE);

//  /*TIM3*/
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
//	TIM_DeInit(TIM3);
//	TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t) (SystemCoreClock / 24000000) - 1;     
//	TIM_TimeBaseStructure.TIM_Period = 11999;   //   ÆµÂÊ 
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;      
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
//	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;    
//	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//  TIM_OCInitStructure.TIM_Pulse = 6000;
//  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//  TIM_OC2Init(TIM3, &TIM_OCInitStructure);
//  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
//	TIM_ARRPreloadConfig(TIM3, ENABLE);
  
	Motor1_ENB;
	TIM_Cmd(TIM2, ENABLE);

}
