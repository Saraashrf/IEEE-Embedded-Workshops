/***<LIB**/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/***<MCAL**/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"

/***<HAL*/
#include "LED.h"


#define CAR_RED 0
#define CAR_YELLOW 1
#define CAR_GREEN 2

u8 Car_Status = CAR_RED;

int main(void)
{
	/****************************< Setup *****************************/
	/**Init SysClk*/
	Mcal_Rcc_InitClkSystem();
	
	/**Enable Peripheral*/
	Mcal_Rcc_EnablePeripheral(2,RCC_APB2);
	Mcal_Rcc_EnablePeripheral(3,RCC_APB2);
	
	/**Init Gpio Pin*/
	Mcal_Gpio_setPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_INPUT_PULL_UP_MOD);
	
	HAL_LED_Init(GPIO_PORTA,GPIO_PIN2);
	HAL_LED_Init(GPIO_PORTA,GPIO_PIN3);
	HAL_LED_Init(GPIO_PORTA,GPIO_PIN4);
	
	HAL_LED_Init(GPIO_PORTB,GPIO_PIN2);
	HAL_LED_Init(GPIO_PORTB,GPIO_PIN3);
	HAL_LED_Init(GPIO_PORTB,GPIO_PIN4);
	
	/***Init button for interrupt*/
	MCAL_NVIC_EnableIRQ(7);
	EXTI_vInit();
	Mcal_Gpio_setPinValue(GPIO_PORTA,GPIO_PIN1,GPI0_PIN_HIGH);
	
	/****************************< Loop *****************************/
	for(;;)
	{
		/***<NORMAL MODE**/
		if(Car_Status == CAR_YELLOW)
		{
	     HAL_LED_Off(GPIO_PORTA,GPIO_PIN3);
		   HAL_LED_Off(GPIO_PORTB,GPIO_PIN3);
			
			 Car_Status = CAR_RED;
			
		   HAL_LED_On(GPIO_PORTA,GPIO_PIN2);
		   HAL_LED_On(GPIO_PORTB,GPIO_PIN4);
		
	     MCAL_STK_SetDelay_ms(500);
		}
		
		if(Car_Status == CAR_GREEN)
		{
	   	HAL_LED_Off(GPIO_PORTA,GPIO_PIN4);
	  	HAL_LED_Off(GPIO_PORTB,GPIO_PIN2);
			
			Car_Status = CAR_YELLOW;
			
	  	HAL_LED_On(GPIO_PORTA,GPIO_PIN3);
		  HAL_LED_On(GPIO_PORTB,GPIO_PIN3);
			
		  MCAL_STK_SetDelay_ms(500);
		}	
		
		if(Car_Status == CAR_RED)
		{
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN2);
      HAL_LED_Off(GPIO_PORTB,GPIO_PIN4);
	  	
			Car_Status = CAR_GREEN;

	  	HAL_LED_On(GPIO_PORTA,GPIO_PIN4);
      HAL_LED_On(GPIO_PORTB,GPIO_PIN2);
			
		  MCAL_STK_SetDelay_ms(500);
	}
 }
}

void EXTI1_IRQHandler(void)
{

	u32 i;
	u32 j;
	u8 Pin1_State;
	for(i=0;i<40000;i++);
	Mcal_Gpio_getPinValue(GPIO_PORTA,GPIO_PIN1,&Pin1_State);
	if(Pin1_State==1)
	{
		if(Car_Status == CAR_GREEN)
		{
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN4);
	  	HAL_LED_Off(GPIO_PORTB,GPIO_PIN2);

			
			for(i=0;i<5;i++)
			{
				HAL_LED_On(GPIO_PORTA,GPIO_PIN3);
		    HAL_LED_On(GPIO_PORTB,GPIO_PIN3);
				
				for(j=0;j<20000;j++);
				
				HAL_LED_Off(GPIO_PORTA,GPIO_PIN3);
		    HAL_LED_Off(GPIO_PORTB,GPIO_PIN3);
				
				for(j=0;j<20000;j++);
				
			}
			
			HAL_LED_On(GPIO_PORTA,GPIO_PIN2);
		  HAL_LED_On(GPIO_PORTB,GPIO_PIN4);
			
			for(i=0;i<213000;i++);
			
			Car_Status = CAR_RED;
			
		}	
		if(Car_Status == CAR_YELLOW)
		{
			for(i=0;i<5;i++)
			{
				HAL_LED_On(GPIO_PORTA,GPIO_PIN3);
		    HAL_LED_On(GPIO_PORTB,GPIO_PIN3);
				
				for(j=0;j<20000;j++);
				
				HAL_LED_Off(GPIO_PORTA,GPIO_PIN3);
		    HAL_LED_Off(GPIO_PORTB,GPIO_PIN3);
				
				for(j=0;j<20000;j++);
				
			}
			
			HAL_LED_On(GPIO_PORTA,GPIO_PIN2);
		  HAL_LED_On(GPIO_PORTB,GPIO_PIN4);
			
			for(i=0;i<213000;i++);
			
			Car_Status = CAR_RED;
			
		}
	}
}