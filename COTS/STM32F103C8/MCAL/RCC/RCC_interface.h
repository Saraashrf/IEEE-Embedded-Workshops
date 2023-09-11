/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : RCC_interface.h ******************/
/*******************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB 0
#define RCC_APB1 1
#define RCC_APB2 2
STD_ReturnType Mcal_Rcc_InitClkSystem();
STD_ReturnType Mcal_Rcc_EnablePeripheral(u8 copy_PeripheralId,u8 copy_BusId);
STD_ReturnType Mcal_Rcc_DisablePeripheral(u8 copy_PeripheralId,u8 copy_BusId);

#endif /* RCC_INTERFACE_H */