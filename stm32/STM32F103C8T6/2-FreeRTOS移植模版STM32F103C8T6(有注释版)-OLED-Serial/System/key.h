#ifndef _key_H
#define _key_H


#include "system.h"
 
#define KEY0_PIN   			GPIO_Pin_4    	//定义KEY0引脚
#define KEY1_PIN    		GPIO_Pin_3    	//定义KEY1引脚
#define KEY2_PIN    		GPIO_Pin_2    	//定义KEY2引脚
#define KEY_UP_PIN  		GPIO_Pin_0  	//定义KEY_UP引脚

#define KEY_PORT 			GPIOE 		//按键端口
#define KEY_UP_PORT 		GPIOA 		//按键端口

//使用位操作定义
#define KEY_UP 	PAin(0)
#define KEY0 	PEin(4)
#define KEY1 	PEin(3)
#define KEY2 	PEin(2)

//按键操作结果宏定义  
#define KEY_UP_PRESS 	1
#define KEY0_PRESS		2
#define KEY1_PRESS		3
#define KEY2_PRESS		4

#define KEY_PIN_RCC RCC_APB2Periph_GPIOB
#define KEY_PIN_1 GPIO_Pin_1
#define KEY_PIN_2 GPIO_Pin_11
#define KEY_PORT_1 GPIOB
#define KEY_1 GPIO_ReadInputDataBit(KEY_PORT_1, KEY_PIN_1)
#define KEY_2 GPIO_ReadInputDataBit(KEY_PORT_1, KEY_PIN_2)
#define KEY_1_PRESS  	1
#define KEY_2_PRESS 	2
#define KEY_IGNORE_PRESS 3
 
void KEY_Init(void);
u8 KEY_Scan(u8 mode);

#endif
