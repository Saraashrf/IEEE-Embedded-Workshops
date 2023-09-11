/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : RCC_config.h ******************/
/*******************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/**
*  your options : RCC_HSE
*                 RCC_HSI
*							    RCC_PLL
*/
#define RCC_SYSCLK  RCC_HSE

/**
*  your options : RCC_CRYSTAL_CLK
*                 RCC_RC_CLK
*/
#if RCC_SYSCLK == RCC_HSE

#define RCC_BYPSS RCC_RC_CLK
#endif
/**
*  your options for RCC_PLL_SR : RCC_HSE
*                                RCC_HSI
*							  
*/

/**
*  your options for RCC_PLL_MUL : from 0b000 to 0b1111
*                
*							  
*/
#if RCC_SYSCLK == RCC_PLL

#define RCC_PLL_SRC RCC_HSI
#define RCC_PLL_MUL 0b0000
#endif
#endif /* RCC_CONFIG_H */
