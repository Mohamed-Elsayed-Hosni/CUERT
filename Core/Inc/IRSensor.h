#ifndef MADEDRIVERS_IR_SENSOR_H_#define MADEDRIVERS_IR_SENSOR_H_#include "stm32f1xx_hal.h"  // STM32 library for register definitions#include <stdint.h>         // Standard integer types#include <stdbool.h>        // Boolean type// Pin Definitions#define DETECTION_PIN_1     GPIO_PIN_8    // Detection indicator for Sensor 1 on PA8#define DETECTION_PIN_2     GPIO_PIN_9    // Detection indicator for Sensor 2 on PA9#define INTERRUPT_PIN       GPIO_PIN_10   // Interrupt indicator for Sensor 3 on PA10// Function Prototypes//void Sensor_Init(void);                 // Initialize the sensors//bool Any_Detecting(void);     // Check if any sensor is detecting//bool Both_Detecting(void);//bool Get_Active(void);      // Check which sensor is active (0 for left, 1 for right)void Get_Sensor_Data(void); // 0 No Detection | 1 Both Detecting | 2 Left | 3 Rightvoid Check_And_Trigger_Interrupt(void); // Check if Sensor 3 detects and trigger interrupt#endif // MADEDRIVERS_IR_SENSOR_H_