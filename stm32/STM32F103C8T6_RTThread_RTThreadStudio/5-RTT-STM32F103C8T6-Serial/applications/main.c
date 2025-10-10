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

#define RECV_BUFFER_SIZE 20

rt_device_t uart_dev;
struct serial_configure uart_config = RT_SERIAL_CONFIG_DEFAULT;
rt_int8_t recv_buffer[RECV_BUFFER_SIZE] = {0};
rt_uint8_t index0 = 0;  // 初始化索引
static rt_sem_t uart_rx_sem = RT_NULL;  // 用于同步的信号量

// 修复后的回调函数
static rt_err_t uart_function(rt_device_t dev, rt_size_t size)
{
    // 释放信号量，通知应用线程有数据到达
    rt_sem_release(uart_rx_sem);
    return RT_EOK;
}

// 接收数据的线程函数
static void uart_recv_thread(void *parameter)
{
    rt_uint8_t buffer;
    while (1)
    {
        // 等待接收信号量
        rt_sem_take(uart_rx_sem, RT_WAITING_FOREVER);

        // 读取数据
        while (rt_device_read(uart_dev, 0, &buffer, 1) > 0)
        {
            if (index0 < RECV_BUFFER_SIZE - 1)  // 防止缓冲区溢出
            {
                recv_buffer[index0++] = buffer;
                if (buffer == '\n')
                {
                    recv_buffer[index0] = '\0';  // 添加结束符
                    rt_device_write(uart_dev, 0, recv_buffer, index0 + 1);  // 回显数据
                    index0 = 0;  // 重置索引
                }
            }
            else
            {
                // 缓冲区已满，丢弃数据并重置
                rt_kprintf("Buffer overflow!\n");
                index0 = 0;
            }
        }
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
    
    // 创建接收信号量
    uart_rx_sem = rt_sem_create("uart_rx", 0, RT_IPC_FLAG_FIFO);
    if (uart_rx_sem == RT_NULL)
    {
        OLED_ShowString(1, 1, "sem create failed");
        return -RT_ERROR;
    }

    uart_dev = rt_device_find("uart2");
    if (uart_dev == RT_NULL)
    {
        OLED_ShowString(1, 1, "uart2 null");
    }
    else
    {
        rt_int8_t result = rt_device_open(uart_dev, RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
        if (result <= 0)
        {
            OLED_ShowString(2, 1, "uart2 open failed");
        }
        else
        {
            rt_device_control(uart_dev, RT_DEVICE_CTRL_CONFIG, (void *)&uart_config);
            rt_device_set_rx_indicate(uart_dev, uart_function);

            // 创建接收线程
            rt_thread_t thread = rt_thread_create("uart_recv",
                                                  uart_recv_thread,
                                                  RT_NULL,
                                                  512,
                                                  25,
                                                  10);
            if (thread != RT_NULL)
            {
                rt_thread_startup(thread);
            }
        }
    }

    return RT_EOK;
}
