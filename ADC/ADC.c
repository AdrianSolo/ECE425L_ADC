/**
 * @file ADC.c
 *
 * @brief Source code for the ADC driver.
 *
 * This file contains the function definitions for the ADC driver.
 *
 * ADC Module 0 is used to sample the potentiometer and the analog
 * light sensor that are connected on the EduBase board. ADC Module 0
 * is configured to sample the potentiometer first and the light sensor after.
 *
 * After the light sensor is sampled, an interrupt signal is set to 
 * indicate that the sampling sequence has ended. After the conversion
 * results have been read from the corresponding FIFO, the interrupt is cleared.
 *
 * The following pins are used:
 *  - Potentiometer   <-->  Tiva LaunchPad Pin PE2 (Channel 1)
 *  - Light Sensor    <-->  Tiva LaunchPad Pin PE1 (Channel 2)
 *
 * @ Adrian Solorzano 
 *
 */

#include "ADC.h"

void ADC_Init(void)
{
		SYSCTL->RCGCADC |= 0x01;
		SysTick_Delay1ms(1);
		SYSCTL->RCGCGPIO |= 0x10;
		GPIOE->DIR &= ~0x04;
	  GPIOE->DEN &= ~0x04;
	  GPIOE->AMSEL |= 0x04;
	  GPIOE->AFSEL |= 0x04;
		ADC0->ACTSS &= ~0x1;
	  ADC0->EMUX &= ~0x000F;
		ADC0->SSMUX0 &= ~0xFFFFFFFF;
	  ADC0->SSMUX0 |= 0x00000001;
		ADC0->SSCTL0 |= 0x00000002;
  	ADC0->SSCTL0 |= 0x00000004;
   	ADC0->ACTSS |= 0x1;
}

//void ADC_Analog_Init(void)
//{
//	SYSCTL->RCGCADC |= 0x02;
//	SysTick_Delay1ms(1);
//	SYSCTL->RCGCGPIO |= 0x10;
//	GPIOE->DIR &= ~0x02;
//	GPIOE->DEN &= ~0x02;
//	GPIOE->AMSEL |= 0x02;
//	GPIOE->AFSEL |= 0x02;
//	ADC1->ACTSS &= ~0x2;
//	ADC1->EMUX &= ~

//}

void ADC_Sample(double analog_value_buffer[])
{
	ADC0->PSSI |= 0x01;
	while((ADC0->RIS & 0x01) == 0);
	uint32_t potentiometer_sample_result = ADC0->SSFIFO0;
	ADC0->ISC |= 0x01;
	analog_value_buffer[0] = (potentiometer_sample_result * 3.3) / 4096;
}
