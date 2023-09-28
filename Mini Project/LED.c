/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 20 sep 2023 ******************/
/************ Version   : 0.1 **************************/
/******* File Name : LED_program.c     *****************/
/******************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "GPIO_interface.h"
#include "STK_interface.h"
/*****************************< HAL *****************************/
#include "LED.h"


STD_ReturnType HAL_LED_Init(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
	return(Mcal_Gpio_setPinMode(Copy_LedPortId,Copy_LedPinId,GPIO_OUTPUT_PP_2MGHZ));
}

STD_ReturnType HAL_LED_On(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
	return(Mcal_Gpio_setPinValue(Copy_LedPortId,Copy_LedPinId,GPI0_PIN_HIGH));
}

STD_ReturnType HAL_LED_Off(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
	return(Mcal_Gpio_setPinValue(Copy_LedPortId,Copy_LedPinId,GPI0_PIN_LOW));
}

STD_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
	u8 Local_PinValue;
	if(Mcal_Gpio_getPinValue(Copy_LedPortId,Copy_LedPinId,&Local_PinValue)==E_NOT_OK)
	{
		return E_NOT_OK;
	}
	
	
	if( Local_PinValue == GPI0_PIN_HIGH)
	{
		return(Mcal_Gpio_setPinValue(Copy_LedPortId,Copy_LedPinId,GPI0_PIN_LOW));
	}
	else
	{
		return(Mcal_Gpio_setPinValue(Copy_LedPortId,Copy_LedPinId,GPI0_PIN_HIGH));
	}
}

STD_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime)
{
	if(Mcal_Gpio_setPinValue(Copy_LedPortId,Copy_LedPinId,GPI0_PIN_HIGH)==E_NOT_OK)
		{
		return E_NOT_OK;
	  }
	if(MCAL_STK_SetDelay_ms(Copy_BlinkTime)==E_NOT_OK)
		{
		return E_NOT_OK;
	  }
	
		if(Mcal_Gpio_setPinValue(Copy_LedPortId,Copy_LedPinId,GPI0_PIN_LOW)==E_NOT_OK)
		{
		return E_NOT_OK;
	  }
		if(MCAL_STK_SetDelay_ms(Copy_BlinkTime)==E_NOT_OK)
		{
		return E_NOT_OK;
	  }
}

STD_ReturnType HAL_LED_BlinkTwice(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime)
{
    if(HAL_LED_BlinkOnce(Copy_LedPortId, Copy_LedPinId, Copy_BlinkTime) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    MCAL_STK_SetDelay_ms(Copy_BlinkTime);

    HAL_LED_BlinkOnce(Copy_LedPortId, Copy_LedPinId, Copy_BlinkTime);

    return E_OK;
}

