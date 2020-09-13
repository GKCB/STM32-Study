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
		key = KEY_Scan(0); //get value
		if(key)
		{
			switch(key)
			{
				case WKUP_PRES: //control BEEP
					BEEP = !BEEP; //reverse value				
					break;
				case KEY0_PRES: //
					LED0 = !LED0;
					break;
				case KEY1_PRES: //
					LED1 = !LED1;
					break;
				case KEY2_PRES: //
					LED0 = !LED0;
				  LED1 = !LED1;
					break;
			}
		}
		else
		{
			delay_ms(10);
		}
	}
		
}



