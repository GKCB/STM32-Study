#include "led.h"


void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//1, enable system clock stm32f4xx_rcc.h
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	//2, init IO func GPIO_Init //stm32f4xx_gpio.h 
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_9|GPIO_Pin_10; //F9 F10
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT; //LED output
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_UP; //UP means don't light this
	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF,&GPIO_InitStruct);
	
	//3, set bits value
	GPIO_SetBits(GPIOF, GPIO_Pin_9|GPIO_Pin_10);

	
}
