/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 18 sep 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : STK_interface.h ******************/
/*******************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void STK_Init(u32 Copy_Ticks);
void STK_Start(void);
void STK_Stop(void);
void STK_Reset(void);
u32 STK_GetRemainingCounts(void);
u32 STK_GetElapsedCounts(void);
Std_ReturnType STK_SetBusyWait(u32 Copy_Microseconds);
Std_ReturnType STK_SetDelay_ms(f32 Copy_Milliseconds);



#endif /* STK_INTERFACE_H */