/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the ATmega32 PWM driver
 *
 * Author: Nada Sayed
 *
 *******************************************************************************/
#include"pwm.h"
#include "avr/io.h" /* To use the ADC Registers */
#include"gpio.h" /* To use gpio setup_inDirection function */
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for:
 * 1. The function responsible for trigger the Timer0 with the PWM Mode.
 * 2. The generated PWM signal frequency will control the DC Motor speed.
 */
void PWM_Timer0_Start(uint8 duty_cycle){

	/* Setting the PWM pin as output pin */
	GPIO_setupPinDirection(PWM_PORD_ID,PWM_PIN_ID,PIN_OUTPUT);

	TCNT0 = 0; //Set Timer Initial value

	OCR0  = duty_cycle; // Set Compare Value

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
