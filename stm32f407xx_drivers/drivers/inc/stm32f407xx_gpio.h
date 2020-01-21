/*
 * stm32f407xx_gpio.h
 *
 *  Created on: 21 Jan 2020
 *      Author: Emre SARIZEYBEK
 */

#ifndef INC_STM32F407XX_GPIO_H_
#define INC_STM32F407XX_GPIO_H_

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




#endif /* INC_STM32F407XX_GPIO_H_ */
