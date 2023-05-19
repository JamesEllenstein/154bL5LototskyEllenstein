#ifndef __STM32L476G_DISCOVERY_PWM_H
#define __STM32L476G_DISCOVERY_PWM_H

#include "stm32l476xx.h"

// [TODO]void LED_Init(void);
void LED_Init(void);
void Green_LED_Off(void);
void Green_LED_On(void);
void Green_LED_Toggle(void);
void TIM2_CH1_Init(void);
void ccrUpdate(uint32_t ccrVal);

#endif /* __STM32L476G_DISCOVERY_PWM_H */
