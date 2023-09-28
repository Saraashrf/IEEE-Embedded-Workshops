/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : GPIO_program.c ******************/
/*******************************************************/

/************** < LIB *********/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************** < MCAL *********/
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

STD_ReturnType Mcal_Gpio_setPinMode(u8 Copy_PortId,u8 Copy_PinId,u8 Copy_Mode)
{
	STD_ReturnType Local_FunctionStatus= E_NOT_OK;
	switch(Copy_PortId)
	{
		case GPIO_PORTA:
			if(Copy_PinId<8)
			{
				GPIO_GPIOA_CRL &= ~((0b1111)<<(4*Copy_PinId));
				GPIO_GPIOA_CRL |= (Copy_Mode<<(4*Copy_PinId));
				Local_FunctionStatus= E_OK;
			}
			else if (Copy_PinId<16)
			{
				GPIO_GPIOA_CRH &= ~((0b1111)<<(4*Copy_PinId));
				GPIO_GPIOA_CRH |= (Copy_Mode<<(4*Copy_PinId));
				Local_FunctionStatus= E_OK;
			}
			else
				Local_FunctionStatus= E_NOT_OK;
		break;
		case  GPIO_PORTB:
			if(Copy_PinId<8)
			{
				GPIO_GPIOB_CRL &= ~((0b1111)<<(4*Copy_PinId));
				GPIO_GPIOB_CRL |= (Copy_Mode<<(4*Copy_PinId));
				Local_FunctionStatus= E_OK;
			}
			else if (Copy_PinId<16)
			{
				GPIO_GPIOB_CRH &= ~((0b1111)<<(4*Copy_PinId));
				GPIO_GPIOB_CRH |= (Copy_Mode<<(4*Copy_PinId));
				Local_FunctionStatus= E_OK;
			}
			else
				Local_FunctionStatus= E_NOT_OK;
		break;
		case  GPIO_PORTC:
			if(Copy_PinId<8)
			{
				GPIO_GPIOC_CRL &= ~((0b1111)<<(4*Copy_PinId));
				GPIO_GPIOC_CRL |= (Copy_Mode<<(4*Copy_PinId));
				Local_FunctionStatus= E_OK;
			}
			else if (Copy_PinId<16)
			{
				GPIO_GPIOC_CRH &= ~((0b1111)<<(4*Copy_PinId));
				GPIO_GPIOC_CRH |= (Copy_Mode<<(4*Copy_PinId));
				Local_FunctionStatus= E_OK;
			}
			else
				Local_FunctionStatus= E_NOT_OK;
		break;
		default:
			Local_FunctionStatus= E_NOT_OK;
			break;
		
	}
	return Local_FunctionStatus;
}

STD_ReturnType Mcal_Gpio_setPinValue(u8 Copy_PortId,u8 Copy_PinId,u8 Copy_VALUE)
{
	STD_ReturnType Local_FunctionStatus= E_NOT_OK;
	switch(Copy_PortId)
	{
		case GPIO_PORTA:
			
			if(Copy_VALUE==GPI0_PIN_HIGH)
			{
				SET_BIT(GPIO_GPIOA_ODR,Copy_PinId);
				Local_FunctionStatus= E_OK;
			}
			else if(Copy_VALUE==GPI0_PIN_LOW)
			{
				CLR_BIT(GPIO_GPIOA_ODR,Copy_PinId);
				Local_FunctionStatus= E_OK;
			}
			else
				Local_FunctionStatus= E_NOT_OK;
			break;
		case GPIO_PORTB:
			if(Copy_VALUE==GPI0_PIN_HIGH)
			{
				SET_BIT(GPIO_GPIOB_ODR,Copy_PinId);
				Local_FunctionStatus= E_OK;
			}
			else if(Copy_VALUE==GPI0_PIN_LOW)
			{
				CLR_BIT(GPIO_GPIOB_ODR,Copy_PinId);
				Local_FunctionStatus= E_OK;
			}
			else
				Local_FunctionStatus= E_NOT_OK;
			break;
		case GPIO_PORTC:
			
			if(Copy_VALUE==GPI0_PIN_HIGH)
			{
				SET_BIT(GPIO_GPIOC_ODR,Copy_PinId);
				Local_FunctionStatus= E_OK;
			}
			else if(Copy_VALUE==GPI0_PIN_LOW)
			{
				CLR_BIT(GPIO_GPIOC_ODR,Copy_PinId);
				Local_FunctionStatus= E_OK;
			}
			else
				Local_FunctionStatus= E_NOT_OK;
			break;
		default:
			Local_FunctionStatus= E_NOT_OK;
			break;
	}
	return Local_FunctionStatus;
}

STD_ReturnType Mcal_Gpio_getPinValue(u8 Copy_PortId,u8 Copy_PinId,u8* Copy_VALUE)
{
	STD_ReturnType Local_FunctionStatus= E_NOT_OK;
	if(Copy_VALUE != NULL)
	{
		switch(Copy_PortId)
		{
			case GPIO_PORTA:
				*Copy_VALUE=GET_BIT(GPIO_GPIOA_IDR,Copy_PinId);
			  Local_FunctionStatus= E_OK;
				break;
			case GPIO_PORTB:
				*Copy_VALUE=GET_BIT(GPIO_GPIOB_IDR,Copy_PinId);
			  Local_FunctionStatus= E_OK;
				break;
			case GPIO_PORTC:
				*Copy_VALUE=GET_BIT(GPIO_GPIOC_IDR,Copy_PinId);
			  Local_FunctionStatus= E_OK;
				break;
			default:
				Local_FunctionStatus= E_NOT_OK;
			  break;
			
		}
	}
	else
	{
		Local_FunctionStatus= E_NOT_OK;
	}
	return Local_FunctionStatus;
}