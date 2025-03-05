#ifndef MADEDRIVERS_MOTOR_H_
#define MADEDRIVERS_MOTOR_H_

#include "stm32f1xx_hal.h"  // Adjust this based on your STM32 series
#include <stdint.h>         // Standard integer types
#include <stdbool.h>        // Boolean type

// Define pins for front motors (direction and PWM control)
#define FRONT_MOTOR_LEFT_IN1_PIN GPIO_PIN_0  // Example pin for Front Motor A IN1 (direction)
#define FRONT_MOTOR_LEFT_IN2_PIN GPIO_PIN_1  // Example pin for Front Motor A IN2 (direction)
#define FRONT_MOTOR_LEFT_PWM_PIN GPIO_PIN_8  // Example pin for Front Motor A PWM (speed)

#define FRONT_MOTOR_RIGHT_IN1_PIN GPIO_PIN_2  // Example pin for Front Motor B IN1 (direction)
#define FRONT_MOTOR_RIGHT_IN2_PIN GPIO_PIN_3  // Example pin for Front Motor B IN2 (direction)
#define FRONT_MOTOR_RIGHT_PWM_PIN GPIO_PIN_9  // Example pin for Front Motor B PWM (speed)

// Define PWM pins for back motors (direction and PWM control)
#define BACK_MOTOR_LEFT_IN1_PIN GPIO_PIN_4  // Example pin for Back Motor A IN1 (direction)
#define BACK_MOTOR_LEFT_IN2_PIN GPIO_PIN_5  // Example pin for Back Motor A IN2 (direction)
#define BACK_MOTOR_LEFT_PWM_PIN GPIO_PIN_10  // Example pin for Back Motor A PWM (speed)


#define BACK_MOTOR_RIGHT_IN1_PIN GPIO_PIN_6  // Example pin for Back Motor B IN1 (direction)
#define BACK_MOTOR_RIGHT_IN2_PIN GPIO_PIN_7  // Example pin for Back Motor B IN2 (direction)
#define BACK_MOTOR_RIGHT_PWM_PIN GPIO_PIN_11  // Example pin for Back Motor B PWM (speed)

// Function prototypes
void MoveForward(float);
void MoveBackward(float);
void TurnLeft(float);
void TurnRight(float);
void Brake(void);
void UTurn(float);

#endif /* MADEDRIVERS_MOTOR_H_ */
