#include "time.h"

//TIM3初始化函数
void TIM3_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);  //使能TIM3时钟
    
    TIM_TimeBaseInitStructure.TIM_Period = arr;            //自动重装载值
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;         //预分频器
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;      //时钟分割
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);   //初始化TIM3
    
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);            //允许TIM3更新中断
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;       //TIM3中断通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //抢占优先级1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;     //子优先级3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;        //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);                       //初始化NVIC
    
    TIM_Cmd(TIM3, ENABLE);                                //使能TIM3
}

//TIM4初始化函数
void TIM4_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);  //使能TIM4时钟
    
    TIM_TimeBaseInitStructure.TIM_Period = arr;            //自动重装载值
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;         //预分频器
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;      //时钟分割
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);   //初始化TIM4
    
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);            //允许TIM4更新中断
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;       //TIM4中断通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //抢占优先级1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;     //子优先级4
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;        //IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);                       //初始化NVIC
    
    TIM_Cmd(TIM4, ENABLE);                                //使能TIM4
}

//TIM3中断服务函数
void TIM3_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断是否发生
    {
        // 可以在这里添加中断处理代码
        
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);    //清除TIM3更新中断标志
    }
}

//TIM4中断服务函数
void TIM4_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  //检查TIM4更新中断是否发生
    {
        // 可以在这里添加中断处理代码
        
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);    //清除TIM4更新中断标志
    }
}
