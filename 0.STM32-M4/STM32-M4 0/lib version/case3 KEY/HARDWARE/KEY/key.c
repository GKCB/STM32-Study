#include "key.h"
#include "delay.h"

//init key
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE, ENABLE);
	//Key need GPIOA and GPIOF clock.
	
	//key0/key1/key2 
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN; //input model
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //100M
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP; //Pull up
	GPIO_Init(GPIOE, &GPIO_InitStructure); //init GPIOE2,3,4
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//WKUP pin GPIOA0
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;// Pull DOWN 
	GPIO_Init(GPIOA, &GPIO_InitStructure); //init GPIOA0 WKUP KEY	

}

u8 KEY_Scan(u8 mode)
{
	static u8 key_up = 1; // The key released
	if(mode) key_up = 1;
	if(key_up && (KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
	{
		delay_ms(10); //10ms shaking off
		key_up = 0;
		if(KEY0 == 0) return 1;
		else if(KEY1 == 0) return 2;
		else if(KEY2 == 0) return 3;
		else if(WK_UP == 1) return 4;
	}
	else if(KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WK_UP == 0)
	{
		key_up = 1;
	}
	return 0; //none key chosed
}



