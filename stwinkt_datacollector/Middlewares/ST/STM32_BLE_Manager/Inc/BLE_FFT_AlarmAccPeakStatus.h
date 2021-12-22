/**
  ******************************************************************************
  * @file    BLE_FFT_AlarmAccPeakStatus.h
  * @author  System Research & Applications Team - Agrate/Catania Lab.
  * @version V0.3.0
  * @date    18-Jan-2021
  * @brief   FFT Alarm Acc Peak Status info services APIs.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0094, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0094
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/  
#ifndef _BLE_FFT_ALARM_ACC_PEAK_STATUS_H_
#define _BLE_FFT_ALARM_ACC_PEAK_STATUS_H_

#ifdef __cplusplus
 extern "C" {
#endif 

/* Exported Types ----------------------------------------------------------- */
/**
* @brief  X-Y-Z Generic Value in float
*/
typedef struct
{
  float x;         //!< Generic X Value in float
  float y;         //!< Generic Y Value in float
  float z;         //!< Generic Z Value in float
} BLE_MANAGER_FFTAlarmAccPeakStatusGenericValue_t;

/**
 * @brief  Warning Alarm Datatype
 */
typedef enum
{
  BLE_GOOD_ACC_PEAK          = (uint8_t)0x00,  //!< GOOD STATUS
  BLE_WARNING_ACC_PEAK       = (uint8_t)0x01,  //!< WARNING STATUS
  BLE_ALARM_ACC_PEAK         = (uint8_t)0x02,  //!< ALARM STATUS
  BLE_NONE_ACC_PEAK          = (uint8_t)0x03,  //!< RFU STATUS
} BLE_Manager_FFTAlarmAccPeakStatusAlarmType_t;

/**
 * @brief  STATUS for FFT Acc Peak Warning-Alarm
 */
typedef struct 
{
  BLE_Manager_FFTAlarmAccPeakStatusAlarmType_t STATUS_AXIS_X;   //!< X STATUS ALARM
  BLE_Manager_FFTAlarmAccPeakStatusAlarmType_t STATUS_AXIS_Y;   //!< Y STATUS ALARM
  BLE_Manager_FFTAlarmAccPeakStatusAlarmType_t STATUS_AXIS_Z;   //!< Z STATUS ALARM
} sBLE_Manager_FFTAlarmAccPeakStatusAlarm_t;

/* Exported Variables ------------------------------------------------------- */
extern BLE_NotifyEnv_t BLE_FFTAlarmAccPeakStatus_NotifyEvent;

/**
 * @brief  Init FFT Alarm Acc Peak Status info service
 * @param  None
 * @retval BleCharTypeDef* BleCharPointer: Data structure pointer for FFT Alarm Acc Peak Status info service
 */
BleCharTypeDef* BLE_InitFFTAlarmAccPeakStatusService(void);

#ifndef BLE_MANAGER_SDKV2
/**
 * @brief  Setting FFT Alarm Acc Peak Status Advertize Data
 * @param  uint8_t *manuf_data: Advertize Data
 * @retval None
 */
void BLE_SetFFTAlarmAccPeakStatusAdvertizeData(uint8_t *manuf_data);
#endif /* BLE_MANAGER_SDKV2 */

/*
 * @brief  Update FFT Alarm Acc Peak status value
 * @param  sBLE_Manager_FFTAlarmAccPeakStatusAlarm_t            Alarm
 * @param  BLE_MANAGER_FFTAlarmAccPeakStatusGenericValue_t      AccPeak
 * @retval tBleStatus   Status
 */
tBleStatus BLE_FFTAlarmAccPeakStatusUpdate(sBLE_Manager_FFTAlarmAccPeakStatusAlarm_t Alarm, BLE_MANAGER_FFTAlarmAccPeakStatusGenericValue_t AccPeak);

#ifdef __cplusplus
}
#endif

#endif /* _BLE_FFT_ALARM_ACC_PEAK_STATUS_H_ */

/******************* (C) COPYRIGHT STMicroelectronics *****END OF FILE****/