/******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the ATmega32 DC MOTOR driver
 *
 * Author: Nada Sayed
 *
 *******************************************************************************/
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PORT_ID    PORTB_ID

#define MOTOR_PIN1_ID    PIN0_ID /*DC motor first pin in the microcontroller */
#define MOTOR_PIN2_ID    PIN1_ID /*DC motor second pin in the microcontroller */

#define MOTOR_MINIMUM_SPEED 0

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/*
 * Description :
 * Enumeration containing the DC motor rotation direction bits:
 * 1. Stop   00.
 * 2. Clockwise Direction   01.
 * 3. Anti Clockwise Direction   10.
 */
typedef enum
{
	Stop,Clockwise_Direction,Anti_Clockwise_Direction
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialing the DC motor driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * Function responsible for:
 * 1. The function responsible for rotate the DC Motor CW/ or A-CW or stop the \
 *  motor based on the state input state value.
 *  2. Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
