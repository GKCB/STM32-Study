#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"

int main(void)
{
	u8 key;
	delay_init(168); //168MHz
	LED_Init();
	BEEP_Init();
	KEY_Init();
	LED0 = 0;
	while(1)
	{
	}
		
}



