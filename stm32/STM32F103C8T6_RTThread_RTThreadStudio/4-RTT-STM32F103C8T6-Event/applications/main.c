/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-10-09     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#include "led.h"
#include "OLED.h"
#include "key.h"

#define LOC(i) 0x01<<i

// 事件标志定义
#define EVENT_LED1 LOC(0)  // 二进制: 0001
#define EVENT_LED2 LOC(1)  // 二进制: 0010
#define EVENT_LED3 LOC(2)  // 二进制: 0100
#define EVENT_ALL  (EVENT_LED1 | EVENT_LED2 | EVENT_LED3)  // 二进制: 0111

rt_thread_t thread_led_control;
rt_thread_t thread_key;
rt_event_t led_event;

// LED状态变量
unsigned char led1_state = 0;
unsigned char led2_state = 0;
unsigned char led3_state = 0;

// LED控制主线程 - 单个线程处理所有LED事件
void thread_led_control_entry(void *p)
{
    rt_uint32_t recv_event;
    
    while(1)
    {
        // 使用OR模式接收任意一个LED事件，同时设置清除标志
        if(rt_event_recv(led_event, EVENT_ALL, RT_EVENT_FLAG_OR|RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_event) == RT_EOK)
        {
            // 根据接收到的事件标志，处理对应的LED
            if(recv_event & EVENT_LED1)
            {
                led1_state ^= 0x01;  // 翻转状态
                rt_kprintf("LED1 event received, new state: %d\n", led1_state);
                rt_pin_write(LED1, !led1_state);  // 低电平点亮
            }
            
            if(recv_event & EVENT_LED2)
            {
                led2_state ^= 0x01;  // 翻转状态
                rt_kprintf("LED2 event received, new state: %d\n", led2_state);
                rt_pin_write(LED2, !led2_state);  // 低电平点亮
            }
            
            if(recv_event & EVENT_LED3)
            {
                led3_state ^= 0x01;  // 翻转状态
                rt_kprintf("LED3 event received, new state: %d\n", led3_state);
                rt_pin_write(LED3, !led3_state);  // 低电平点亮
            }
        }
    }
}

// 按键处理线程
void thread_key_entry(void *p)
{
    unsigned char key_num, key_down, key_old;
    
    while(1)
    {
        key_num = Key_Entry();
        // 消抖
        key_down = key_num & (key_num ^ key_old);
        key_old = key_num;
        
        switch(key_down)
        {
            case 1:
                rt_event_send(led_event, EVENT_LED1);
                rt_kprintf("Key1 pressed, sending LED1 event\n");
                break;
            case 2:
                rt_event_send(led_event, EVENT_LED2);
                rt_kprintf("Key2 pressed, sending LED2 event\n");
                break;
            case 3:
                rt_event_send(led_event, EVENT_LED3);
                rt_kprintf("Key3 pressed, sending LED3 event\n");
                break;
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

    // 创建事件
    led_event = rt_event_create("led", RT_IPC_FLAG_FIFO);

    // 在OLED上显示信息
    OLED_ShowString(1, 1, "Single-Thread LED Ctrl");
    OLED_ShowString(2, 1, "Key1:LED1  Key2:LED2");
    OLED_ShowString(3, 1, "Key3:LED3");
    OLED_ShowString(4, 1, "One thread controls all");
    
    // 创建并启动LED控制主线程
    thread_led_control = rt_thread_create("thread_led_control", thread_led_control_entry, RT_NULL, 512, 15, 5);
    if (thread_led_control != RT_NULL)
    {
        rt_thread_startup(thread_led_control);
    }
    else
    {
        rt_kprintf("LED control thread create error\n");
    }
    
    // 创建并启动按键处理线程
    thread_key = rt_thread_create("thread_key", thread_key_entry, RT_NULL, 512, 15, 5);
    if (thread_key != RT_NULL)
    {
        rt_thread_startup(thread_key);
    }
    else
    {
        rt_kprintf("Key thread create error\n");
    }
    
    return RT_EOK;
}
