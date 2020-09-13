#ifndef __KEY_H
#define __KEY_H
#include "sys.h"

//lib function
/*
#define KEY0  GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4);
#define KEY1  GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3);
#define KEY2  GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2);
#define WK_UP GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
*/

//bit band

#define KEY0  PEin(4) //PE4
#define KEY1  PEin(3) //PE3
#define KEY2  PEin(2) //PE2
#define WK_UP PAin(0) //PA0

#define KEY0_PRES 1
#define KEY1_PRES 2
#define KEY2_PRES 3
#define WKUP_PRES 4

void KEY_Init(void); //Init KEY IO
u8 KEY_Scan(u8);     //Scan these KEYS

#endif

