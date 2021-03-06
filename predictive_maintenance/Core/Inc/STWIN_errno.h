/**
  ******************************************************************************
  * @file    STWIN_errno.h 
  * @author  System Research & Applications Team - Catania Lab.
  * @version V2.4.0
  * @date    07-June-2021
  * @brief   Error Code
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0055, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0055
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STWIN_ERRNO_H
#define __STWIN_ERRNO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Common Error codes */
#define BSP_ERROR_NONE                    0
#define BSP_ERROR_NO_INIT                -1
#define BSP_ERROR_WRONG_PARAM            -2
#define BSP_ERROR_BUSY                   -3
#define BSP_ERROR_PERIPH_FAILURE         -4
#define BSP_ERROR_COMPONENT_FAILURE      -5
#define BSP_ERROR_UNKNOWN_FAILURE        -6
#define BSP_ERROR_UNKNOWN_COMPONENT      -7 
#define BSP_ERROR_BUS_FAILURE            -8
#define BSP_ERROR_CLOCK_FAILURE          -9
#define BSP_ERROR_MSP_FAILURE            -10
#define BSP_NOT_IMPLEMENTED              -11
#define BSP_ERROR_MALLOC_FAILURE         -12

#ifdef __cplusplus
}
#endif

#endif /* __STWIN_ERRNO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
