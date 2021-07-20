/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT_Types.h
 *       Module:  PORT.c
 *
 *  Description:  header file for PORT.c Module
 *
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/*Define the pins on each port*/
typedef uint32 Port_PinType;


/*Pin Mode type*/
typedef uint8 Port_PinModeType ;



/*Pin level type*/
typedef uint8 Port_PinLevelType ;
#define PORT_PIN_LOW														0
#define PORT_PIN_HIGH														1


/*Pin direction type*/
typedef uint8 Port_PinDirectionType ;
#define PORT_PIN_INPUT														0
#define PORT_PIN_OUTPUT														1

/*pin internal attach*/
typedef uint32 Port_PinInternalAttachType ;
#define PORT_PIN_PULLUP													0x510
#define PORT_PIN_PULLDOWN												0x514
#define PORT_PIN_OPEN_DRAIN											0x50C


/*Pin output current*/
typedef uint32 Port_PinOutputCurrentType ;
#define PORT_PIN_DR2R														0x500
#define PORT_PIN_DR4R														0x504
#define PORT_PIN_DR8R														0x508

/*Port configure type*/
typedef struct
{
    Port_PinType								PortPinNumber;
		Port_PinDirectionType				PortPinDirection;
    Port_PinModeType 						PortPinMode;
    Port_PinLevelType 					PortPinLevelValue;
    Port_PinInternalAttachType  PortPinInternalAttach;
    Port_PinOutputCurrentType   PortPinOutputCurrent;
} Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
Syntax          :
Description     :
Sync\Async      :
Reentrancy      :
Parameters (in) :
Parameters (out):
Return value:   :
*******************************************************************************/
#endif  /* PORT_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: PORT_Types.h
 *********************************************************************************************************************/
