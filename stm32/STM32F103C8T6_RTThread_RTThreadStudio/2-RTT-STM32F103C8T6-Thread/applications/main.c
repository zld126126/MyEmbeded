/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-10-07     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#include "led.h"
#include "OLED.h"

rt_thread_t thread1, thread2, thread3;

void thread1_entry(void *p){
    while(1){
        rt_kprintf("thread1 running\n");
        rt_thread_mdelay(10);
    }
}

void thread2_entry(void *p){
    while(1){
        rt_kprintf("thread2 running\n");
        rt_thread_mdelay(10);
    }
}

void thread3_entry(void *p){
    while(1){
        rt_kprintf("thread3 running\n");
        rt_thread_mdelay(10);
    }
}

int main(void)
{
    // 初始化LED
    LED_Init();
    // 初始化OLED
    OLED_Init();

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

    thread3 = rt_thread_create("thread3", thread3_entry, RT_NULL, 512, 15, 5);
    if (thread1 != RT_NULL){
        rt_thread_startup(thread3);
    }else{
        rt_kprintf("thread3 create error");
    }
    return RT_EOK;
}
