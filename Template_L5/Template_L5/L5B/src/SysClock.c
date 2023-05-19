#include "SysClock.h"

void System_Clock_Init(void) {
	// NAY Enable HSI
		// Enable MSI
	RCC->CFGR &= RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_MSI;

	RCC->CR &= ~(RCC_CR_MSIRANGE);
	RCC->CR |= (RCC_CR_MSIRANGE_2);
	RCC->CR |= RCC_CR_MSIRGSEL;
	RCC->CR |= RCC_CR_MSION;
	while((RCC->CR & RCC_CR_MSIRDY) == 0);
}
