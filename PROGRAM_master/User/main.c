/*
MODULAR ROBOT master ����
*/
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"					//���õĿ��ļ�
#include "stdio.h"
#include "rcc.h"
#include "CAN.h"
#include "USART.h"
#include "EXTI.h"
#include "MOTOR_DRIVER.h"
#include "TIMER.h"




int fputc(int ch, FILE *f);
void EXIT_ER(void ); //����Թܽ����ⲿ�ж�
void TIM3_Handler(void); //TIM3�ⲿ�ж�
void TIM4_Handler(void); //TIM4�ⲿ�ж�


//can
CanRxMsg RxMessage;
int can_flag_receive = 0;
int flag_ask_status = 0;
/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int main(void)
{
	u32 i;
  RCC_Configuration();
	USART_Configuration();
	TIM_Congfiguration();
  CAN_Configuration();
	printf("Here is Modular Robot master!\r\n");
	TIM_Cmd(TIM3, ENABLE);
	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);	 //�������ж�
	
	while(1)
	{
		if(flag_ask_status == 1)  //ѯ�ʴӻ�״̬
		{
			uint8_t data = 0 ;
			CAN_SEND(0X00,1,&(data));
			flag_ask_status = 0;
			//printf("Master ask slave!\r\n");
		}
		
		if(can_flag_receive == 1) //�յ��ӻ�����
		{
			printf("Master receive slave %x!\r\n" ,RxMessage.StdId);
			can_flag_receive = 0;
		}
	}
}
void TIM3_Handler(void)
{
	flag_ask_status = 1;
	TIM_Cmd(TIM3, ENABLE);
}

int fputc(int ch, FILE *f)
{
    //USART_SendData(USART2, (uint8_t) ch);
    USART2->DR = (uint8_t) ch;
    //USART_SendData(USART2,(uint8_t)ch);
    /* Loop until the end of transmission */
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
    {
			
    }
    return ch;
}

