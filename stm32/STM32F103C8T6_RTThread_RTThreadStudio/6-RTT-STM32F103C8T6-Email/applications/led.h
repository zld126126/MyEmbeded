#ifndef _led_H
#define _led_H

#include <rtdevice.h>
#include <drv_common.h>

#define LED1 GET_PIN(A,0)
#define LED2 GET_PIN(A,1)
#define LED3 GET_PIN(A,2)

void LED_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED2_ON(void);
void LED2_OFF(void);
void LED3_ON(void);
void LED3_OFF(void);

#endif
