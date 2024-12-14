/**
 * @file ADC.h
 *
 * @brief Header file for the ADC driver.
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

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"

/**
 * @brief function, ADC_Init, that will be used to initialize ADC
		Module 0 to use the PE2 pin as an input analog source. The PE2 pin is used by the
		on the EduBase board. The ADC module will be configured to sample the
		potentiometer, and an interrupt signal will be set to indicate that the sampling has finished.
		After the conversion result has been read from the corresponding FIFO, the interrupt will
		be cleared.
 *
 * @param
 *
 * @return none
 */
void ADC_Init(void);

/**
 * @brief ADC_Sample, that will be used to initiate the
	Sample Sequencer 0 module to begin sampling. A busy-wait loop will be used to wait until
	an interrupt has occurred. This interrupt signal will indicate the end of the sampling
	sequence. After the interrupt signal has been set, the conversion results will be read from
	the FIFO and the interrupt is cleared. Then, the measured analog voltage is calculated and
	stored in a double array.
 *
 * @param
 *
 * @return analog_value_buffer[0]
*/
void ADC_Sample(double analog_value_buffer[]);

void ADC_Analog_Init(void);

