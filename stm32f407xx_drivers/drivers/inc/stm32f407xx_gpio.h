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



#endif /* INC_STM32F407XX_GPIO_H_ */
