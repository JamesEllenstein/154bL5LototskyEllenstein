/*
 * ECE 153B - Winter 2023
 *
 * Name(s):
 * Section:
 * Lab: 5B
 */


#include "ADC.h"
#include "DAC.h"
#include "EXTI.h"
#include "PWM.h"
#include "SysClock.h"
#include "stm32l476xx.h"
#include <stdio.h>
#include <math.h>
volatile int voltage;
    int main(void) {
    // Initialization
    System_Clock_Init(); // Switch System Clock = 16 MHz
	
    ADC_Init();
		LED_Init();
		TIM2_CH1_Init();
		DAC_Init();
	  EXTI_Init();
    // [TODO] Initialize PWM
		//Green_LED_Toggle();
    while (1) {
        // [TODO] Trigger ADC and get result
			ADC1->CR |= ADC_CR_ADSTART;
			while ((ADC123_COMMON->CSR & ADC_CSR_EOC_MST) != ADC_CSR_EOC_MST);
			voltage = ADC1->DR;
			ccrUpdate(floor(((float)voltage / (float)4096) * 4000));
        // [TODO] LED behavior based on ADC result
    }
}
