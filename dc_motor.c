/******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the ATmega32 DC MOTOR driver
 *
 * Author: Nada Sayed
 *
 *******************************************************************************/
#include "dc_motor.h"
#include "gpio.h" /* To use the gpio functions */
#include "pwm.h" /* To use the pwm function */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialing the DC motor driver.
 */
void DcMotor_Init(void){
	/* Setting the motor pins as output pins */
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN2_ID,PIN_OUTPUT);

	/* Stopping the motor initially */
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_LOW);
}

/*
 * Description :
 * Function responsible for:
 * 1. The function responsible for rotate the DC Motor CW/ or A-CW or stop the \
 *  motor based on the state input state value.
 *  2. Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	if(state==Stop){
		speed=MOTOR_MINIMUM_SPEED;
	}
	else if(state==Clockwise_Direction) {
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_LOW);

	}
	else if(state==Anti_Clockwise_Direction){
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_HIGH);
	}
	/*Send the required duty cycle to the PWM driver based on the required speed value.*/
	PWM_Timer0_Start((speed*MAXIMUM_TIMER0_COUNT)/100);
}
