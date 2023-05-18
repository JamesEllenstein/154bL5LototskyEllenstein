#include "PWM.h"

// [TODO]
void LED_Init(void) {
    // Enable GPIO Clock
    RCC->AHB2ENR |= (RCC_AHB2ENR_GPIOAEN); //equivalent to (1<<0)
    // Initialize Green LED
		GPIOA->MODER &= ~GPIO_MODER_MODE5;
		GPIOA->MODER |= GPIO_MODER_MODE5_1;
		GPIOA->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR5;
		GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;
	 	GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL5;
		GPIOA->AFR[0] |= GPIO_AFRL_AFSEL5_0;
		GPIOA->OTYPER &=  ~GPIO_OTYPER_OT5;
		GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD5;
}
void Green_LED_Off(void) {
	GPIOA->ODR &= ~(1<<5);
}
void Green_LED_On(void) {
	GPIOA->ODR |= (1<<5);
}
void Green_LED_Toggle(void) {
	GPIOA->ODR ^= (1<<5);
}
void TIM2_CH1_Init(void){
	// Enable the timer clock
	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;

	// Counting direction: 0 = up-counting, 1 = down-counting
	TIM2->CR1 &= ~(TIM_CR1_DIR);
	TIM2->CR1 |= TIM_CR1_DIR;
  // Prescaler
	TIM2->PSC = 3;
  // Auto-reload
	TIM2->CR1 |= TIM_CR1_ARPE;
	TIM2->ARR = 16000;
	// Disable output compare mode
	TIM2->CCMR1 &= ~TIM_CCMR1_OC1M;
	// PWM mode 1
	TIM2->CCMR1 |= (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2);
	// Output 1 preload enable
	TIM2->CCMR1 |= TIM_CCMR1_OC1PE;
	// Select output polarity: active high
	TIM2->CCER |= TIM_CCER_CC1P;
  // Enable output for ch1
	TIM2->CCER |= TIM_CCER_CC1E;
	// Output Compare Register for channel 1
	TIM2->CCR1 = 5;
	// Enable counter
	TIM2->CR1 |= TIM_CR1_CEN;
}
void ccrUpdate(uint32_t ccrVal) {
	TIM2->CCR1 = ccrVal;
}
