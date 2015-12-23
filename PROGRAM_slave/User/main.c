/*
MODULAR ROBOT slave ����
MOTOR TIMER Ϊ TIM2 channel 2   MOTOR_DRIVER.h�г�ʼ��
TIM4 Ϊ�ⲿ�ж���ʱ  ���ڡ�������
TIM3 ��Ϊ�ܶ�����ʱ

*/
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"					//���õĿ��ļ�
#include "stdio.h"
#include "CAN.h"
#include "USART.h"
#include "EXTI.h"
#include "MOTOR_DRIVER.h"
#include "TIMER.h"

//Can
CanRxMsg RxMessage;
int can_flag_stutus;//�ظ�״̬
int can_flag_control;//����ת�Ǻͷ���


#define SLAVE_ID 0x01
//void CAN_TX(unsigned char data1,unsigned char data2,unsigned char data3);	//unsigned char add,//����CAN���ͺ���
//TestStatus CAN_RX(void);								   //���������ز�����CAN���պ���
//void Init_RxMes(CanRxMsg *RxMessage);        
void EXIT_ER(void );
int fputc(int ch, FILE *f);
extern void TIM3_Handler(void);
extern void TIM4_Handler(void);
/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int main(void)
{

	USART_Configuration();
	TIM_Congfiguration();
	EXTI_Congfiguration();
  CAN_Configuration();
	printf("Here is Modular Robot slave!\r\n");
	motor_GPIO_Congfiguration();
	motor_timer_Configuration();
	TIM_Cmd(TIM2, ENABLE);
	//TIM_Cmd(TIM4, ENABLE);
	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);	 //�������ж�
	while (1)
  { 
		if(can_flag_stutus == 1) //�ظ���ǰ״̬
		{
			
			uint8_t data[2] ;
			printf("slave recieve message from master!\r\n");
			data[0] = SLAVE_ID;
			data[1] = SLAVE_ID;
			CAN_SEND(SLAVE_ID,1,data);
			can_flag_stutus = 0;
		}
		if(can_flag_control == 1)
		{
			
			can_flag_control = 0;
		}
  }
}


void EXIT_ER(void)
{
	printf("exti!\r\n");
	EXTI->IMR &=~(1<<7) ;

	if(Motor1_DIR_STATE==1)
	{
		SET_Motor1_STATE_0;
	}else
	{
		SET_Motor1_STATE_1;
	}
	//printf("%d\r\n",Motor1_DIR_STATE);
	TIM_Cmd(TIM4, ENABLE);
	
}


void TIM3_Handler(void)
{
	TIM_Cmd(TIM3, DISABLE);
	printf("timer3 complete!\r\n");
	TIM_ARRPreloadConfig(TIM2, DISABLE);
}

void TIM4_Handler(void)
{
	TIM_Cmd(TIM4, DISABLE);
	printf("timer4 complete!\r\n");
	EXTI->IMR |=(1<<7) ;
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
//#ifdef  USE_FULL_ASSERT

///**
//  * @brief  Reports the name of the source file and the source line number
//  *         where the assert_param error has occurred.
//  * @param  file: pointer to the source file name
//  * @param  line: assert_param error line source number
//  * @retval None
//  */
//void assert_failed(uint8_t* file, uint32_t line)
//{ 
//  /* User can add his own implementation to report the file name and line number,
//     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

//  /* Infinite loop */
//  while (1)
//  {
//  }
//}
//#endif
