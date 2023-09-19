/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 18 sep 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : STK_private.h ******************/
/*******************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_BASE_ADDRESS 0xE000E010

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_DefReg_t;

#define STK     ((STK_DefReg_t*)STK_BASE_ADDRESS)

/***<register bit mask**/
#define STK_CTRL_ENABLE_MASK             0X00000001
#define STK_CTRL_TICKINT_MASK            0X00000002
#define STK_CTRL_CLKSOURCE               0X00000004
#define STK_CTRL_COUNTFLAG_MASK          0x00010000

#define STK_CTRL_CLKSOURCE_1             1
#define STK_CTRL_CLKSOURCE_8             0

#define STK_CTRL_TICKINT_ENABLE          1
#define STK_CTRL_TICKINT_DISABLE         0

#if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
    #define STK_AHB_CLK       8000000   /**< Processor clock (AHB clock) divided by 1 */
#elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
    #define STK_AHB_CLK       1000000   /**< Processor clock (AHB clock) divided by 8 */
#else
    #error "You chose a wrong clock source for the SysTick"
#endif

#endif /* STK_PRIVATE_H */