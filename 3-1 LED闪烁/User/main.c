#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	//开启时钟
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//复用推挽模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	//选择0号引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	while(1)
	{
		
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);	//设置为低电平,点亮LED
		Delay_ms(500);
		GPIO_SetBits(GPIOA,GPIO_Pin_0);		//熄灭LED
		Delay_ms(500);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);	//点亮LED
		Delay_ms(500);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);	//熄灭LED
		Delay_ms(500);
	}
		
}