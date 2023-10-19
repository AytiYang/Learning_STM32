#include "stm32f10x.h"                  // Device header

#include "Delay.h"
#include "OLED.h"
uint8_t KeyNum;
int main(void)
{
	OLED_Init();
	OLED_ShowChar(1,1,'a');
	OLED_ShowString(2,1,"hello world!");
	while(1)
	{
		
	}
}