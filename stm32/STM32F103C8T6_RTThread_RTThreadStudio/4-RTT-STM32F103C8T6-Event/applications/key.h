#ifndef _key_H
#define _key_H

#define KEY1 GET_PIN(B,1)
#define KEY2 GET_PIN(B,11)

void Key_Init(void);
uint8_t Key_Entry(void);

#endif
