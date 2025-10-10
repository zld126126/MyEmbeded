/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-xx-xx                  first version
 * 2023-xx-xx                  modified to use RT-Thread pin device API
 */

#include <rtthread.h>
#include "stm32f10x.h"
#include "Key.h"

/* 按键引脚定义 */
#define KEY0_PIN    GPIO_Pin_1
#define KEY1_PIN    GPIO_Pin_11
#define KEY_PORT    GPIOB
#define KEY_RCC     RCC_APB2Periph_GPIOB

/**
 * @brief  按键初始化函数
 * @param  无
 * @retval 无
 */
void Key_Init(void)
{
    /*开启时钟*/
    RCC_APB2PeriphClockCmd(KEY_RCC, ENABLE);
    
    /*GPIO初始化*/
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = KEY0_PIN | KEY1_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY_PORT, &GPIO_InitStructure);
    
    rt_kprintf("Key init done!\n");
}

/**
 * @brief  获取按键状态
 * @param  无
 * @retval 按键编号，范围：0~2，返回0代表没有按键按下
 * @note   非阻塞式操作，检测到按键按下并消抖后立即返回
 */
rt_uint8_t Key_GetNum(void)
{
    rt_uint8_t key_num = 0;    
    
    if (GPIO_ReadInputDataBit(KEY_PORT, KEY0_PIN) == 0)  
    {
        rt_thread_mdelay(20);   /* 延时消抖 */
        if (GPIO_ReadInputDataBit(KEY_PORT, KEY0_PIN) == 0)
        {
            key_num = 1;
        }
    }
    
    if (GPIO_ReadInputDataBit(KEY_PORT, KEY1_PIN) == 0)  
    {
        rt_thread_mdelay(20);   /* 延时消抖 */
        if (GPIO_ReadInputDataBit(KEY_PORT, KEY1_PIN) == 0)
        {
            key_num = 2;
        }
    }
    
    return key_num;    
}
