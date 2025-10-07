#include "system.h"

/**
  * @brief  TIM6初始化函数
  * @param  arr: 自动重装载值
  * @param  psc: 预分频系数
  * @retval 无
  */
void TIM6_Init(uint16_t arr, uint16_t psc)
{
    // 1. 使能TIM6时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
    
    // 2. 配置TIM6参数
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_Period = arr;             // 自动重装载值
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;          // 预分频系数
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;  // 向上计数模式
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;      // 时钟分频因子
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);
    
    // 3. 清除更新中断标志位
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);
    
    // 4. 使能TIM6
    TIM_Cmd(TIM6, ENABLE);
}
