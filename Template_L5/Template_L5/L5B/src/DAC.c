#include "stm32l476xx.h"

static void DAC_Pin_Init(void) {
    GPIOA->MODER |= GPIO_MODER_MODE4;
		GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD4;
}

void DAC_Write_Value(uint32_t value) {
    DAC->DHR12R1 = value;
}

void DAC_Init(void) {
    DAC_Pin_Init();

    // [TODO] Enable DAC clock
		RCC->APB1ENR1 |= RCC_APB1ENR1_DAC1EN;
		//DISABLE DAC
		DAC->CR &= ~DAC_CR_EN1;
    // [TODO] Enable software trigger mode
		DAC->CR |= DAC_CR_TSEL1;
    // [TODO] Disable trigger
		DAC->CR &= ~DAC_CR_TEN1;
    // [TODO] DAC1 connected in normal mode to external pin only with buffer enabled
		DAC->MCR &= ~DAC_MCR_MODE1;
    // [TODO] Enable DAC channel 1
		DAC->CR |= DAC_CR_EN1;
	
    DAC_Write_Value(0);
}
