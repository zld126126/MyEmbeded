#include "key.h"
#include "SysTick.h"

/*******************************************************************************
* 函 数 名         : KEY_Init
* 函数功能		   : 按键初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量	
	RCC_APB2PeriphClockCmd(KEY_PIN_RCC,ENABLE);
	
//	GPIO_InitStructure.GPIO_Pin=KEY_UP_PIN;	   //选择要控制的IO口
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;//下拉输入  
//	GPIO_Init(KEY_UP_PORT,&GPIO_InitStructure);	  /* 初始化GPIO */
//	
//	GPIO_InitStructure.GPIO_Pin=KEY0_PIN|KEY1_PIN|KEY2_PIN;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	//上拉输入
//	GPIO_Init(KEY_PORT,&GPIO_InitStructure);
		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = KEY_PIN_1 | KEY_PIN_2;
	GPIO_Init(KEY_PORT_1, &GPIO_InitStructure);
		
}

/*******************************************************************************
* 函 数 名         : KEY_Scan
* 函数功能		   : 按键扫描函数
* 输    入         : mode=0:单次按键模式
			 mode=1:连续按键模式
* 输    出         : 0表示无按键按下
			 KEY_UP_PRESS表示KEY_UP按下
			 KEY0_PRESS表示KEY0按下
			 KEY1_PRESS表示KEY1按下
			 KEY2_PRESS表示KEY2按下
*******************************************************************************/
//u8 KEY_Scan(u8 mode)
//{
//	static u8 key=1;
//	
//	if(mode==1) //连续扫描按键
//		key=1;
//	if(key==1&&(KEY_UP==1||KEY0==0||KEY1==0||KEY2==0)) //有按键按下
//	{
//		delay_ms(10);  //延时消抖
//		key=0;
//		if(KEY_UP==1)
//			return KEY_UP_PRESS; 
//		else if(KEY0==0)
//			return KEY0_PRESS; 
//		else if(KEY1==0)
//			return KEY1_PRESS; 
//		else if(KEY2==0)
//			return KEY2_PRESS; 
//	}
//	else if(KEY_UP==0&&KEY0==1&&KEY1==1&&KEY2==1)    //无按键按下
//		key=1;
//	return 0;
//}

u8 KEY_Scan(u8 mode)
{
    static u8 last_key = 0;  // 记录上一次按键的状态
    u8 current_key = 0;      // 当前按键状态

    // 获取当前按键状态，注意按键：按下为0，释放为1
    if (KEY_1 == 0) {
        delay_ms(10);  // 延时消抖
        if (KEY_1 == 0) current_key = KEY_1_PRESS;  // 确认按键1按下
    } else if (KEY_2 == 0) {
        delay_ms(10);  // 延时消抖
        if (KEY_2 == 0) current_key = KEY_2_PRESS;  // 确认按键2按下
    }

    // 按键处理逻辑
    if (current_key != 0) {  // 有按键按下
        if (last_key == current_key) {  // 与上一次按键相同的情况下：
            if (mode == 1) {  // 连续按键模式
                return current_key;  // 直接返回对应值，表示连续按键
            } else {  // 单次按键模式
                return KEY_IGNORE_PRESS;  // 忽略按键
            }
        } else {  // 新的按键按下
            last_key = current_key;
            return current_key;  // 返回单次按键值
        }
    } else {  // 无按键按下
        last_key = 0;  // 清除上一次按键记录
        return 0;
    }
}
