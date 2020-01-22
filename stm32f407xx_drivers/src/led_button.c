/*
 * led_button.c
 *
 *  Created on: 22 Jan 2020
 *      Author: Emre SARIZEYBEK
 */
#include "stm32f407xx.h"
void GPIO_LedInit(void);
void GPIO_ButtonInit(void);
void delay(void);

#define HIGH        ENABLE
#define BTN_PRESSED HIGH

int main(void){

	GPIO_LedInit();
	GPIO_ButtonInit();

	while(1){

		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED){
			delay();
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		}
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
}

void GPIO_ButtonInit(void){

	GPIO_Handle_t GPIO_Button;
	/* This is button gpio configuration */
	GPIO_Button.pGPIOx = GPIOA;                                   /* GPIOA base address    */
	GPIO_Button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;       /* GPIO pin mode         */
	GPIO_Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;    /* GPIO pin no           */
	GPIO_Button.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;   /* GPIO pin speed        */
	GPIO_Button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PD; /* GPIO pin PuPd control */
	GPIO_Init(&GPIO_Button);
}

void delay(void){
	for ( uint32_t i = 0; i < 500000/2 ; i++) ;
}
