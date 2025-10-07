#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "key.h"
#include "semphr.h"
#include "OLED.h"


//任务优先级
#define START_TASK_PRIO		1
//任务堆栈大小	
#define START_STK_SIZE 		128  
//任务句柄
TaskHandle_t StartTask_Handler;
//任务函数
void start_task(void *pvParameters);

//任务优先级
#define LED1_TASK_PRIO		2
//任务堆栈大小	
#define LED1_STK_SIZE 		50  
//任务句柄
TaskHandle_t LED1Task_Handler;
//任务函数
void led1_task(void *pvParameters);

//任务优先级
#define LowPriority_TASK_PRIO		3
//任务堆栈大小	
#define LowPriority_STK_SIZE 		512  
//任务句柄
TaskHandle_t LowPriority_Task_Handle;
//任务函数
void LowPriority_Task(void *pvParameters);

//任务优先级
#define MidPriority_TASK_PRIO		4
//任务堆栈大小	
#define MidPriority_STK_SIZE 		512  
//任务句柄
TaskHandle_t MidPriority_Task_Handle;
//任务函数
void MidPriority_Task(void *pvParameters);

//任务优先级
#define HighPriority_TASK_PRIO		5
//任务堆栈大小	
#define HighPriority_STK_SIZE 		512  
//任务句柄
TaskHandle_t HighPriority_Task_Handle;
//任务函数
void HighPriority_Task(void *pvParameters);


SemaphoreHandle_t MuxSem_Handle =NULL;


/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
int main()
{
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4
	LED_Init();
	KEY_Init();
	OLED_Init();
	USART1_Init(115200);
	//printf("FreeRTOS互斥量实验\r\n");
	//创建开始任务
    xTaskCreate((TaskFunction_t )start_task,            //任务函数
                (const char*    )"start_task",          //任务名称
                (uint16_t       )START_STK_SIZE,        //任务堆栈大小
                (void*          )NULL,                  //传递给任务函数的参数
                (UBaseType_t    )START_TASK_PRIO,       //任务优先级
                (TaskHandle_t*  )&StartTask_Handler);   //任务句柄              
    vTaskStartScheduler();          //开启任务调度
}

//开始任务任务函数
void start_task(void *pvParameters)
{
	taskENTER_CRITICAL();           //进入临界区
     
	/* 创建MuxSem */
	MuxSem_Handle = xSemaphoreCreateMutex();	
	
    //创建LED1任务
    xTaskCreate((TaskFunction_t )led1_task,     
                (const char*    )"led1_task",   
                (uint16_t       )LED1_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )LED1_TASK_PRIO,
                (TaskHandle_t*  )&LED1Task_Handler); 
				
	//创建低优先级任务
    xTaskCreate((TaskFunction_t )LowPriority_Task,     
                (const char*    )"LowPriority_Task",   
                (uint16_t       )LowPriority_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )LowPriority_TASK_PRIO,
                (TaskHandle_t*  )&LowPriority_Task_Handle);

	//创建中优先级任务
    xTaskCreate((TaskFunction_t )MidPriority_Task,     
                (const char*    )"MidPriority_Task",   
                (uint16_t       )MidPriority_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )MidPriority_TASK_PRIO,
                (TaskHandle_t*  )&MidPriority_Task_Handle);
				
	//创建高优先级任务
    xTaskCreate((TaskFunction_t )HighPriority_Task,     
                (const char*    )"HighPriority_Task",   
                (uint16_t       )HighPriority_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )HighPriority_TASK_PRIO,
                (TaskHandle_t*  )&HighPriority_Task_Handle);
				
    vTaskDelete(StartTask_Handler); //删除开始任务
    taskEXIT_CRITICAL();            //退出临界区
} 

//LED1任务函数
void led1_task(void *pvParameters)
{
    while(1)
    {
        LED3=0;
        vTaskDelay(200);
        LED3=1;
        vTaskDelay(800);
    }
}

//低优先级任务函数
void LowPriority_Task(void *pvParameters)
{
    //BaseType_t xReturn = pdPASS;/* 定义一个创建信息返回值，默认为pdPASS */
	static uint32_t i=0;
	
	while(1)
    {
    //printf("LowPriority_Task 获取互斥量\n");
		//获取互斥量 MuxSem,没获取到则一直等待
		BaseType_t xReturn = xSemaphoreTake(MuxSem_Handle,/* 互斥量句柄 */
                              portMAX_DELAY); /* 等待时间 */
		//if( xReturn == pdTRUE ) printf("LowPriority_Task Running\n\n");

		for(i=0;i<2000000;i++)//模拟低优先级任务占用互斥量
		{
			taskYIELD();//发起任务调度
		}

		//printf("LowPriority_Task 释放互斥量!\r\n");
		xReturn = xSemaphoreGive( MuxSem_Handle );//给出互斥量
		LED4=!LED4;
		vTaskDelay(500);
    }
}

//中优先级任务函数
void MidPriority_Task(void *pvParameters)
{
	static u8 flag = 0;
	while(1)
    {
			//printf("MidPriority_Task Running\n");
			flag = !flag;
			if (flag){
				OLED_ShowString(1, 1, "       ");
				OLED_ShowString(1, 1, "middle");
			}else{
				OLED_ShowString(1, 1, "middle.");
			}	
			vTaskDelay(500);
    }
}

//高优先级任务函数
void HighPriority_Task(void *pvParameters)
{
	//BaseType_t xReturn = pdTRUE;
	
	while(1)
    {
		//printf("HighPriority_Task 获取互斥量\n");
		//获取互斥量 MuxSem,没获取到则一直等待
		BaseType_t xReturn = xSemaphoreTake(MuxSem_Handle,/* 互斥量句柄 */
                              portMAX_DELAY); /* 等待时间 */
		//if(pdTRUE == xReturn) printf("HighPriority_Task Running\n");
		LED4=!LED4;
		xReturn = xSemaphoreGive( MuxSem_Handle );//给出互斥量
		vTaskDelay(500);
    }
}
