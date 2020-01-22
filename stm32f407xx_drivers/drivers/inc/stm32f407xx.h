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

/****************************** START: Processor Specific Details ******************************/


/*
 * ARM Cortex Mx Processor NVIC ISERx Register Addresses
 */
#define NVIC_ISER0 ( (__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1 ( (__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2 ( (__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3 ( (__vo uint32_t*)0xE000E10C )


/*
 * ARM Cortex Mx Processor NVIC ICERx Register Addresses
 */
#define NVIC_ICER0 ( (__vo uint32_t*)0XE000E180 )
#define NVIC_ICER1 ( (__vo uint32_t*)0XE000E184 )
#define NVIC_ICER2 ( (__vo uint32_t*)0XE000E188 )
#define NVIC_ICER3 ( (__vo uint32_t*)0XE000E18C )

/*
 * ARM Cortex Mx Processor Priority Register Addresses Calculation
 */
#define NVIC_PR_BASE_ADDR ( (__vo uint32_t*)0xE000E400 )
#define NO_PR_BITS_IMPLEMENTED 4


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


/*
 * Base Addresses of Peripherals which Are Hanging on APB2 Bus
 */
#define EXTI_BASEADDR    (APB2PERIPH_BASE + 0x3C00) /* This is the EXTI base address of STM32F407xx   */
#define SYSCFG_BASEADDR  (APB2PERIPH_BASE + 0x3800) /* This is the SYSCFG base address of STM32F407xx */


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
 *  Peripheral Register Definition Structure for EXTI
 */
typedef struct{
	__vo uint32_t IMR;   /* Interrupt mask register             Address offset: 0x00                */
	__vo uint32_t EMR;   /* Event mask register                 Address offset: 0x04                */
	__vo uint32_t RTSR;  /* Rising trigger selection register   Address offset: 0x08                */
	__vo uint32_t FTSR;  /* Falling trigger selection register  Address offset: 0x0C                */
	__vo uint32_t SWIER; /* Software interrupt event register   Address offset: 0x10                */
	__vo uint32_t PR;    /* Pending register                    Address offset: 0x14                */
}EXTI_RegDef_t;


/*
 *  Peripheral Register Definition Structure for SYSCFG
 */
typedef struct{
	__vo uint32_t MEMRMP;       /* SYSCFG memory remap register                        Address offset: 0x00                */
	__vo uint32_t PMC;          /* SYSCFG peripheral mode configuration register       Address offset: 0x04                */
	__vo uint32_t EXTICR[4];    /* SYSCFG external interrupt configuration register 1  Address offset: 0x08                */
	     uint32_t RESERVED1[2]; /*Reserved                                             Address offset:0x08 , 0x1C          */
	__vo uint32_t CMPCR;        /* Compensation cell control register                  Address offset: 0x20                */
	     uint32_t RESERVED2[2]; /*Reserved                                             Address offset:0x24 , 0x28          */
	__vo uint32_t CFGR;         /*                                                     Address offset:0x2C                 */
}SYSCFG_RegDef_t;


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
#define GPIOA  ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI  ((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define GPIOJ  ((GPIO_RegDef_t*)GPIOJ_BASEADDR)
#define GPIOK  ((GPIO_RegDef_t*)GPIOK_BASEADDR)
#define RCC    ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI   ((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/*
 * Clock Enable Macros for GPIOx Peripherals
 */
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN() (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN() (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN() (RCC->AHB1ENR |= (1 << 8))
#define GPIOJ_PCLK_EN() (RCC->AHB1ENR |= (1 << 9))
#define GPIOK_PCLK_EN() (RCC->AHB1ENR |= (1 << 10))

/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))


/*
 * Clock Disable Macros for GPIOx Peripherals
 */
#define GPIOA_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 8))
#define GPIOJ_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 9))
#define GPIOK_PCLK_DI() (RCC->AHB1ENR &= ~(1 << 10))


/*
 * Clock Disable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_DI() (RCC->APB2ENR &= ~(1 << 14))


/*
 * Some Generic Macros
 */
#define ENABLE            (1)
#define DISABLE           (0)
#define SET               ENABLE
#define RESET             DISABLE
#define GPIO_PIN_SET      SET
#define GPIO_PIN_RESET    RESET


/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));}while(0)
#define GPIOB_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));}while(0)
#define GPIOC_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));}while(0)
#define GPIOD_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));}while(0)
#define GPIOE_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));}while(0)
#define GPIOF_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5));}while(0)
#define GPIOG_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6));}while(0)
#define GPIOH_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));}while(0)
#define GPIOI_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8));}while(0)
#define GPIOJ_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 9)); (RCC->AHB1RSTR &= ~(1 << 9));}while(0)
#define GPIOK_REG_RESET()  do{(RCC->AHB1RSTR |= (1 << 10)); (RCC->AHB1RSTR &= ~(1 << 10));}while(0)


/*
 * This macro returns a code (between 0 to 7) for a given GPIO base address(x)
 */
#define GPIO_BASEADDR_TO_CODE(x) ((x == GPIOA) ? 0 :\
		                          (x == GPIOB) ? 1 :\
		                          (x == GPIOC) ? 2 :\
		                          (x == GPIOD) ? 3 :\
		                          (x == GPIOE) ? 4 :\
		                          (x == GPIOF) ? 5 :\
		                          (x == GPIOG) ? 6 :\
		                          (x == GPIOH) ? 7 : 0)


/*
 * IRQ (Interrupt Request) Numbers of STM32F407x MCU
 */
#define IRQ_NO_EXTI0      6
#define IRQ_NO_EXTI1      7
#define IRQ_NO_EXTI2      8
#define IRQ_NO_EXTI3      9
#define IRQ_NO_EXTI4     10
#define IRQ_NO_EXT9_5    23
#define IRQ_NO_EXT10_15  40


/*
 * Macros for all the possible priority levels
 */
#define NVIC_IRQ_PRI0   0
#define NVIC_IRQ_PRI1   1
#define NVIC_IRQ_PRI2   2
#define NVIC_IRQ_PRI3   3
#define NVIC_IRQ_PRI4   4
#define NVIC_IRQ_PRI5   5
#define NVIC_IRQ_PRI6   6
#define NVIC_IRQ_PRI7   7
#define NVIC_IRQ_PRI8   8
#define NVIC_IRQ_PRI9   9
#define NVIC_IRQ_PRI10 10
#define NVIC_IRQ_PRI11 11
#define NVIC_IRQ_PRI12 12
#define NVIC_IRQ_PRI13 13
#define NVIC_IRQ_PRI14 14
#define NVIC_IRQ_PRI15 15








#include "stm32f407xx_gpio.h"



#endif /* INC_STM32F407XX_H_ */
