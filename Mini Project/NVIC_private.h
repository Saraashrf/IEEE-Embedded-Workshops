/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : NVIC_PRIVATE.h ******************/
/*******************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS 0xE000E100U

#define NVIC_ISER0  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x00)))
#define NVIC_ISER1  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x04)))
#define NVIC_ISER2 (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x08)))
	
#define NVIC_ICER0  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x80)))
#define NVIC_ICER1  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x84)))
#define NVIC_ICER2  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x88)))

#define NVIC_ISPR0  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x0100)))
#define NVIC_ISPR1  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x0104)))
#define NVIC_ISPR2  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x0108)))

#define NVIC_ICPR0  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x0180)))
#define NVIC_ICPR1  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x0184)))
#define NVIC_ICPR2  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x0188)))

#define NVIC_IABR0  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x0200)))
#define NVIC_IABR1 (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x0204)))
#define NVIC_IABR2  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0x0208)))

#define NVIC_STIR  (*((volatile u32 *)(NVIC_BASE_ADDRESS+ 0xE00)))
	
#define SCB_AIRCR  (*((volatile u32 *)(0XE000ED0C)))
	
#define NVIC_IPR_BASE_ADDRESS    ((volatile u8 *)0xE000E400) /**< INTERRUPT PRIORITY REGISTERS BASE ADDRESS */
	
#define _16GROUP_0SUB_PRIORITY 0x05FA0300
#define _8GROUP_2SUB_PRIORITY 0x05FA0400
#define _4GROUP_4SUB_PRIORITY 0x05FA0500
#define _2GROUP_8SUB_PRIORITY 0x05FA0600
#define _0GROUP_16SUB_PRIORITY 0x05FA0700

#endif /**<NVIC_PRIVATE_H*/