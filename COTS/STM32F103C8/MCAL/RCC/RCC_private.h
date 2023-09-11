/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : RCC_private.h ******************/
/*******************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_BASE_ADDRESS     0X40021000u
#define RCC_CR_R                 (*((volatile u32*)(RCC_BASE_ADDRESS + 0X00)))
#define RCC_CFGR_R               (*((volatile u32*)(RCC_BASE_ADDRESS + 0X04)))
#define RCC_CIR_R                (*((volatile u32*)(RCC_BASE_ADDRESS + 0X08)))
#define RCC_APB2RSTR_R           (*((volatile u32*)(RCC_BASE_ADDRESS + 0X0C)))
#define RCC_APB1RSTR_R           (*((volatile u32*)(RCC_BASE_ADDRESS + 0X10)))
#define RCC_AHBENR_R             (*((volatile u32*)(RCC_BASE_ADDRESS + 0X14)))
#define RCC_APB2ENR_R            (*((volatile u32*)(RCC_BASE_ADDRESS + 0X18)))
#define RCC_APB1ENR_R            (*((volatile u32*)(RCC_BASE_ADDRESS + 0X1C)))
#define RCC_BDCR_R               (*((volatile u32*)(RCC_BASE_ADDRESS + 0X20)))
#define RCC_CSR_R                (*((volatile u32*)(RCC_BASE_ADDRESS + 0X24)))

#define RCC_PIN_0 0
#define RCC_PIN_1 1
#define RCC_PIN_2 2
#define RCC_PIN_3 3
#define RCC_PIN_4 4 
#define RCC_PIN_5 5
#define RCC_PIN_6 6
#define RCC_PIN_7 7
#define RCC_PIN_8 8
#define RCC_PIN_9 9
#define RCC_PIN_10 10
#define RCC_PIN_11 11
#define RCC_PIN_12 12
#define RCC_PIN_13 13
#define RCC_PIN_14 14
#define RCC_PIN_15 15
#define RCC_PIN_16 16
#define RCC_PIN_17 17
#define RCC_PIN_18 18
#define RCC_PIN_19 19
#define RCC_PIN_20 20
#define RCC_PIN_21 21
#define RCC_PIN_22 22
#define RCC_PIN_23 23
#define RCC_PIN_24 24
#define RCC_PIN_25 25
#define RCC_PIN_26 26
#define RCC_PIN_27 27
#define RCC_PIN_28 28
#define RCC_PIN_29 29
#define RCC_PIN_30 30
#define RCC_PIN_30 31
#define RCC_PIN_32 32


#define RCC_HSE  0
#define RCC_HSI  1
#define RCC_PLL  2

#define RCC_CRYSTAL_CLK  0
#define RCC_RC_CLK       1
#endif /* RCC_PRIVATE_H */