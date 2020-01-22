/*
 * stm32f407xx_gpio.c
 *
 *  Created on: 21 Jan 2020
 *      Author: Emre SARIZEYBEK
 */
#include "stm32f407xx_gpio.h"
#include "stm32f407xx.h"


/************************************************************************************************************
 * @fn                     : GPIO_PeriClockControl
 * @brief                  : This function enables or disables peripheral clock for GPIO ports
 * @param1[in]             : Base address of the GPIO peripheral
 * @param2[in]             : ENABLE or DISABLE macros
 * @return                 : None
 ************************************************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){

	if (EnorDi == ENABLE){
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF){
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG){
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH){
			GPIOH_PCLK_EN();
		}
		else if(pGPIOx == GPIOI){
			GPIOI_PCLK_EN();
		}
		else if(pGPIOx == GPIOJ){
			GPIOJ_PCLK_EN();
		}
		else if(pGPIOx == GPIOK){
			GPIOK_PCLK_EN();
		}
		else{
			if(pGPIOx == GPIOA){
				GPIOA_PCLK_DI();
			}
			else if(pGPIOx == GPIOB){
				GPIOB_PCLK_DI();
			}
			else if(pGPIOx == GPIOC){
				GPIOC_PCLK_DI();
			}
			else if(pGPIOx == GPIOD){
				GPIOD_PCLK_DI();
			}
			else if(pGPIOx == GPIOE){
				GPIOE_PCLK_DI();
			}
			else if(pGPIOx == GPIOF){
				GPIOF_PCLK_DI();
			}
			else if(pGPIOx == GPIOG){
				GPIOG_PCLK_DI();
			}
			else if(pGPIOx == GPIOH){
				GPIOH_PCLK_DI();
			}
			else if(pGPIOx == GPIOI){
				GPIOI_PCLK_DI();
			}
			else if(pGPIOx == GPIOJ){
				GPIOJ_PCLK_DI();
			}
			else if(pGPIOx == GPIOK){
				GPIOK_PCLK_DI();
			}
		}
	}
}


/************************************************************************************************************
 * @fn                     : GPIO_Init
 * @brief                  : This function initialize GPIO pins
 * @param[in]              : Base address of GPIO_Handle_t structure
 * @return                 : None
 ************************************************************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	uint32_t tempreg = 0; /* This is a temp variable  */

	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE); /* This function enables GPIOx peripheral clock */

	/* 1. Configure the mode of gpio pin*/
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG ){
		tempreg = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~( 0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); /* Clearing */
		pGPIOHandle->pGPIOx->MODER |= tempreg; /* Setting */
	}

	/* 2. Configure the speed of gpio pin*/
	tempreg = 0;
	tempreg = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); /* Clearing */
	pGPIOHandle->pGPIOx->OSPEEDR |= tempreg; /* Setting */

	/* 3. Configure the PuPd settings */
	tempreg = 0;
	tempreg = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); /* Clearing */
	pGPIOHandle->pGPIOx->PUPDR |= tempreg; /* Setting */

	/* 4. Configure the OpType */
	tempreg = 0;
	tempreg = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); /* Clearing */
	pGPIOHandle->pGPIOx->OTYPER |= tempreg; /* Setting */

	/* 5. Configure the alt functionality */
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN ){
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2)); /* Clearing */
	    pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2)); /* Setting */
	}
}


/************************************************************************************************************
 * @fn                     : GPIO_DeInit
 * @brief                  : This function resets GPIOx ports
 * @param[in]              : Base address of GPIO_RegDef_t structure
 * @return                 : None
 ************************************************************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

	if(pGPIOx == GPIOA){
			GPIOA_REG_RESET();
		}
		else if(pGPIOx == GPIOB){
			GPIOB_REG_RESET();
		}
		else if(pGPIOx == GPIOC){
			GPIOC_REG_RESET();
		}
		else if(pGPIOx == GPIOD){
			GPIOD_REG_RESET();
		}
		else if(pGPIOx == GPIOE){
			GPIOE_REG_RESET();
		}
		else if(pGPIOx == GPIOF){
			GPIOF_REG_RESET();
		}
		else if(pGPIOx == GPIOG){
			GPIOG_REG_RESET();
		}
		else if(pGPIOx == GPIOH){
			GPIOH_REG_RESET();
		}
		else if(pGPIOx == GPIOI){
			GPIOI_REG_RESET();
		}
		else if(pGPIOx == GPIOJ){
			GPIOJ_REG_RESET();
		}
		else if(pGPIOx == GPIOK){
			GPIOK_REG_RESET();
		}
}


/************************************************************************************************************
 * @fn                     : GPIO_ToggleOutputPin
 * @brief                  : This function toggles GPIOx pin state
 * @param1[in]             : Base address of GPIO_RegDef_t structure
 * @param2[in]             : Pin number of GPIOx
 * @return                 : None
 ************************************************************************************************************/
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	pGPIOx->ODR ^=  (1 << PinNumber);
}


/************************************************************************************************************
 * @fn                     : GPIO_ReadFromInputPin
 * @brief                  : This function reads input pin state
 * @param1[in]             : Base address of GPIO_RegDef_t structure
 * @param2[in]             : Pin number of GPIOx
 * @return                 : 0 or 1
 ************************************************************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	uint8_t value = 0;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}





