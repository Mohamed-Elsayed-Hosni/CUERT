#include "IRSensor.h"
#include "motor.h"



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




    // If Left Sensors are reading so Turn Right
    if (left1 | left2 | left3) TurnRight(0.3);
    // If Right Sensors are reading so Turn Left
    else if (right1 | right2 | right3) TurnLeft(0.3);
    // If None is Reading so Move Forward
    else MoveForward(0.25);
}

