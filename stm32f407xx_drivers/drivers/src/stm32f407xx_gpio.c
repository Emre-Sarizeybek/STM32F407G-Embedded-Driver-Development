/*
 * stm32f407xx_gpio.c
 *
 *  Created on: 21 Jan 2020
 *      Author: Emre SARIZEYBEK
 */
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


