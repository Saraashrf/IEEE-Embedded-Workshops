/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 18 sep 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : STK_config.h ******************/
/*******************************************************/
#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/** options: STK_CTRL_CLKSOURCE_1,STK_CTRL_CLKSOURCE_8 */
#define STK_CTRL_CLKSOURCE  STK_CTRL_CLKSOURCE_1  

/** options: STK_CTRL_TICKINT_ENABLE ,STK_CTRL_TICKINT_DISABLE  */
#define STK_CTRL_TICKINT    STK_CTRL_TICKINT_ENABLE     


#if  STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
    #define STK_AHB_CLK       8000000   /**< Processor clock (AHB clock) divided by 1 */
#elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
    #define STK_AHB_CLK       1000000   /**< Processor clock (AHB clock) divided by 8 */
#else
    #error "You chose a wrong clock source for the SysTick"
#endif

#endif /* STK_CONFIG_H */