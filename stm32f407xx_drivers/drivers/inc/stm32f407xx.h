/*
 * stm32f407xx.h
 *
 *  Created on: 20 Jan 2020
 *      Author: Emre SARIZEYBEK
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#define  __vo volatile

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

/********************* Peripheral Register Definition Structures *********************/

/*
 * Peripheral Register Definition Structure for GPIO
 */
typedef struct{
	 __vo uint32_t MODER;   /* GPIO port mode register                      Address offset: 0x00 */
	 __vo uint32_t OTYPER;  /* GPIO port output type register               Address offset: 0x04 */
	 __vo uint32_t OSPEEDR; /* GPIO port output speed register              Address offset: 0x08 */
	 __vo uint32_t PUPDR;   /* GPIO port pull-up/pull-down register         Address offset: 0x0C */
	 __vo uint32_t IDR;     /* GPIO port input data register                Address offset: 0x10 */
	 __vo uint32_t ODR;     /* GPIO port output data register               Address offset: 0x14 */
	 __vo uint32_t BSRR;    /* GPIO port bit set/reset register             Address offset: 0x18 */
	 __vo uint32_t LCKR;    /* GPIO port configuration lock register        Address offset: 0x1C */
	 __vo uint32_t AFR[2];  /* AFR[0]: GPIO alternate function low register Address offset: 0x20 ,  AFR[1]: GPIO alternate function high register Address offset: 0x24 */
}GPIO_RegDef_t;


/*
 * Peripheral Register Definition Structure for RCC
 */
typedef struct{
	__vo uint32_t CR;           /* RCC clock control register                                   Address offset: 0x00                */
	__vo uint32_t PLLCFGR;      /* RCC PLL configuration register                               Address offset: 0x04                */
	__vo uint32_t CFGR;         /* RCC clock configuration register                             Address offset: 0x08                */
	__vo uint32_t CIR;          /* RCC clock interrupt register                                 Address offset: 0x0C                */
	__vo uint32_t AHB1RSTR;     /* RCC AHB1 peripheral reset register                           Address offset: 0x10                */
	__vo uint32_t AHB2RSTR;     /* RCC AHB2 peripheral reset register                           Address offset: 0x14                */
	__vo uint32_t AHB3RSTR;     /* RCC AHB3 peripheral reset register                           Address offset: 0x18                */
		 uint32_t RESERVED0;    /* Reserved: 0x1C          */
	__vo uint32_t APB1RSTR;     /* RCC APB1 peripheral reset register                           Address offset: 0x20                */
	__vo uint32_t APB2RSTR;     /* RCC APB2 peripheral reset register                           Address offset: 0x24                */
	     uint32_t RESERVED1[2]; /* Reserved: 0x28 , 0x2C   */
	__vo uint32_t AHB1ENR;      /* RCC AHB1 peripheral clock register                           Address offset: 0x30                */
	__vo uint32_t AHB2ENR;      /* RCC AHB2 peripheral clock enable register                    Address offset: 0x34                */
	__vo uint32_t AHB3ENR;      /* RCC AHB3 peripheral clock enable register                    Address offset: 0x38                */
	     uint32_t RESERVED2;    /* Reserved: 0x3C          */
	__vo uint32_t APB1ENR;      /* RCC APB1 peripheral clock enable register                    Address offset: 0x40                */
	__vo uint32_t APB2ENR;      /* RCC APB2 peripheral clock enable register                    Address offset: 0x44                */
	     uint32_t RESERVED3[2]; /* Reserved: 0x48 , 0x4C   */
	__vo uint32_t AHB1LPENR;    /* RCC AHB1 peripheral clock enable in low power mode register  Address offset: 0x50                */
	__vo uint32_t AHB2LPENR;    /* RCC AHB2 peripheral clock enable in low power mode register  Address offset: 0x54                */
	__vo uint32_t AHB3LPENR;    /* RCC AHB3 peripheral clock enable in low power mode register  Address offset: 0x58                */
	     uint32_t RESERVED4;    /* Reserved: 0x5C          */
	__vo uint32_t APB1LPENR;    /* RCC APB1 peripheral clock enable in low power mode register  Address offset: 0x60                */
	__vo uint32_t APB2LPENR;    /* RCC APB2 peripheral clock enabled in low power mode register Address offset: 0x64                */
	     uint32_t RESERVED5[2]; /* Reserved: 0x68 , 0x6C   */
	__vo uint32_t BDCR;         /* RCC Backup domain control register                           Address offset: 0x70                */
	__vo uint32_t CSR;          /* RCC clock control & status register                          Address offset: 0x74                */
	     uint32_t RESERVED6[2]; /* Reserved: 0x78 , 0x7C   */
	__vo uint32_t SSCGR;        /* RCC spread spectrum clock generation register                Address offset: 0x80                */
	__vo uint32_t PLLI2SCFGR;   /* RCC PLLI2S configuration register                            Address offset: 0x84                */
}RCC_RegDef_t;


/*
 * Peripheral Definitions Macros
 */
#define GPIOA ( (GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB ( (GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC ( (GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD ( (GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE ( (GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF ( (GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG ( (GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH ( (GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI ( (GPIO_RegDef_t*) GPIOI_BASEADDR)
#define GPIOJ ( (GPIO_RegDef_t*) GPIOJ_BASEADDR)
#define GPIOK ( (GPIO_RegDef_t*) GPIOK_BASEADDR)
#define RCC   ((RCC_RegDef_t*) RCC_BASEADDR)












#endif /* INC_STM32F407XX_H_ */
