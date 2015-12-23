#include "EXTI.h"
#include "main.h"

void EXTI_Congfiguration(void)
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(S1_GPIO_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
//	/*GPIO PB8*/
//  GPIO_InitStructure.GPIO_Pin = S1_Pin;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//  GPIO_Init(S1_GPIO, &GPIO_InitStructure);
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource8);
//	/* Configure PB8  EXTI9_5 line */
//  EXTI_InitStructure.EXTI_Line = EXTI_Line8;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);

//	
//	/*GPIO PB9*/
//  GPIO_InitStructure.GPIO_Pin = S2_Pin;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//  GPIO_Init(S2_GPIO, &GPIO_InitStructure);
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource9);
//	/* Configure PB9  EXTI9_5 line */
//  EXTI_InitStructure.EXTI_Line = EXTI_Line9;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);
	
	
//	/*GPIO PB6*/
//  GPIO_InitStructure.GPIO_Pin = ES_Pin;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//  GPIO_Init(ES_GPIO, &GPIO_InitStructure);
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6);
//	/* Configure PB6  EXTI9_5 line */
//  EXTI_InitStructure.EXTI_Line = EXTI_Line6;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);
	
	
	/*GPIO PB7*/
  GPIO_InitStructure.GPIO_Pin = ER_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(ER_GPIO, &GPIO_InitStructure);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource7);
	/* Configure PB7  EXTI9_5 line */
  EXTI_InitStructure.EXTI_Line = EXTI_Line7;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
	
	
	/*NVIC */
  /* Enable and set EXTI9_5 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
}

