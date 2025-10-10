#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "Key.h"
#include <rtthread.h>
#include <rtdbg.h>

rt_thread_t thread1, thread2;

void thread1_entry(void *p){
    while(1){
        //rt_kprintf("thread1 running\n");
				rt_kprintf("thread1 运行\n");
				LED2_Turn();
        rt_thread_mdelay(100);
    }
}

void thread2_entry(void *p){
		static uint8_t KeyNum;
    while(1){
        rt_kprintf("thread2 running\n");
				KeyNum = Key_GetNum();
				if (KeyNum == 1){
					LED1_Turn();
				}else if (KeyNum == 2){
					LED1_Turn();
				}
        rt_thread_mdelay(15);
    }
}

int main(void)
{
	/*模块初始化*/
	OLED_Init();
	LED_Init();
	Key_Init();
	
	OLED_ShowString(1, 1, "RT-Thread test!");

	thread1 = rt_thread_create("thread1", thread1_entry, RT_NULL, 512, 14, 5);
	if (thread1 != RT_NULL){
		rt_thread_startup(thread1);
	}else{
		rt_kprintf("thread1 create error\n");
	}
	
	thread2 = rt_thread_create("thread2", thread2_entry, RT_NULL, 512, 15, 5);
	if (thread2 != RT_NULL){
			rt_thread_startup(thread2);
	}else{
			rt_kprintf("thread2 create error\n");
	}
}
