#ifndef _led_H
#define _led_H

#define LED1 GET_PIN(A,0)
#define LED2 GET_PIN(A,1)

void LED_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED2_ON(void);
void LED2_OFF(void);

#endif
