#include "main.h"
#include "dianji.h"

void Diantiao_All_Init()
{
	  TIM2->CCR1=110;
	  TIM2->CCR2=110; 
		HAL_Delay(1000);
		TIM2->CCR1=210;
		TIM2->CCR2=210;
		HAL_Delay(1000);
	
}

void Diantiao1_Init()
{
		TIM2->CCR1=160;
		HAL_Delay(1000);
}

void Diantiao2_Init()
{
		TIM2->CCR2=160;
		HAL_Delay(1000);
}

void Turn_Right()
{
		TIM2->CCR2=(TIM2->CCR1)-10;
}

void Turn_Left()
{
		TIM2->CCR1=(TIM2->CCR2)-10;
}

void Turn_High()
{
		TIM2->CCR1+=10;
		TIM2->CCR2=(TIM2->CCR1);
}

void Turn_Down()
{
		TIM2->CCR1-=10;
		TIM2->CCR2=(TIM2->CCR1);
}

void Go_On()
{
		TIM2->CCR1=180;
		TIM2->CCR2=180;
}

void Go_Back()
{
		TIM2->CCR1=130;
		TIM2->CCR2=130;
}

void Zhua_Catch()
{
		TIM1->CCR1=4000;
		motor_qian;
}

void Zhua_Put()
{
		TIM1->CCR1=4000;
		motor_hou;
}

void Go_Stop()
{
		TIM2->CCR1=160;
		TIM2->CCR2=160;
}


