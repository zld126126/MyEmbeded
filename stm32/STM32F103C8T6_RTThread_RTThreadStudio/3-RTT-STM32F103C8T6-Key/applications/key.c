#include <rtdevice.h>
#include <board.h>
#include "key.h"

void Key_Init(void)
{
    rt_pin_mode(KEY1, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY2, PIN_MODE_INPUT_PULLUP);
}

uint8_t Key_Entry(void)
{
    if (rt_pin_read(KEY1) == 0) {
        return 1;
    }else if(rt_pin_read(KEY2) == 0){
        return 2;
    }else{
        return 3;
    }
}
