/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "dianji.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

char RxBuffer[RXBUFFERSIZE];   
uint8_t aRxBuffer;			
uint8_t Uart1_Rx_Cnt = 0;
//int IT_flag = 0;


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

 HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);   //pe9
 HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);   //pe11
 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);   //pa0
 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);   //pa1
 
 HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
 
//Diantiao_All_Init();          //行程校准
 Diantiao1_Init();
 Diantiao2_Init();
//__HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);      //串口2使能UART_IT_RXNE
//	HAL_UART_Receive_DMA(&huart1, (uint8_t *)DATA_receive_BUFFER,20);//串口2DMA接收初始化

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
   while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
//		TIM2->CCR1=180;
//		TIM2->CCR2=180;
//		HAL_Delay(1000);
//		TIM2->CCR1=160;
//		TIM2->CCR2=160;
//		HAL_Delay(1000);
//		TIM2->CCR1=150;
//		TIM2->CCR2=150;
//		HAL_Delay(1000);
//		TIM2->CCR1=160;
//		TIM2->CCR2=160;
//		HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
//void DMA_Usart_Send(uint8_t *buf,uint8_t len)//串口发送封装
//{
// if(HAL_UART_Transmit_DMA(&huart1, buf,len)!= HAL_OK) 
//  {
//   Error_Handler();
//  }

//}

//void DMA_Usart1_Read(uint8_t *Data,uint8_t len)//串口接收封装
//{
//	HAL_UART_Receive_DMA(&huart1,Data,len);
//}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//串口发数据格式：G O#      
	//大写字母+空格+大写字母+#号
    uint16_t i=0;
		
		
		//HAL_UART_Transmit(&huart1, (uint8_t *)&RxBuffer, Uart1_Rx_Cnt,2); 
		
		RxBuffer[Uart1_Rx_Cnt++] = aRxBuffer; 
		if(RxBuffer[Uart1_Rx_Cnt-1] == 0x23) 
		{
			HAL_UART_Transmit(&huart1, (uint8_t *)&RxBuffer, Uart1_Rx_Cnt,0xFFFF); 
      while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX);
      for(i=0;i<Uart1_Rx_Cnt;i++)
			{
				if(RxBuffer[i-1]==0x20)
				{
						switch(RxBuffer[i-2])
						{
							case 'T':if(RxBuffer[i]=='R')Turn_Right();
											 if(RxBuffer[i]=='L')Turn_Left();
											 if(RxBuffer[i]=='H')Turn_High();
							         if(RxBuffer[i]=='D')Turn_Down();
												break;
							case 'G':if(RxBuffer[i]=='O')Go_On();
							         if(RxBuffer[i]=='B')Go_Back();
											 if(RxBuffer[i]=='S')Go_Stop();
												break;
							case 'Z':if(RxBuffer[i]=='C')Zhua_Catch();
											 if(RxBuffer[i]=='P')Zhua_Put();
												break;
							
						}
				}
				
				
			}
			
			Uart1_Rx_Cnt = 0;
			memset(RxBuffer,0x00,sizeof(RxBuffer));
		}
	
		
		
		
	HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);

	
	
	
}




/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
