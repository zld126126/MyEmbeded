/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-10-06     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#include "led.h"
#include "OLED.h"

int main(void)
{
    int count = 1;
    
    // 初始化LED
    LED_Init();
    // 初始化OLED
    OLED_Init();

    // 在OLED上显示信息
    OLED_ShowString(1, 1, "Hello RT-Thread!");
    OLED_ShowString(2, 1, "OLED Test");

    //rt_kprintf("Hello RT-Thread!\n");

    while (count++)
    {
        //LOG_D("Hello RT-Thread!");
        rt_kprintf("Hello RT-Thread! Count: %d\n", count);

        // 显示计数值
        OLED_ShowString(3, 1, "Count: ");
        OLED_ShowNum(3, 7, count, 5);

        // 切换LED状态
        LED1_ON();
        LED2_OFF();
        rt_thread_mdelay(200);
        LED1_OFF();
        LED2_ON();
        rt_thread_mdelay(800);
    }

    return RT_EOK;
}
