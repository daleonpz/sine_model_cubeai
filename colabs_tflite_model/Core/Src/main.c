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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>


#include "ai_datatypes_defines.h"
#include "ai_platform.h"
#include "sine_ai.h"
#include "sine_ai_data.h"


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

CRC_HandleTypeDef hcrc;

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

uint32_t uwPrescalerValue = 0;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
static void MX_CRC_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
    /* USER CODE BEGIN 1 */
    char buf[255];
    int buf_len = 0;
    ai_error ai_err;
    ai_i32 nbatch;

    // Chunk of memory used to hold intermediate values for neural network
    AI_ALIGNED(4) ai_u8 activations[AI_SINE_AI_DATA_ACTIVATIONS_SIZE];

    // Buffers used to store input and output tensors
    AI_ALIGNED(4) ai_i8 in_data[AI_SINE_AI_IN_1_SIZE_BYTES];
    AI_ALIGNED(4) ai_i8 out_data[AI_SINE_AI_OUT_1_SIZE_BYTES];

    // Pointer to our model
    ai_handle sine_ai = AI_HANDLE_NULL;

    // Initialize wrapper structs that hold pointers to data and info about the
    // data (tensor height, width, channels)
    ai_buffer ai_input[AI_SINE_AI_IN_NUM] = AI_SINE_AI_IN;
    ai_buffer ai_output[AI_SINE_AI_OUT_NUM] = AI_SINE_AI_OUT;

    // Set working memory and get weights/biases from model
    ai_network_params ai_params = AI_NETWORK_PARAMS_INIT(
            AI_SINE_AI_DATA_WEIGHTS(ai_sine_ai_data_weights_get()), 
            AI_SINE_AI_DATA_ACTIVATIONS(activations)
            );
    //     ai_network_params ai_params = {
    //         AI_SINE_AI_DATA_WEIGHTS(ai_sine_ai_data_weights_get()),
    //         AI_SINE_AI_DATA_ACTIVATIONS(activations)
    //     };

    // Set pointers wrapper structs to our data buffers
    ai_input[0].n_batches = 1;
    ai_input[0].data = AI_HANDLE_PTR(in_data);
    ai_output[0].n_batches = 1;
    ai_output[0].data = AI_HANDLE_PTR(out_data);
    /* USER CODE END 1 */

    /* Enable I-Cache---------------------------------------------------------*/
    SCB_EnableICache();

    /* Enable D-Cache---------------------------------------------------------*/
    SCB_EnableDCache();

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
    MX_TIM3_Init();
    MX_CRC_Init();
    MX_USART1_UART_Init();
    /* USER CODE BEGIN 2 */

    // Start timer/counter
    HAL_TIM_Base_Start(&htim3);

    // Greetings!
    buf_len = sprintf(buf, "\r\n\r\nSTM32 X-Cube-AI test\r\n");
    HAL_UART_Transmit(&huart1, (uint8_t *)buf, buf_len, 100);

    // Create instance of neural network
    ai_err = ai_sine_ai_create(&sine_ai, AI_SINE_AI_DATA_CONFIG);
    if (ai_err.type != AI_ERROR_NONE)
    {
        buf_len = sprintf(buf, "Error: could not create NN instance\r\n");
        HAL_UART_Transmit(&huart1, (uint8_t *)buf, buf_len, 100);
        while(1);
    }

    // Initialize neural network
    if (!ai_sine_ai_init(sine_ai, &ai_params))
    {
        buf_len = sprintf(buf, "Error: could not initialize NN\r\n");
        HAL_UART_Transmit(&huart1, (uint8_t *)buf, buf_len, 100);
        while(1);
    }
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        // Fill input buffer (use test value)
        for (uint32_t i = 0; i < AI_SINE_AI_IN_1_SIZE; i++)
        {
            ((ai_float *)in_data)[i] = (ai_float)2.0f;
        }

        // Get current timestamp
        uint32_t timestamp;
        uint32_t timedone = 0 ;
        timestamp = htim3.Instance->CNT;

        // Perform inference
        nbatch = ai_sine_ai_run(sine_ai, &ai_input[0], &ai_output[0]);
        if (nbatch != 1) {
            buf_len = sprintf(buf, "Error: could not run inference\r\n");
            HAL_UART_Transmit(&huart1, (uint8_t *)buf, buf_len, 100);
        }

        // Read output (predicted y) of neural network
        float y_val;
        y_val = ((float *)out_data)[0];

        timedone = htim3.Instance->CNT;
        if (timedone < timestamp) timedone += 60000; // due to timer setup

        // Print output of neural network along with inference time (microseconds)
        buf_len = sprintf(buf,
                "Output: %f | Duration: %lu  ns\r\n",
                y_val,
                (unsigned long)(timedone - timestamp)); // due to timer setup 
        HAL_UART_Transmit(&huart1, (uint8_t *)buf, buf_len, 10);

        // Wait before doing it again
//         timestamp = htim3.Instance->CNT;
        HAL_Delay(50);
//         timedone = htim3.Instance->CNT;
//         if (timedone < timestamp) timedone += 60000;
//         buf_len = sprintf(buf,
//                 " >>> delay duration: %lu  \r\n",
//                 (unsigned long)(timedone  - timestamp));
//         HAL_UART_Transmit(&huart1, (uint8_t *)buf, buf_len, 100);

        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
    }
    /* USER CODE END 3 */

}

/**
 * @brief System Clock Configuration
 * @retval None
 */

// void SystemClock_Config(void)
// {
//     RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//     RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//     HAL_StatusTypeDef ret = HAL_OK;
// 
//     /* Enable HSE Oscillator and activate PLL with HSE as source */
//     RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
//     RCC_OscInitStruct.HSEState = RCC_HSE_ON;
//     RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//     RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//     RCC_OscInitStruct.PLL.PLLM = 25;
//     RCC_OscInitStruct.PLL.PLLN = 432;  
//     RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
//     RCC_OscInitStruct.PLL.PLLQ = 9;
// 
//     ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
//     if(ret != HAL_OK)
//     {
//         while(1) { ; }
//     }
// 
//     /* Activate the OverDrive to reach the 216 MHz Frequency */  
//     ret = HAL_PWREx_EnableOverDrive();
//     if(ret != HAL_OK)
//     {
//         while(1) { ; }
//     }
// 
//     /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
//     RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
//     RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//     RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//     RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
//     RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2; 
// 
//     ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7);
//     if(ret != HAL_OK)
//     {
//         while(1) { ; }
//     }  
// }
void SystemClock_Config(void) //16Mhz
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
     */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
        |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClkInitStruct.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
 * @brief CRC Initialization Function
 * @param None
 * @retval None
 */
static void MX_CRC_Init(void)
{

    /* USER CODE BEGIN CRC_Init 0 */

    /* USER CODE END CRC_Init 0 */

    /* USER CODE BEGIN CRC_Init 1 */

    /* USER CODE END CRC_Init 1 */
    hcrc.Instance = CRC;
    hcrc.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_ENABLE;
    hcrc.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_ENABLE;
    hcrc.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
    hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
    hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;
    if (HAL_CRC_Init(&hcrc) != HAL_OK)
    {
        Error_Handler();
    }
    /* USER CODE BEGIN CRC_Init 2 */

    /* USER CODE END CRC_Init 2 */

}

/**
 * @brief TIM3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM3_Init(void)
{

    /* USER CODE BEGIN TIM3_Init 0 */

    /* USER CODE END TIM3_Init 0 */

    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    /* USER CODE BEGIN TIM3_Init 1 */
//     uint32_t tim_clock_freq = 10000; //Hz
    uint32_t tim_clock_freq =    1000000; //hz (1Mhz)
    uwPrescalerValue = (uint32_t)(SystemCoreClock / tim_clock_freq) - 1;

    /* USER CODE END TIM3_Init 1 */
    htim3.Instance = TIM3;
    htim3.Init.Prescaler = uwPrescalerValue; 
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    // max value 2**16
    htim3.Init.Period = 60000;  // 1sek/tim_clock_freq * time_units   for 10Khz -> 1 Sec = 10000 Units (max count to count)
                                // for 1 Mhz 60000 units =  60,000 ms 
        htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
    {
        Error_Handler();
    }
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
    {
        Error_Handler();
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }
    /* USER CODE BEGIN TIM3_Init 2 */

    /* USER CODE END TIM3_Init 2 */

}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void)
{

    /* USER CODE BEGIN USART1_Init 0 */

    /* USER CODE END USART1_Init 0 */

    /* USER CODE BEGIN USART1_Init 1 */

    /* USER CODE END USART1_Init 1 */
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }
    /* USER CODE BEGIN USART1_Init 2 */

    /* USER CODE END USART1_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

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
