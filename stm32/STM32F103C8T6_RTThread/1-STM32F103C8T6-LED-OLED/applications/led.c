#include <rtdevice.h>
#include <board.h>
#include "led.h"

void LED_Init(void)
{
    rt_pin_mode(LED1, PIN_MODE_OUTPUT);
    rt_pin_mode(LED2, PIN_MODE_OUTPUT);
}

void LED1_ON(void)
{
    rt_pin_write(LED1, PIN_HIGH);
}

void LED1_OFF(void)
{
    rt_pin_write(LED1, PIN_LOW);
}

void LED2_ON(void)
{
    rt_pin_write(LED2, PIN_HIGH);
}

void LED2_OFF(void)
{
    rt_pin_write(LED2, PIN_LOW);
}
