/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : RCC_program.c ******************/
/*******************************************************/

/************** < LIB *********/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************** < MCAL *********/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

STD_ReturnType Mcal_Rcc_InitClkSystem()
{
	STD_ReturnType local_functionStatus = E_NOT_OK;
	#if RCC_SYSCLK == RCC_HSE
	  
	  #if RCC_BYPSS == RCC_RC_CLK
	    SET_BIT(RCC_CR_R,RCC_PIN_18);
	    
	  #elif RCC_BYPSS == RCC_CRYSTAL_CLK
	    CLR_BIT(RCC_CR_R,RCC_PIN_18);
	   
	  #else
	    #error "WRONG !!!"
	  #endif /**< RCC_BYPSS */
	
	  SET_BIT(RCC_CR_R,RCC_PIN_16);
	  while(!GET_BIT(RCC_CR_R,RCC_PIN_17));
	  RCC_CFGR_R=0x01;
	
	  local_functionStatus = E_OK;
	#elif RCC_SYSCLK == RCC_HSI
	  SET_BIT(RCC_CR_R,RCC_PIN_0);
	  while(!GET_BIT(RCC_CR_R,RCC_PIN_1));
	  RCC_CFGR_R=0x00;
		local_functionStatus = E_OK;
		
	#elif RCC_SYSCLK == RCC_PLL
	  #if RCC_PLL_SRC == RCC_HSI
		  SET_BIT(RCC_CR_R,RCC_PIN_0);
	    while(!GET_BIT(RCC_CR_R,RCC_PIN_1));
			CLR_BIT(RCC_CFGR_R,RCC_PIN_16);
		#elif RCC_PLL_SRC == RCC_HSE
	  
	    #if RCC_BYPSS == RCC_RC_CLK
	      SET_BIT(RCC_CR_R,RCC_PIN_18);
	    
	    #elif RCC_BYPSS == RCC_CRYSTAL_CLK
	      CLR_BIT(RCC_CR_R,RCC_PIN_18);
	   
	    #else
	      #error "WRONG !!!"
	    #endif /**< RCC_BYPSS */
	
	    SET_BIT(RCC_CR_R,RCC_PIN_16);
	    while(!GET_BIT(RCC_CR_R,RCC_PIN_17));	
		  SET_BIT(RCC_CFGR_R,RCC_PIN_16);
		#else
		  #error "wrong!!"
		#endif /*<RCC_PLL_SRC*/
		RCC_CFGR_R |= (RCC_PLL_MUL<<18);
	  SET_BIT(RCC_CR_R,RCC_PIN_24);
	  while(!GET_BIT(RCC_CR_R,RCC_PIN_25));
		RCC_CFGR_R |=0x02;
		local_functionStatus = E_OK;
	#else
	   #error "WRONG !!!"
	#endif /**< RCC_SYSCLK */
	return local_functionStatus;
}
STD_ReturnType Mcal_Rcc_EnablePeripheral(u8 copy_PeripheralId,u8 copy_BusId)
{
	STD_ReturnType local_functionStatus = E_NOT_OK;
	switch(copy_BusId)
	{
		case RCC_AHB:
			SET_BIT(RCC_AHBENR_R,copy_PeripheralId);
		  local_functionStatus = E_OK;
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR_R ,copy_PeripheralId);
		  local_functionStatus = E_OK;
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR_R ,copy_PeripheralId);
		  local_functionStatus = E_OK;
			break;
		default:
			local_functionStatus = E_NOT_OK;
			break;
	}
	return local_functionStatus;
}
STD_ReturnType Mcal_Rcc_DisablePeripheral(u8 copy_PeripheralId,u8 copy_BusId)
{
	STD_ReturnType local_functionStatus = E_NOT_OK;
	switch(copy_BusId)
	{
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR_R,copy_PeripheralId);
		  local_functionStatus = E_OK;
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR_R ,copy_PeripheralId);
		  local_functionStatus = E_OK;
			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR_R ,copy_PeripheralId);
		  local_functionStatus = E_OK;
			break;
		default:
			local_functionStatus = E_NOT_OK;
			break;
	}
	return local_functionStatus;
}