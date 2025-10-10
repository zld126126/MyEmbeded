/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-10-08     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#include "led.h"
#include "OLED.h"
#include "key.h"

rt_thread_t thread1, thread2, thread3;
unsigned char mode = 0;

void thread1_entry(void *p){
    unsigned char i = 0;
    while(1){
        // 添加调试信息，查看LED引脚的实际状态
        rt_kprintf("LED1=%d, LED2=%d, LED3=%d\n", LED1, LED2, LED3);
        rt_kprintf("Writing LED1=%d, LED2=%d, LED3=%d\n", i == 1?0:1, i == 2?0:1, i == 3?0:1);
        
        rt_pin_write(LED1, i == 1?0:1);
        rt_pin_write(LED2, i == 2?0:1);
        rt_pin_write(LED3, i == 3?0:1);
        
        // 读取引脚状态并打印
        rt_kprintf("Read LED1=%d, LED2=%d, LED3=%d\n", rt_pin_read(LED1), rt_pin_read(LED2), rt_pin_read(LED3));
        
        if (i == 3){
            rt_kprintf("thread1 running\n");
        }
        if (mode == 1){
            if (++i == 4){
                i = 1;
            }
        }else if(mode == 2){
            if (--i == 0 || i == 255){
                i = 3;
            }
        }
        rt_thread_mdelay(500);
    }
}

void thread2_entry(void *p){
    unsigned char key_num, key_down, key_old;
    while(1){
        key_num = Key_Entry();
        //消抖
        key_down = key_num & (key_num ^ key_old);
        key_old = key_num;
        switch(key_down){
            case 1:mode = 1;rt_kprintf("thread2 k1\n");break;
            case 2:mode = 2;rt_kprintf("thread2 k2\n");break;
        }
        rt_thread_mdelay(15);
    }
}

int main(void)
{
    // 初始化LED
    LED_Init();
    // 初始化OLED
    OLED_Init();
    // 初始化Key
    Key_Init();

    OLED_ShowString(1, 1, "thread test:");
    thread1 = rt_thread_create("thread1", thread1_entry, RT_NULL, 512, 15, 5);
    if (thread1 != RT_NULL){
        rt_thread_startup(thread1);
    }else{
        rt_kprintf("thread1 create error");
    }

    thread2 = rt_thread_create("thread2", thread2_entry, RT_NULL, 512, 15, 5);
    if (thread2 != RT_NULL){
        rt_thread_startup(thread2);
    }else{
        rt_kprintf("thread2 create error");
    }
    return RT_EOK;
}
