/******************************************************************************
 *
 * Name: Fan_Control.c
 *
 * Description: Design a temperature-controlled fan using ATmega32 microcontroller
 *
 * Author: Nada Sayed
 *
 * Date: 10/8/2022
 *******************************************************************************/

#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"
#include "lm35_sensor.h"
#include "adc.h"
#include "lcd.h"
#include "std_types.h"
#include"common_macros.h"

int main(void){

	uint8 current_temperature;

	/*Setting the configurations structure of the ADC driver
	 * 1. Working with internal reference voltage = 2.56v
	 * 2. Working with ADC frequency = FCPU/8
	 */
	ADC_ConfigType Adc_Config = {Internal_Reference_Voltage,F_CPU_8};

	DcMotor_State state= Stop ; /*Initialize the motor state initially to stop*/
	ADC_init(&Adc_Config); /*Passing the configuration structure to the initialing function of ADC */
	LCD_init(); /*Initialing the LCD */
	DcMotor_Init(); /*Initialing the DC motor*/

	while(1){

		LCD_displayStringRowColumn(0,3,"Fan is ");

		/*Getting the reading of the temperature from the sensor */
		current_temperature=LM35_getTemperature();

		if(current_temperature<30){
			state=Stop; /*Stopping the motor if temperature is less than 30 degrees */
			LCD_displayString("OFF");
			/*Passing the motor state and the speed to the motor to adjust its settings*/
			DcMotor_Rotate(state,0);
		}
		else if(current_temperature>=30 && current_temperature<60){
			/*Moving the motor clockwise if temperature is greater than 30 degrees */
			state=Clockwise_Direction;
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			/*Passing the motor state and the speed to the motor to adjust its settings*/
			DcMotor_Rotate(state,25);
		}
		else if(current_temperature>=60 && current_temperature<90){
			/*Moving the motor clockwise if temperature is greater than 30 degrees */
			state=Clockwise_Direction;
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			/*Passing the motor state and the speed to the motor to adjust its settings*/
			DcMotor_Rotate(state,50);
		}
		else if(current_temperature>=90 && current_temperature<120){
			/*Moving the motor clockwise if temperature is greater than 30 degrees */
			state=Clockwise_Direction;
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			/*Passing the motor state and the speed to the motor to adjust its settings*/
			DcMotor_Rotate(state,75);
		}
		else if(current_temperature>=120){
			/*Moving the motor clockwise if temperature is greater than 30 degrees */
			state=Clockwise_Direction;
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			/*Passing the motor state and the speed to the motor to adjust its settings*/
			DcMotor_Rotate(state,100);
		}
		LCD_moveCursor(1,3); /*Moving the cursor to write in the second line */
		LCD_displayString("Temp =    C");
		LCD_moveCursor(1,10); /*Moving the cursor to write the temperature every time in the same place */
		LCD_intgerToString(current_temperature); /*Displaying the temperature */
	}
}


