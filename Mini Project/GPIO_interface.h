/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : GPIO_interface.h ******************/
/*******************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

STD_ReturnType Mcal_Gpio_setPinMode(u8 Copy_PortId,u8 Copy_PinId,u8 Copy_Mode);
STD_ReturnType Mcal_Gpio_setPinValue(u8 Copy_PortId,u8 Copy_PinId,u8 Copy_VALUE);
STD_ReturnType Mcal_Gpio_getPinValue(u8 Copy_PortId,u8 Copy_PinId,u8* Copy_VALUE);

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
#define GPIO_PIN8 8
#define GPIO_PIN9 9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15

#define GPIO_INPUT_ANALOG_MOD                0b0000
#define GPI0_INPUT_FLOATING_MOD              0b0100
#define GPIO_INPUT_PULL_UP_MOD               0b1000
#define GPIO_INPUT_PULL_DOWN_MOD             0b1000

#define GPIO_OUTPUT_PP_10MGHZ                0b0001 
#define GPIO_OUTPUT_OPEN_DRAIN_10MGHZ        0b0101
#define GPIO_OUTPUT_AF_PP_10MGHZ             0b0110
#define GPIO_OUTPUT_AF_OPEN_DRAIN_10MGHZ     0b0111

#define GPIO_OUTPUT_PP_2MGHZ                 0b0010
#define GPIO_OUTPUT_OPEN_DRAIN_2MGHZ         0b0110
#define GPIO_OUTPUT_AF_PP_2MGHZ              0b0110
#define GPIO_OUTPUT_AF_OPEN_DRAIN_2MGHZ      0b0110

#define GPIO_OUTPUT_PP_50MGHZ                0b0011
#define GPIO_OUTPUT_OPEN_DRAIN_50MGHZ        0b0111
#define GPIO_OUTPUT_AF_PP_50MGHZ             0b0111
#define GPIO_OUTPUT_AF_OPEN_DRAIN_50MGHZ     0b0111

#define GPI0_PIN_HIGH 1
#define GPI0_PIN_LOW  0

#endif /**<GPIO_INTERFACE_H*/