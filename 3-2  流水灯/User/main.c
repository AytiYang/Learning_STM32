#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int myGPIO[] = {GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2,GPIO_Pin_3,GPIO_Pin_4,GPIO_Pin_5,GPIO_Pin_6,GPIO_Pin_7};

void LED_FLASH(int num);

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	//开启时钟
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//复用推挽模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;	//选择0-16引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	while(1)
	{
		//GPIO_Write(GPIOA,~0x0002);	//0000 0000 0000 0001
		for(int i=0x0001;i<=0x00FF;i*=2)
		{
			GPIO_Write(GPIOA,~i);
			Delay_ms(500);

		}
	}
}
