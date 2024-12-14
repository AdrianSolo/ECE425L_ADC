/*
 * @file main.c
 *
 * @brief Main source code for the ADC program.
 *
 * This file contains the main entry point and function definitions for the ADC program.
 *
 * It interfaces with the following:
 *  - EduBase Board Potentiometer (PE2)
 *  - EduBase Board Analog Light Sensor (PE1)
 *
 * @ Adrian Solorzano 
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "EduBase_LCD.h"
#include "ADC.h"

static double adc_buffer[8];

int main(void)
{
	
	SysTick_Delay_Init();
	
	EduBase_LCD_Init(); 
	
	ADC_Init();
	
	EduBase_LCD_Enable_Display();
	EduBase_LCD_Clear_Display();
	
	EduBase_LCD_Set_Cursor(0, 0);
	EduBase_LCD_Display_String("Potentiometer");
	
	while(1)
	{		
		ADC_Sample(adc_buffer);
		EduBase_LCD_Set_Cursor(0, 1);
		EduBase_LCD_Display_Double(adc_buffer[0]);
		SysTick_Delay1ms(1000);
	}
}
