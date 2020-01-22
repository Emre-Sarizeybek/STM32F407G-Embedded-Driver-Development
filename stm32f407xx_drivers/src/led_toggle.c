/*
 * led_toggle.c
 *
 *  Created on: 22 Jan 2020
 *      Author: Emre SARIZEYBEK
 */
#include "stm32f407xx.h"

void GPIO_LedInit(void);
void delay(void);

int main (void){

	GPIO_LedInit();

	while(1){

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
		delay();
	}

	return 0;
}


void GPIO_LedInit(void){
	GPIO_Handle_t GPIO_Led;

	/* This is led gpio configuration */
	GPIO_Led.pGPIOx = GPIOD;                                   /* GPIOD base address    */
	GPIO_Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;      /* GPIO pin mode         */
	GPIO_Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;   /* GPIO pin no           */
	GPIO_Led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;   /* GPIO pin speed        */
	GPIO_Led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU; /* GPIO pin PuPd control */
	GPIO_Led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;  /* GPIO pin output type  */
	GPIO_Init(&GPIO_Led);

	GPIO_Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_Init(&GPIO_Led);

	GPIO_Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GPIO_Init(&GPIO_Led);

	GPIO_Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GPIO_Init(&GPIO_Led);
}

void delay(void){

	for (uint32_t i=0; i<500000/2; i++);
}
