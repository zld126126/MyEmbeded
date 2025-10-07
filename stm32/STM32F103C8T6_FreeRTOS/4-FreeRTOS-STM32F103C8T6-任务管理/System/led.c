#include "led.h"

/*******************************************************************************
* 函 数 名         : LED_Init
* 函数功能		   : LED初始化函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//定义结构体变量
	
	RCC_APB2PeriphClockCmd(LED1_PORT_RCC|LED2_PORT_RCC|LED3_PORT_RCC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=LED1_PIN;  //选择要控制的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置为推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置输出速率
	GPIO_Init(LED1_PORT,&GPIO_InitStructure); 	   /* 初始化GPIO */
	GPIO_SetBits(LED1_PORT,LED1_PIN);   //将LED端口拉高，熄灭所有LED
	
	GPIO_InitStructure.GPIO_Pin=LED2_PIN;  //选择要控制的IO口
	GPIO_Init(LED2_PORT,&GPIO_InitStructure); 	   /* 初始化GPIO */
	GPIO_SetBits(LED2_PORT,LED2_PIN);   //将LED端口拉高，熄灭所有LED
	
	GPIO_InitStructure.GPIO_Pin=LED3_PIN;  //选择要控制的IO口
	GPIO_Init(LED3_PORT,&GPIO_InitStructure); 	   /* 初始化GPIO */
	GPIO_SetBits(LED3_PORT,LED3_PIN);   //将LED端口拉高，熄灭所有LED
	
	GPIO_InitStructure.GPIO_Pin=LED4_PIN;  //选择要控制的IO口
	GPIO_Init(LED4_PORT,&GPIO_InitStructure); 	   /* 初始化GPIO */
	GPIO_SetBits(LED4_PORT,LED4_PIN);   //将LED端口拉高，熄灭所有LED
}



