/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 28 aug 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : NVIC_config.h ******************/
/*******************************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

#define NUMBER_OF_INTERRUPTS 81
#define MAXIMUM_PRIORITY 15

/**< your options : _16GROUP_0SUB_PRIORITY
                    _8GROUP_2SUB_PRIORITY
										_4GROUP_4SUB_PRIORITY
										_2GROUP_8SUB_PRIORITY
										_0GROUP_16SUB_PRIORITY
*/

#define PRIORITY_GROUPING _16GROUP_0SUB_PRIORITY

#endif /**<NVIC_CONFIG_H*/