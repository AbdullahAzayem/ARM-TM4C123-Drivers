/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_TYPES.h
 *       Module:  Mcu.c
 *
 *  Description:  header file for Mcu.c Module    
 *  
 *********************************************************************************************************************/
#ifndef MCU_TYPES_H_
#define MCU_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*Mcu config type*/
typedef struct
{
	uint8 Mcu_ClockSource;
	uint8 Mcu_PLLUse;
	uint32 MCU_Freq;
}Mcu_ConfigType;


/*ClockType setting*/
typedef struct 
{
	/*Peripheral Clock Gate*/
	uint8 Mcu_PeripheralControlGate;
}Mcu_ClockType;




/*MCU Clock Source*/
typedef uint8 Mcu_ClockSource; 
#define MCU_MAIN_OSCILLATOR 																0x0
#define MCU_PRECISION_INTERNAL_OSCILLATOR 									0x1
#define MCU_PRECISION_INTERNAL_OSCILLATOR_DEV4   						0x2
#define MCU_LOW_FREQUENCY_INTERNAL_OSCILLATOR 							0x3


/*MCU Reset Type*/					 														
typedef uint8  Mcu_RawResetType;
#define MCU_CORE_RESET 																			1
#define MCU_PERIPHERAL_RESET 																2
#define MCU_SYSTEM_RESET 																		3


/*PLL Status type*/
typedef uint8  Mcu_PllStatusType;
#define MCU_PLL_LOCKED					0x0
#define MCU_PLL_NOT_LOCKED			0x1	


/*Mcu Status*/
typedef uint8  Mcu_StatusType;
#define MCU_NOT_INITIALIZED 				0x0
#define MCU_INITIALIZED			 				0x1


/*Mcu availability*/
typedef uint8 Mcu_PLLConditionType;
#define MCU_PLL_ENABLE							0x0
#define MCU_PLL_DISABLE							0x1	










#endif  /* MCU_TYPES_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Mcu.h
 *********************************************************************************************************************/
