#include "TIMER.h"
#include "main.h"
void TIM_Congfiguration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	/*TIMER3 */
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_DeInit(TIM3);
	TIM_TimeBaseStructure.TIM_Prescaler = 50000;   //1440hz
	TIM_TimeBaseStructure.TIM_Period = (uint16_t)(1440 * TIM3_VALUE); 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;      
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;    
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 
	TIM_ARRPreloadConfig(TIM3, ENABLE); 
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);	
	TIM_ARRPreloadConfig(TIM3, DISABLE);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	/*TIMER4 */
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;//
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	TIM_DeInit(TIM4);
	TIM_TimeBaseStructure.TIM_Prescaler = 50000;   //1440hz
	TIM_TimeBaseStructure.TIM_Period = (uint16_t)1440 * TIM4_VALUE; 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;      
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;    
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 
	TIM_ARRPreloadConfig(TIM4, ENABLE); 
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);	
	TIM_ARRPreloadConfig(TIM4, DISABLE);
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
	

}