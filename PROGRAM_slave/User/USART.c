#include "USART.h"
#include "main.h"

void USART_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	/*USART RCC*/
  RCC_APB2PeriphClockCmd(USART2_GPIO_CLK, ENABLE);
  RCC_APB1PeriphClockCmd(USART2_CLK, ENABLE); 
	
	/*串口2 TX管脚配置*/
	
  /* Configure USART2 Rx as input floating */
  GPIO_InitStructure.GPIO_Pin = USART2_TxPin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(USART2_GPIO, &GPIO_InitStructure); 
	
  /*串口2 RX管脚配置*/
  /* Configure USART2 Rx as input floating */
  GPIO_InitStructure.GPIO_Pin = USART2_RxPin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(USART2_GPIO, &GPIO_InitStructure);
	
	
	
	USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
  USART_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;	//USART1发送/接收模式  中断模式
  USART_Init(USART1, &USART_InitStructure);
  
  USART_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;	//USART2发送/接收模式
  USART_Init(USART2, &USART_InitStructure);

  USART_Cmd(USART1, ENABLE);
  USART_Cmd(USART2, ENABLE);
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}
