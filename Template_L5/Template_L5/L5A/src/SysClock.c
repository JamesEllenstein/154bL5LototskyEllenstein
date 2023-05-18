#include "SysClock.h"

void System_Clock_Init(void) {
	
	// Enable MSI
	RCC->CFGR &= RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_MSI;

	RCC->CR &= ~(RCC_CR_MSIRANGE);
	RCC->CR |= (RCC_CR_MSIRANGE_2);
	RCC->CR |= RCC_CR_MSIRGSEL;
	RCC->CR |= RCC_CR_MSION;
	while((RCC->CR & RCC_CR_MSIRDY) == 0);
	
	// Select MSI as system clock source

	/*
	// Enable HSI
	RCC->CR |= RCC_CR_HSION;
	while((RCC->CR & RCC_CR_HSIRDY) == 0);
	
	// Select HSI as system clock source
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_HSI;
	while((RCC->CFGR & RCC_CFGR_SWS) == 0);
	*/
}
