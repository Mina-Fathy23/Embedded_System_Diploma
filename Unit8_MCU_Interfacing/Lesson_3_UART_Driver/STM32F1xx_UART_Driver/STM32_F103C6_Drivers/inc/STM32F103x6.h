/*
 * STM32F103x6.h
 *
 *  Created on: Sep 16, 2024
 *      Author: Mina Fathy
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//----------------------------
//Includes
//----------------------------

#include <stdlib.h>
#include "Platform_Types.h"
#include "Utils.h"

//----------------------------
//Base addresses for Memories
//----------------------------

#define Flash_Memory_BASE						0x08000000UL
#define System_Memory_BASE						0x1FFFF000UL
#define SRAM_Memory_BASE						0x20000000UL

#define Peripherals_BASE						0x40000000UL

#define Cortex_M3_Internal_Peripherals_BASE		0xE0000000UL

//NVIC register Map
#define NVIC_BASE								0xE000E100UL
#define NVIC_ISER0								*((volatile uint32_t *)(NVIC_BASE + 0x0 ))
#define NVIC_ISER1								*((volatile uint32_t *)(NVIC_BASE + 0x4 ))
#define NVIC_ISER2								*((volatile uint32_t *)(NVIC_BASE + 0x8 ))
#define NVIC_ICER0								*((volatile uint32_t *)(NVIC_BASE + 0x80))
#define NVIC_ICER1								*((volatile uint32_t *)(NVIC_BASE + 0x84))
#define NVIC_ICER2								*((volatile uint32_t *)(NVIC_BASE + 0x88))

//----------------------------
//Base addresses for AHB Peripherals
//----------------------------

//RCC
#define RCC_BASE								0x40021000UL

//----------------------------
//Base addresses for APB2 Peripherals
//----------------------------

//GPIO
//A,B Fully included in LQFP48 Package
#define GPIOA_Base								0x40010800UL
#define GPIOB_Base								0x40010C00UL

//C,D Partially included in LQFP48 Package
#define GPIOC_Base								0x40011000UL
#define GPIOD_Base								0x40011400UL

//E not included in LQFP48 Package
#define GPIOE_Base								0x40011800UL

//EXTI
#define EXTI_Base								0x40010400UL

//AFIO
#define AFIO_Base								0x40010000UL

//USART1
#define USART1_Base								0x40013800UL

//----------------------------
//Base addresses for APB1 Peripherals
//----------------------------

//USART2-3
#define USART2_Base								0x40004400UL
#define USART3_Base								0x40004800UL



//======================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef	struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_TypedDef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4]; //EXTICR1, EXTICR2 ,EXTICR3, EXTICR4
			 uint32_t Reserved0; //0x18
	volatile uint32_t MAPR2;	 //0x1C

}AFIO_TypedDef;


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;

}USART_TypedDef;


//=======================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA				((GPIO_TypeDef *)GPIOA_Base)
#define GPIOB				((GPIO_TypeDef *)GPIOB_Base)
#define GPIOC				((GPIO_TypeDef *)GPIOC_Base)
#define GPIOD				((GPIO_TypeDef *)GPIOD_Base)
#define GPIOE				((GPIO_TypeDef *)GPIOE_Base)

#define RCC					((RCC_TypeDef *)RCC_BASE)

#define EXTI				((EXTI_TypedDef *)EXTI_Base)

#define AFIO				((AFIO_TypedDef *)AFIO_Base)

#define USART1				((USART_TypedDef *)USART1_Base)
#define USART2				((USART_TypedDef *)USART2_Base)
#define USART3				((USART_TypedDef *)USART2_Base)

//========================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()			(RCC->APB2ENR |= 1 << 2)
#define RCC_GPIOB_CLK_EN()			(RCC->APB2ENR |= 1 << 3)
#define RCC_GPIOC_CLK_EN()			(RCC->APB2ENR |= 1 << 4)
#define RCC_GPIOD_CLK_EN()			(RCC->APB2ENR |= 1 << 5)
#define RCC_GPIOE_CLK_EN()			(RCC->APB2ENR |= 1 << 6)

#define RCC_AFIO_CLK_EN()			(RCC->APB2ENR |= 1 << 0)

#define RCC_USART1_CLK_EN()			(RCC->APB2ENR |= 1 << 14)
#define RCC_USART2_CLK_EN()			(RCC->APB1ENR |= 1 << 17)
#define RCC_USART3_CLK_EN()			(RCC->APB1ENR |= 1 << 18)

#define RCC_USART1_CLK_Reset()		(RCC->APB2RSTR |= 0 << 14)
#define RCC_USART2_CLK_Reset()		(RCC->APB1RSTR |= 1 << 17)
#define RCC_USART3_CLK_Reset()		(RCC->APB1RSTR |= 1 << 18)


//=========================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*
//IVT
//-*-*-*-*-*-*-*-*-*-*-*
//EXTI
#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10
#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23
#define EXTI10_IRQ			40
#define EXTI11_IRQ			40
#define EXTI12_IRQ			40
#define EXTI13_IRQ			40
#define EXTI14_IRQ			40
#define EXTI15_IRQ			40

//USART_Interrupt
#define USART1_IRQ			37
#define USART2_IRQ			38
#define USART3_IRQ			39


//-*-*-*-*-*-*-*-*-*-*-*
//NVIC IRQ Enable/Diable MACROS:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_IRQ6_EXTI0_Enable			(NVIC_ISER0 |= 1 << 6 )
#define NVIC_IRQ7_EXTI1_Enable			(NVIC_ISER0 |= 1 << 7 )
#define NVIC_IRQ8_EXTI2_Enable			(NVIC_ISER0 |= 1 << 8 )
#define NVIC_IRQ9_EXTI3_Enable			(NVIC_ISER0 |= 1 << 9 )
#define NVIC_IRQ10_EXTI4_Enable			(NVIC_ISER0 |= 1 << 10)
#define NVIC_IRQ23_EXTI5_9_Enable		(NVIC_ISER0 |= 1 << 23)
#define NVIC_IRQ40_EXTI10_15_Enable		(NVIC_ISER1 |= 1 << 8 ) 	//40 - 32 = 8

#define NVIC_IRQ6_EXTI0_Disable			(NVIC_ICER0 |= 1 << 6 )
#define NVIC_IRQ7_EXTI1_Disable			(NVIC_ICER0 |= 1 << 7 )
#define NVIC_IRQ8_EXTI2_Disable			(NVIC_ICER0 |= 1 << 8 )
#define NVIC_IRQ9_EXTI3_Disable			(NVIC_ICER0 |= 1 << 9 )
#define NVIC_IRQ10_EXTI4_Disable		(NVIC_ICER0 |= 1 << 10)
#define NVIC_IRQ23_EXTI5_9_Disable		(NVIC_ICER0 |= 1 << 23)
#define NVIC_IRQ40_EXTI10_15_Disable	(NVIC_ICER1 |= 1 << 8 )		//40 - 32 = 8


#define NVIC_IRQ37_USART1_Enable		(NVIC_ISER1 |= 1 << 5 )		//37 - 32 = 5
#define NVIC_IRQ38_USART2_Enable		(NVIC_ISER1 |= 1 << 6 )		//38 - 32 = 6
#define NVIC_IRQ39_USART3_Enable		(NVIC_ISER1 |= 1 << 7 )		//39 - 32 = 7

#define NVIC_IRQ37_USART1_Disable		(NVIC_ICER1 |= 1 << 5 )		//37 - 32 = 5
#define NVIC_IRQ38_USART2_Disable		(NVIC_ICER1 |= 1 << 6 )		//38 - 32 = 6
#define NVIC_IRQ39_USART3_Disable		(NVIC_ICER1 |= 1 << 7 )		//39 - 32 = 7




#endif /* INC_STM32F103X6_H_ */
