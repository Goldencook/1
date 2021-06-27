#include "main.h"
	float motor_cnt[5]={0};

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_12)
	motor_cnt[1]++;
	if(motor_cnt[1]==300)       //CCR值给4000，一圈500左右，赋值467就转到500
	{
			TIM1->CCR1=0;
			motor_cnt[1]=0;
	}
//	if(GPIO_Pin == GPIO_PIN_11)
//	motor_cnt[2]++;
//	
//	if(GPIO_Pin == GPIO_PIN_12)
//	motor_cnt[3]++;
//		
//	if(GPIO_Pin == GPIO_PIN_13)
//	motor_cnt[4]++;

}