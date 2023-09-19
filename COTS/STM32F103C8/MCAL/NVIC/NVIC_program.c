/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : NVIC_program.c ******************/
/*******************************************************/

/************** < LIB *********/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************** < MCAL *********/
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

STD_ReturnType MCAL_NVIC_EnableIRQ(IRQn_t Copy_IRQn)
{
	STD_ReturnType Local_FunctionStatus = E_NOT_OK;
	if(Copy_IRQn < 32)
	{
		NVIC_ISER0=(1<<Copy_IRQn);
		Local_FunctionStatus=E_OK;
	}
	else if (Copy_IRQn < 64)
	{
		NVIC_ISER1=(1<<(Copy_IRQn-32));
		Local_FunctionStatus=E_OK;
	}
	else if(Copy_IRQn < 96)
	{
		NVIC_ISER2=(1<<(Copy_IRQn-64));
		Local_FunctionStatus=E_OK;
	}
	else
	{
		Local_FunctionStatus=E_NOT_OK;
	}
 return Local_FunctionStatus;
}


STD_ReturnType MCAL_NVIC_DisableIRQ(IRQn_t Copy_IRQn)
{
	STD_ReturnType Local_FunctionStatus = E_NOT_OK;
	if(Copy_IRQn < 32)
	{
		NVIC_ICER0=(1<<Copy_IRQn);
		Local_FunctionStatus=E_OK;
	}
	else if (Copy_IRQn < 64)
	{
		NVIC_ICER1=(1<<(Copy_IRQn-32));
		Local_FunctionStatus=E_OK;
	}
	else if(Copy_IRQn < 96)
	{
		NVIC_ICER2=(1<<(Copy_IRQn-64));
		Local_FunctionStatus=E_OK;
	}
	else
	{
		Local_FunctionStatus=E_NOT_OK;
	}
 return Local_FunctionStatus;
}


STD_ReturnType MCAL_NVIC_SetPendingIRQ (IRQn_t Copy_IRQn)
{
	STD_ReturnType Local_FunctionStatus = E_NOT_OK;
	if(Copy_IRQn < 32)
	{
		NVIC_ISPR0=(1<<Copy_IRQn);
		Local_FunctionStatus=E_OK;
	}
	else if (Copy_IRQn < 64)
	{
		NVIC_ISPR1=(1<<(Copy_IRQn-32));
		Local_FunctionStatus=E_OK;
	}
	else if(Copy_IRQn < 96)
	{
		NVIC_ISPR2=(1<<(Copy_IRQn-64));
		Local_FunctionStatus=E_OK;
	}
	else
	{
		Local_FunctionStatus=E_NOT_OK;
	}
 return Local_FunctionStatus;
}


STD_ReturnType MCAL_NVIC_ClearPendingIRQ (IRQn_t Copy_IRQn)
{
	STD_ReturnType Local_FunctionStatus = E_NOT_OK;
	if(Copy_IRQn < 32)
	{
		NVIC_ICPR0=(1<<Copy_IRQn);
		Local_FunctionStatus=E_OK;
	}
	else if (Copy_IRQn < 64)
	{
		NVIC_ICPR1=(1<<(Copy_IRQn-32));
		Local_FunctionStatus=E_OK;
	}
	else if(Copy_IRQn < 96)
	{
		NVIC_ICPR2=(1<<(Copy_IRQn-64));
		Local_FunctionStatus=E_OK;
	}
	else
	{
		Local_FunctionStatus=E_NOT_OK;
	}
 return Local_FunctionStatus;
}

STD_ReturnType MCAL_NVIC_GetPendingIRQ (IRQn_t Copy_IRQn, u8 *Copy_ReturnPendingFlag) 
{
		STD_ReturnType Local_FunctionStatus = E_NOT_OK;
	  if(Copy_ReturnPendingFlag != NULL)
		{
			 if(Copy_IRQn < 32)
	     {
		     if(GET_BIT(NVIC_ISPR0,Copy_IRQn))
				 {
					 *Copy_ReturnPendingFlag=1;
				 }
				 else
				 {
					 *Copy_ReturnPendingFlag=0;
				 }
		     Local_FunctionStatus=E_OK;
	     }
	    else if (Copy_IRQn < 64)
	     {
		     if(GET_BIT(NVIC_ISPR1,(Copy_IRQn-32)))
				 {
					 *Copy_ReturnPendingFlag=1;
				 }
				 else
				 {
					 *Copy_ReturnPendingFlag=0;
				 }
		     Local_FunctionStatus=E_OK;
	
	     }
	   else if(Copy_IRQn < 96)
	     {
	    	if(GET_BIT(NVIC_ISPR2,(Copy_IRQn-64)))
				 {
					 *Copy_ReturnPendingFlag=1;
				 }
				 else
				 {
					 *Copy_ReturnPendingFlag=0;
				 }
		     Local_FunctionStatus=E_OK;
	     }
		    
	   else
	     {
		    Local_FunctionStatus=E_NOT_OK;
	     }  
		  }
		else
		{
			Local_FunctionStatus=E_NOT_OK;
		}
		 return Local_FunctionStatus;
}


STD_ReturnType MCAL_NVIC_GetActive (IRQn_t Copy_IRQn,u8 *Copy_ReturnActiveFlag)
{
	STD_ReturnType Local_FunctionStatus = E_NOT_OK;
	  if(Copy_ReturnActiveFlag != NULL)
		{
			 if(Copy_IRQn < 32)
	     {
		     if(GET_BIT(NVIC_IABR0,Copy_IRQn))
				 {
					 *Copy_ReturnActiveFlag=1;
				 }
				 else
				 {
					 *Copy_ReturnActiveFlag=0;
				 }
		     Local_FunctionStatus=E_OK;
	     }
	    else if (Copy_IRQn < 64)
	     {
		     if(GET_BIT(NVIC_IABR1,(Copy_IRQn-32)))
				 {
					 *Copy_ReturnActiveFlag=1;
				 }
				 else
				 {
					 *Copy_ReturnActiveFlag=0;
				 }
		     Local_FunctionStatus=E_OK;
	
	     }
	   else if(Copy_IRQn < 96)
	     {
	    	if(GET_BIT(NVIC_IABR2,(Copy_IRQn-64)))
				 {
					 *Copy_ReturnActiveFlag=1;
				 }
				 else
				 {
					 *Copy_ReturnActiveFlag=0;
				 }
		     Local_FunctionStatus=E_OK;
	     }
		    
	   else
	     {
		    Local_FunctionStatus=E_NOT_OK;
	     }  
		  }
		else
		{
			Local_FunctionStatus=E_NOT_OK;
		}
		 return Local_FunctionStatus;
}

STD_ReturnType MCAL_NVIC_xSetPriority(IRQn_t Copy_IRQn,u32 Copy_Priority)
{
	STD_ReturnType Local_FunctionStatus = E_NOT_OK;
	if((Copy_IRQn <= NUMBER_OF_INTERRUPTS) && (Copy_Priority <= MAXIMUM_PRIORITY))
	{

		NVIC_IPR_BASE_ADDRESS[Copy_IRQn]=(Copy_Priority<<4);
		SCB_AIRCR= _0GROUP_16SUB_PRIORITY;
		Local_FunctionStatus=E_OK;
	}
	else
	{
		Local_FunctionStatus=E_NOT_OK;
	}
	 return Local_FunctionStatus;
}

STD_ReturnType MCAL_NVIC_vSetPriority(IRQn_t Copy_IRQn,u8 Copy_SubPriority, u8 Copy_GroupPriority)
{
	STD_ReturnType Local_FunctionStatus = E_NOT_OK;
	#if (PRIORITY_GROUPING ==  _16GROUP_0SUB_PRIORITY || PRIORITY_GROUPING ==  _8GROUP_2SUB_PRIORITY || PRIORITY_GROUPING ==  _4GROUP_4SUB_PRIORITY|| PRIORITY_GROUPING ==  _2GROUP_8SUB_PRIORITY || PRIORITY_GROUPING ==  _0GROUP_16SUB_PRIORITY)
    SCB_AIRCR= PRIORITY_GROUPING;
		u8 Local_Priority = (Copy_SubPriority | (Copy_GroupPriority << (PRIORITY_GROUPING -  _16GROUP_0SUB_PRIORITY)/0x100));
		NVIC_IPR_BASE_ADDRESS[Copy_IRQn]=(Local_Priority<<4);
	  Local_FunctionStatus=E_OK;
	#else
	 #error "error"
	#endif /**<PRIORITY_GROUPING*/
	return Local_FunctionStatus;
}