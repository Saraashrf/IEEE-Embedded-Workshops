/*******************************************************/
/************ Author    : Sara Ashraf Abdelhakam *******/
/************ Date      : 20 sep 2023 ******************/
/************ Version   : 0.1 **************************/
/************ File Name : LED_interface.h ******************/
/*******************************************************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef enum {
    LED_PORTA, /**< Port A */ 
    LED_PORTB, /**< Port B */
    LED_PORTC  /**< Port C */
} LED_Port_t;

typedef enum {
    LED_PIN0,  /**< Pin 0 */ 
    LED_PIN1,  /**< Pin 1 */
    LED_PIN2,  /**< Pin 2 */
    LED_PIN3,  /**< Pin 3 */
    LED_PIN4,  /**< Pin 4 */
    LED_PIN5,  /**< Pin 5 */
    LED_PIN6,  /**< Pin 6 */
    LED_PIN7,  /**< Pin 7 */
    LED_PIN8,  /**< Pin 8 */
    LED_PIN9,  /**< Pin 9 */
    LED_PIN10, /**< Pin 10 */
    LED_PIN11, /**< Pin 11 */
    LED_PIN12, /**< Pin 12 */
    LED_PIN13, /**< Pin 13 */
    LED_PIN14, /**< Pin 14 */
    LED_PIN15, /**< Pin 15 */ 
} LED_Pin_t;

typedef f32 LED_Delay_ms_t;

STD_ReturnType HAL_LED_Init(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

STD_ReturnType HAL_LED_On(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

STD_ReturnType HAL_LED_Off(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

STD_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId);

STD_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime);

STD_ReturnType HAL_LED_BlinkTwice(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime);

#endif /**< LED_INTERFACE_H_ */