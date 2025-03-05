/*
 * interrupt.c
 *
 *  Created on: Feb 13, 2025
 *      Author: MazenDev
 */

#include "interrupt.h"
#include "motor.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == TRIGGERING_INTERRUPT_PIN) // If The INT Source Is EXTI Line10
    {
        // Your interrupt handling code for the third IR sensor
        // For example:
            Brake();
            HAL_Delay(5000);
            MoveForward(1);
    }
}


