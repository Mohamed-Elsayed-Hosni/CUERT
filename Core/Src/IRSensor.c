#include "IRSensor.h"
#include "motor.h"


//// Check if any sensor is detecting
//bool Any_Detecting(void) {
//	return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0) == GPIO_PIN_SET
//			|| HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1) == GPIO_PIN_SET
//			|| HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3) == GPIO_PIN_SET
//			|| HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4) == GPIO_PIN_SET;
//}
//
//bool Both_Detecting(void) {
//	return (HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0) == GPIO_PIN_SET
//			|| HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1) == GPIO_PIN_SET)
//			&& (HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3) == GPIO_PIN_SET
//			|| HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4) == GPIO_PIN_SET);
//}
//
//// Check which sensor is active (0 for left, 1 for right)
//bool Get_Active(void) {
//	return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3) == GPIO_PIN_SET
//			|| HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4) == GPIO_PIN_SET;
//}




//int Get_Sensor_Data(void){ // 0 Sensor Detecting | 1 Sensor not Detecting | 2 Left Detecting | 3 Right Detecting
//    //uint32_t right_side_sensor = read_adc_channel(ADC_CHANNEL_8);
//    uint32_t left_side_sensor = read_adc_channel(ADC_CHANNEL_8);
//    uint32_t right_front_sensor = read_adc_channel(ADC_CHANNEL_9);
////    GPIO_PinState left_side_sensor = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
//    GPIO_PinState left_front_sensor = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
//
//    // Define thresholds for ADC values (example threshold: 1000, adjust as needed)
//    const uint32_t threshold = 2.5;
//
//    if (right_front_sensor > threshold && left_side_sensor == GPIO_PIN_SET) {
//        return 0; // All sensors detect something
//    }
//    if ((right_front_sensor <= threshold) && (left_side_sensor == GPIO_PIN_RESET)) {
//        return 1; // No sensors detect something
//    }
//    if (left_side_sensor == GPIO_PIN_RESET) {
//        return 2; // Left sensors detect something
//    }
//    if (right_front_sensor <= threshold) {
//        return 3; // Right sensors detect something
//    }
//    return -1; // Undefined state
//}

void Get_Sensor_Data(void){ // 0 Sensor Detecting | 1 Sensor not Detecting | 2 Left Detecting | 3 Right Detecting
    //uint32_t right_side_sensor = read_adc_channel(ADC_CHANNEL_8);
	// Right Sensors from far to near
	GPIO_PinState right1 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
	GPIO_PinState right2 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5);
	GPIO_PinState right3 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6);
	// Left Sensors from far to near
    GPIO_PinState left1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11);
    GPIO_PinState left2 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
    GPIO_PinState left3 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);



    // Define thresholds for ADC values (example threshold: 1000, adjust as needed)
//    const uint32_t threshold = 2.5;
    // If Left Sensors are reading so Turn Right
    if (left1 | left2 | left3) TurnRight(0.3);
    // If Right Sensors are reading so Turn Left
    else if (right1 | right2 | right3) TurnLeft(0.3);
    // If None is Reading so Move Forward
    else MoveForward(0.25);
}


// Check if Sensor 3 detects and trigger interrupt
//void Check_And_Trigger_Interrupt(void) {
//    if (GPIOA->IDR & INTERRUPT_PIN) {
//        // Trigger the interrupt by setting the EXTI pending bit
//        EXTI->SWIER |= INTERRUPT_PIN;  // Software interrupt event register
//    }
//}
