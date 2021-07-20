/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "Std_Types.h"
#include "IntCtrl_Types.h"
#include "IntCtrl_Cfg.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
typedef struct
{
	IntCtrl_InterruptType IntCtrl_InterruptNumber;
	uint8 IntCtrl_InterruptGroup;
	uint8 IntCtrl_InterruptSubGroup;
	
}IntCtrl_InterruptConfigType;

const IntCtrl_InterruptConfigType IntCtrl_InterruptState[INTCTRL_ACTIVE_GROUP_NUMBER] = 
{	/*Interrupt number                                   interrupt group      Interrupt subgroup*/
	{INTCTRL_WATCHDOG_TIMER_0_AND_1,  												2									,			 0},
	{INTCTRL_FLAH_MEMORY_AND_EEPROM_CONTROL		 ,  						2									,			 0}
		
};




/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
