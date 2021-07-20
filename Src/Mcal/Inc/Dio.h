/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio.c
 *
 *  Description:  header file for Dio.c Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/					
#define DIO_PORTA_APB				0
#define DIO_PORTB_APB				1
#define DIO_PORTC_APB				2
#define DIO_PORTD_APB				3
#define DIO_PORTE_APB				4
#define DIO_PORTF_APB				5
#define DIO_PORTA_AHB				6
#define DIO_PORTB_AHB				7
#define DIO_PORTC_AHB				8
#define DIO_PORTD_AHB				9
#define DIO_PORTE_AHB				10
#define DIO_PORTF_AHB				11

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
Syntax          :   DioPinLevelType Dio_ReadChannel(DioChannelType ChannelID)                               
Description     :   read the value of digital pin
Sync\Async      :   
Reentrancy      :   
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
DioPinLevelType Dio_ReadChannel(DioChannelType ChannelID);

/******************************************************************************
Syntax          :  void Dio_WriteChannel(DioChannelType Channel,DioPinLevelType ChannelLevel);
Description     :   set the value of digital pin
Sync\Async      :   
Reentrancy      :   
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
void Dio_WriteChannel(DioChannelType ChannelID,DioPinLevelType ChannelLevel);

/******************************************************************************
Syntax          :   DioPortLevelType Dio_ReadPort(DioPortType PortID);                           
Description     :   read the value of digital port
Sync\Async      :   
Reentrancy      :   
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
DioPortLevelType Dio_ReadPort(DioPortType PortID);


/******************************************************************************
Syntax          :   void Dio_WritePort (DioPortType ChannelPort, DioPortLevelType ChannelLevel);                                
Description     :   read the value of digital port
Sync\Async      :   
Reentrancy      :   
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
void Dio_WritePort (DioPortType ChannelPort, DioPortLevelType ChannelLevel);

/******************************************************************************
Syntax          :   void GPIO_FlipChannel(DioChannelType Channel)                           
Description     :   read the value of digital port
Sync\Async      :   
Reentrancy      :   
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
void GPIO_FlipChannel(DioChannelType Channel);

#endif  /* GPIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu.h
 *********************************************************************************************************************/
