/*
 * stm32f407xx_gpio.h
 *
 *  Created on: 21 Jan 2020
 *      Author: Emre SARIZEYBEK
 */

#ifndef INC_STM32F407XX_GPIO_H_
#define INC_STM32F407XX_GPIO_H_

#include "stm32f407xx.h"


/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0    0
#define GPIO_PIN_NO_1    1
#define GPIO_PIN_NO_2    2
#define GPIO_PIN_NO_3    3
#define GPIO_PIN_NO_4    4
#define GPIO_PIN_NO_5    5
#define GPIO_PIN_NO_6    6
#define GPIO_PIN_NO_7    7
#define GPIO_PIN_NO_8    8
#define GPIO_PIN_NO_9    9
#define GPIO_PIN_NO_10  10
#define GPIO_PIN_NO_11  11
#define GPIO_PIN_NO_12  12
#define GPIO_PIN_NO_13  13
#define GPIO_PIN_NO_14  14
#define GPIO_PIN_NO_15  15


/*
 * @GPIO_PIN_MODES
 * GPIO possible modes
 */
#define GPIO_MODE_IN     0
#define GPIO_MODE_OUT    1
#define GPIO_MODE_ALTFN  2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_FT  4
#define GPIO_MODE_IT_RT  5
#define GPIO_MODE_IT_RFT 6


/*
 * @GPIO_PIN_OP_TYPE
 * GPIO pin possible output modes
 */
#define GPIO_OP_TYPE_PP  0
#define GPIO_OP_TYPE_OD  1


/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW    0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST   2
#define GPIO_SPEED_HIGH   3


/*
 * @GPIO_PIN_PP_PD_TYPE
 * GPIO pin pull up and pull down configuration macros
 */
#define GPIO_NO_PUPD       0
#define GPIO_PIN_PU        1
#define GPIO_PIN_PD        2


/*
 * This is a configuration structure for a GPIOx pin
 */
typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


/*
 * This is a handle structure for a GPIOx pin
 */
typedef struct{
	GPIO_RegDef_t     *pGPIOx;
	GPIO_PinConfig_t  GPIO_PinConfig;
}GPIO_Handle_t;


/****************************************************************************
 *                   APIs supported by this driver
 * Note: For more information about the APIs check the function definitions
 ****************************************************************************/

/*
 * This is a peripheral clock control function for GPIO ports
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);


/*
 * This is a GPIO initial function for GPIO pins
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);


/*
 * This is a GPIO De-Init function for GPIO ports
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


/*
 * This function toggles output GPIO pin state
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * This function reads input pin state
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * This function reads input port state
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 *  IRQ Configuration and ISR handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber , uint8_t EnOrDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);




#endif /* INC_STM32F407XX_GPIO_H_ */
