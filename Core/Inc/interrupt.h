/*
 * interrupt.h
 *
 *  Created on: Feb 13, 2025
 *      Author: MazenDev
 */

#ifndef MADEDRIVERS_INTERRUPT_H_
#define MADEDRIVERS_INTERRUPT_H_
#include <stdint.h>         // Standard integer types
#define TRIGGERING_INTERRUPT_PIN GPIO_PIN_10

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);


#endif /* MADEDRIVERS_INTERRUPT_H_ */
