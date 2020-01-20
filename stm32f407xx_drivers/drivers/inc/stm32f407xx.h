/*
 * stm32f407xx.h
 *
 *  Created on: 20 Jan 2020
 *      Author: Emre SARIZEYBEK
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

/*
 * Base Addresses of Flash, SRAM and ROM Memories
 */
#define FLASH_BASEADDR  	(0x08000000U)  /* This is Flash memory base address of STM32F407xx  */
#define SRAM1_BASEADDR		(0x20000000U)  /* This is SRAM1 base address of STM32F407xx         */
#define SRAM2_BASEADDR  	(0x2001C000U)  /* This is SRAM2 base address of STM32F407xx         */
#define SRAM                SRAM1_BASEADDR /* This is SRAM  base address of my project           */
#define ROM 				(0x1FFF0000U)  /* This is ROM   base address of STM32F407xx           */


/*
 * AHBx and APBx Bus Peripheral Base Addresses
 */
#define PERIPH_BASE			(0x40000000U) /* This is Peripheral base address of STM32F407xx       */
#define APB1PERIPH_BASE		PERIPH_BASE   /* This is APB1 peripheral base address of STM32F407xx  */
#define APB2PERIPH_BASE		(0x40010000U) /* This is APB2 peripheral base address of STM32F407xx  */
#define AHB1PERIPH_BASE		(0x40020000U) /* This is AHB1 peripheral base address of STM32F407xx  */
#define AHB2PERIPH_BASE		(0x50000000U) /* This is AHB2 peripheral base address of STM32F407xx  */


/*
 * Base Addresses of Peripherals which Are Hanging on AHB1 Bus
 */
#define GPIOA_BASEADDR    (AHB1PERIPH_BASE + 0x0000U) /* This is GPIOA base address of STM32F407xx */
#define GPIOB_BASEADDR    (AHB1PERIPH_BASE + 0x0400U) /* This is GPIOB base address of STM32F407xx */
#define GPIOC_BASEADDR    (AHB1PERIPH_BASE + 0x0800U) /* This is GPIOC base address of STM32F407xx */
#define GPIOD_BASEADDR    (AHB1PERIPH_BASE + 0x0C00U) /* This is GPIOD base address of STM32F407xx */
#define GPIOE_BASEADDR    (AHB1PERIPH_BASE + 0x1000U) /* This is GPIOE base address of STM32F407xx */
#define GPIOF_BASEADDR    (AHB1PERIPH_BASE + 0x1400U) /* This is GPIOF base address of STM32F407xx */
#define GPIOG_BASEADDR    (AHB1PERIPH_BASE + 0x1800U) /* This is GPIOG base address of STM32F407xx */
#define GPIOH_BASEADDR    (AHB1PERIPH_BASE + 0x1C00U) /* This is GPIOH base address of STM32F407xx */
#define GPIOI_BASEADDR    (AHB1PERIPH_BASE + 0x2000U) /* This is GPIOI base address of STM32F407xx */
#define GPIOJ_BASEADDR    (AHB1PERIPH_BASE + 0x2400U) /* This is GPIOJ base address of STM32F407xx */
#define GPIOK_BASEADDR    (AHB1PERIPH_BASE + 0x2800U) /* This is GPIOK base address of STM32F407xx */
#define RCC_BASEADDR      (AHB1PERIPH_BASE + 0x3800U) /* This is RCC   base address of STM32F407xx */

#endif /* INC_STM32F407XX_H_ */
