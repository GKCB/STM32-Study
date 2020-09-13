#include "led.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE); //peripheral clock
	
	//Init LED GPIOF
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//output mode
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//pull up
  GPIO_Init(GPIOF, &GPIO_InitStructure);//init GPIOF
	
	GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10);//GPIOF9,F10 set hight led off
	
}


