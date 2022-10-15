/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Nada Sayed
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define Reference_Voltage_INTERNAL 2.56
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/*
 * Description :
 * Enumeration containing the ADC reference voltage bits:
 * 1. AREF   00.
 * 2. AVCC   01.
 * 3. Reserved   10.
 * 4. Internal reference voltage 11.
 */
typedef enum
{
	AREF,AVCC,Reserved,Internal_Reference_Voltage
}ADC_ReferenceVolatge;

/*
 * Description :
 * Enumeration containing the ADC frequency bits:
 * 1. FCPU/2   000.
 * 2. FCPU/2   001.
 * 3. FCPU/4   010.
 * 4. FCPU/8   011.
 * 5. FCPU/16  100.
 * 6. FCPU/32  101.
 * 7. FCPU/64  110.
 * 8. FCPU/128 111.
 */
typedef enum
{
	F_CPU_2,F_CPU_2_AGAIN,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

/*
 * Description :
 * Structure containing the ADC configurations:
 * 1.Reference voltage.
 * 2. Prescalar.
 */
typedef struct{
	ADC_ReferenceVolatge ref_volt; /*enum type containing the reference voltage bits */
	ADC_Prescaler prescaler; /*enum type containing the prescalar bits */
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the ADC driver by passing a pointer to structure containing \
 * the configurations .
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for reading analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
