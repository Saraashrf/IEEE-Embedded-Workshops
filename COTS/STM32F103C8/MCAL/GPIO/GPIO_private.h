/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : GPIO_PRIVATE.h ******************/
/*******************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIO_PORT_A_BASE_ADDRESS  0x40010800U
#define GPIO_PORT_B_BASE_ADDRESS  0x40010C00U
#define GPIO_PORT_C_BASE_ADDRESS  0x40011000U

/*********************< REGISTERS ADDRESSES FOR PORT A******************************/
#define GPIO_GPIOA_CRL           *((volatile u32*)(GPIO_PORT_A_BASE_ADDRESS + 0x00))
#define GPIO_GPIOA_CRH           *((volatile u32*)(GPIO_PORT_A_BASE_ADDRESS + 0x04))
#define GPIO_GPIOA_IDR           *((volatile u32*)(GPIO_PORT_A_BASE_ADDRESS + 0x08))
#define GPIO_GPIOA_ODR           *((volatile u32*)(GPIO_PORT_A_BASE_ADDRESS + 0x0C))
#define GPIO_GPIOA_BSRR          *((volatile u32*)(GPIO_PORT_A_BASE_ADDRESS + 0x10))
#define GPIO_GPIOA_BRR           *((volatile u32*)(GPIO_PORT_A_BASE_ADDRESS + 0x14))
#define GPIO_GPIOA_LCKR          *((volatile u32*)(GPIO_PORT_A_BASE_ADDRESS + 0x18))

/*********************< REGISTERS ADDRESSES FOR PORT B******************************/
#define GPIO_GPIOB_CRL           *((volatile u32*)(GPIO_PORT_B_BASE_ADDRESS + 0x00))
#define GPIO_GPIOB_CRH           *((volatile u32*)(GPIO_PORT_B_BASE_ADDRESS + 0x04))
#define GPIO_GPIOB_IDR           *((volatile u32*)(GPIO_PORT_B_BASE_ADDRESS + 0x08))
#define GPIO_GPIOB_ODR           *((volatile u32*)(GPIO_PORT_B_BASE_ADDRESS + 0x0C))
#define GPIO_GPIOB_BSRR          *((volatile u32*)(GPIO_PORT_B_BASE_ADDRESS + 0x10))
#define GPIO_GPIOB_BRR           *((volatile u32*)(GPIO_PORT_B_BASE_ADDRESS + 0x14))
#define GPIO_GPIOB_LCKR          *((volatile u32*)(GPIO_PORT_B_BASE_ADDRESS + 0x18))
	
/*********************< REGISTERS ADDRESSES FOR PORT C******************************/
#define GPIO_GPIOC_CRL           *((volatile u32*)(GPIO_PORT_C_BASE_ADDRESS + 0x00))
#define GPIO_GPIOC_CRH           *((volatile u32*)(GPIO_PORT_C_BASE_ADDRESS + 0x04))
#define GPIO_GPIOC_IDR           *((volatile u32*)(GPIO_PORT_C_BASE_ADDRESS + 0x08))
#define GPIO_GPIOC_ODR           *((volatile u32*)(GPIO_PORT_C_BASE_ADDRESS + 0x0C))
#define GPIO_GPIOC_BSRR          *((volatile u32*)(GPIO_PORT_C_BASE_ADDRESS + 0x10))
#define GPIO_GPIOC_BRR           *((volatile u32*)(GPIO_PORT_C_BASE_ADDRESS + 0x14))
#define GPIO_GPIOC_LCKR          *((volatile u32*)(GPIO_PORT_C_BASE_ADDRESS + 0x18))

#endif /**<GPIO_PRIVATE_H*/