/*
 * button_interrupt.c
 *
 *  Created on: 22 Jan 2020
 *      Author: Emre SARIZEYBEK
 */


#include "stm32f407xx.h"
#include <string.h>

void GPIO_LedInit(void);
void GPIO_ButtonInit(void);
void delay(void);
void EXTI0_IRQHandler(void);

#define HIGH        ENABLE
#define BTN_PRESSED HIGH


int main (void){

	GPIO_LedInit();
	GPIO_ButtonInit();


	/* IRQ Configurations */
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0, NVIC_IRQ_PRI0);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0 , ENABLE);

	while(1);

	return 0;
}

void GPIO_LedInit(void){
	/* This is led gpio configuration */
	GPIO_Handle_t GpioLed;
	memset(&GpioLed,0,sizeof(GpioLed));
	GpioLed.pGPIOx = GPIOD; /* GPIOD base address */
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;     /* GPIO pin mode         */
	GpioLed.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;      /* GPIO pin no           */
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;    /* GPIO pin speed        */
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;    /* GPIO pin PuPd control */
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;  /* GPIO pin output type  */
	GPIO_Init(&GpioLed);
}


void GPIO_ButtonInit(void){
	/* This is button configuration */
	GPIO_Handle_t GPIOBtn;
	memset(&GPIOBtn,0,sizeof(GPIOBtn));
	GPIOBtn.pGPIOx = GPIOA; /* GPIOA base address */
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;     /* GPIO pin mode         */
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_IT_FT;   /* GPIO pin no           */
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;   /* GPIO pin speed        */
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PD;  /* GPIO pin PuPd control */
	GPIO_Init(&GPIOBtn);
}


void delay(void){

	for ( uint32_t i = 0; i < 500000/2 ; i++) ;

}


void EXTI0_IRQHandler(void){

	delay();
	GPIO_IRQHandling(GPIO_PIN_NO_0);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
}


