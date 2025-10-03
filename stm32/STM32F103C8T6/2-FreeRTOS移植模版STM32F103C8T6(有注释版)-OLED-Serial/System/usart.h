#ifndef _usart_H
#define _usart_H

#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>

// 保留原有定义以保持兼容性
#define USART1_REC_LEN		200   	//串口接收缓冲区长度 200

extern u8  USART1_RX_BUF[USART1_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末尾字节为换行符
extern u16 USART1_RX_STA;           	//接收状态标记

// 新增定义
#define SERIAL_DEFAULT_BAUDRATE    9600  // 默认波特率

extern uint8_t Serial_RxData;
extern uint8_t Serial_RxFlag;

// 新增函数声明
void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);
uint8_t Serial_GetRxFlag(void);
uint8_t Serial_GetRxData(void);

// 保留原有初始化函数以保持兼容性
void USART1_Init(u32 bound);

#endif


