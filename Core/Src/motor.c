#include "motor.h"
#include "stm32f1xx_hal.h"  // Adjust this based on your STM32 series
#include "stm32f1xx_hal_tim.h"  // Include HAL TIM header for TIM_HandleTypeDef
#include <stdint.h>         // Standard integer types

// Declare the timer handle as external
extern TIM_HandleTypeDef htim1;  // Changed from htim2 to htim1

// Function to move forward
void MoveForward(float factor) {
    // Front Motors: Set direction forward and set speed
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR1 = (uint32_t)(factor * 65535);

    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR2 = (uint32_t)(factor * 65535);               //

    // Back Motors: Set direction forward and set speed
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR3 = (uint32_t)(factor * 65535);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR4 = (uint32_t)(factor * 65535);
}
//function to move backward
void MoveBackward(float factor) {
    // Front Motors: Set direction backward and set speed
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN2_PIN, GPIO_PIN_SET);
    TIM1->CCR1 = (uint32_t)(factor * 65535);                //

    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_SET);
    TIM1->CCR2 = (uint32_t)(factor * 65535);               //

    // Back Motors: Set direction backward and set speed
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN2_PIN, GPIO_PIN_SET);
    TIM1->CCR3 = (uint32_t)(factor * 65535);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_SET);
    TIM1->CCR4 = (uint32_t)(factor * 65535);
}

// Function to turn left
void TurnLeft(float factor) {
    // Front Motors: Set direction left backward right forward and set speed
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN2_PIN, GPIO_PIN_SET);
    TIM1->CCR1 = (uint32_t) (65535);              //

    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR2 = (uint32_t)(factor * 65535);               //

    // Back Motors: Set direction left backward right forward and set speed
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN2_PIN, GPIO_PIN_SET);
    TIM1->CCR3 = (uint32_t) (65535);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR4 = (uint32_t)(factor * 65535);
}

// Function to turn right
void TurnRight(float factor) {
    // Front Motors:  Set direction right backward left forward and set speed
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR1 = (uint32_t)(factor * 65535);                //

    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_SET);
    TIM1->CCR2 = (uint32_t) (65535);              //

    // Back Motors: Set direction right backward left forward and set speed
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN1_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR3 = (uint32_t)(factor * 65535);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_SET);
    TIM1->CCR4 = (uint32_t) (65535);
}

// Function to brake (stop all motors)
void Brake(void) {
    // Front Motors: Set direction forward and full speed
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR1 = (uint32_t)(0);                //

    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR2 = (uint32_t)(0);               //

    // Back Motors: Set full speed
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR3 = (uint32_t)(0);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_RESET);
    TIM1->CCR4 = (uint32_t)(0);
}

// Function to make a U-turn By Turning Left
void UTurn(float factor) {
    // Front Motors: Set direction forward and full speed
//    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN1_PIN, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_LEFT_IN2_PIN, GPIO_PIN_SET);
//    TIM1->CCR1 = (uint32_t)(65535);                //
//
//    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, FRONT_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_RESET);
//    TIM1->CCR2 = (uint32_t)(factor * 65535);               //
//
//    // Back Motors: Set full speed
//    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN1_PIN, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_LEFT_IN2_PIN, GPIO_PIN_SET);
//    TIM1->CCR3 = (uint32_t)(65535);
//    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN1_PIN, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, BACK_MOTOR_RIGHT_IN2_PIN, GPIO_PIN_RESET);
//    TIM1->CCR4 = (uint32_t)(factor * 65535);
	TurnLeft(factor);
}
