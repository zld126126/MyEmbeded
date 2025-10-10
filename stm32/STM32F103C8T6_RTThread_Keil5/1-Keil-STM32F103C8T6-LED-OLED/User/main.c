#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include <rtthread.h>
#include <rtdbg.h>

rt_thread_t thread1;
uint8_t flag;

void thread1_entry(void *p){
    while(1){
        rt_kprintf("thread1 running\n");
				flag = !flag;
				if (flag){
					LED1_ON();
					LED2_OFF();
					
					OLED_ShowString(4, 1, "thread1 run");
				}else{
					LED1_OFF();
					LED2_ON();
					
					OLED_ShowString(3, 1, "thread1 run");
				}
        rt_thread_mdelay(500);
    }
}

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	LED_Init();

	thread1 = rt_thread_create("thread1", thread1_entry, RT_NULL, 512, 15, 5);
	if (thread1 != RT_NULL){
		rt_thread_startup(thread1);
		rt_kprintf("thread1 create success\n");
	}else{
		rt_kprintf("thread1 create error\n");
	}
}
