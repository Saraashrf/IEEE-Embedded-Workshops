/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : NVIC_interface.h ******************/
/*******************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

typedef u8 IRQn_t;
STD_ReturnType MCAL_NVIC_xSetPriority(IRQn_t Copy_IRQn,u32 Copy_Priority);
STD_ReturnType MCAL_NVIC_EnableIRQ(IRQn_t Copy_IRQn);
STD_ReturnType MCAL_NVIC_DisableIRQ(IRQn_t Copy_IRQn);
STD_ReturnType MCAL_NVIC_GetPendingIRQ (IRQn_t Copy_IRQn, u8 *Copy_ReturnPendingFlag) ;
STD_ReturnType MCAL_NVIC_SetPendingIRQ (IRQn_t Copy_IRQn);
STD_ReturnType MCAL_NVIC_ClearPendingIRQ (IRQn_t Copy_IRQn);
STD_ReturnType MCAL_NVIC_GetActive(IRQn_t Copy_IRQn,u8 *Copy_ReturnActiveFlag);
STD_ReturnType MCAL_NVIC_vSetPriority(IRQn_t Copy_IRQn,u8 Copy_SubPriority, u8 Copy_GroupPriority);

#endif /**<NVIC_INTERFACE_H*/