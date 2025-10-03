#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "key.h"
#include "limits.h"
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
#define LED2_TASK_PRIO		3
//任务堆栈大小	
#define LED2_STK_SIZE 		50  
//任务句柄
TaskHandle_t LED2Task_Handler;
//任务函数
void led2_task(void *pvParameters);

//任务优先级
#define KEY_TASK_PRIO		4
//任务堆栈大小	
#define KEY_STK_SIZE 		512  
//任务句柄
TaskHandle_t KEYTask_Handler;
//任务函数
void key_task(void *pvParameters);


#define KEY1_EVENT  (0x01 << 0)//设置事件掩码的位0
#define KEY2_EVENT  (0x01 << 1)//设置事件掩码的位1



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
	//printf("FreeRTOS任务通知代替事件组实验\r\n");
	//printf("按下KEY1|KEY2发送任务事件通知！\n");
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
							 
    //创建LED1任务
    xTaskCreate((TaskFunction_t )led1_task,     
                (const char*    )"led1_task",   
                (uint16_t       )LED1_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )LED1_TASK_PRIO,
                (TaskHandle_t*  )&LED1Task_Handler); 
	
	//创建LED2任务
    xTaskCreate((TaskFunction_t )led2_task,     
                (const char*    )"led2_task",   
                (uint16_t       )LED2_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )LED2_TASK_PRIO,
                (TaskHandle_t*  )&LED2Task_Handler);
				
	//创建KEY任务
    xTaskCreate((TaskFunction_t )key_task,     
                (const char*    )"key_task",   
                (uint16_t       )KEY_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )KEY_TASK_PRIO,
                (TaskHandle_t*  )&KEYTask_Handler);
	
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

//LED2任务函数
void led2_task(void *pvParameters)
{
    BaseType_t xReturn = pdTRUE;
	uint32_t r_event = 0;  /* 定义一个事件接收变量 */
	uint32_t last_event = 0;/* 定义一个保存事件的变量 */
	
	while(1)
    {
        //获取任务通知 ,没获取到则一直等待
		xReturn = xTaskNotifyWait(0x0,			//进入函数的时候不清除任务bit
								ULONG_MAX,	  //退出函数的时候清除所有的bitR
								&r_event,		  //保存任务通知值                    
								portMAX_DELAY);	//阻塞时间
                        
		if( pdTRUE == xReturn )
		{
			last_event |= r_event;
			if(last_event == (KEY1_EVENT|KEY2_EVENT))
			{
				last_event=0;
				//printf ( "KEY1与KEY2都按下\n");
				OLED_ShowString(1, 1, "k1 k2");
				LED4=!LED4;
			}
			else
				last_event = r_event;
		}
    }
}

//KEY任务函数
void key_task(void *pvParameters)
{
    u8 key=0;
	
	while(1)
    {
        key=KEY_Scan(0);
		if(key==KEY_1_PRESS)
		{
			//printf ( "KEY1被按下\n" );
			OLED_ShowString(2, 1, "k1");
			/* 触发一个事件1 */
			xTaskNotify((TaskHandle_t	)LED2Task_Handler,//接收任务通知的任务句柄
						(uint32_t		)KEY1_EVENT,//要触发的事件
						(eNotifyAction)eSetBits);//设置任务通知值中的位
		}
		else if(key==KEY_2_PRESS)
		{
			//printf ( "KEY2被按下\n" );	
			OLED_ShowString(2, 1, "k2");
			/* 触发一个事件2 */
			xTaskNotify((TaskHandle_t	)LED2Task_Handler,//接收任务通知的任务句柄
						(uint32_t		)KEY2_EVENT,//要触发的事件
						(eNotifyAction)eSetBits);//设置任务通知值中的位
		}
		vTaskDelay(20);
    }
}
