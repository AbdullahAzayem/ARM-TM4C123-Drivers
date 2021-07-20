/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file      Wdt.c
 *         \brief     Microcontroller Driver
 *         \details   The Driver configure the watchdog timer
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "IntCtrl_Types.h"
#include "Wdt.h"
#include "Wdt_Cfg.h" 





/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define WDT_INTTYPE_OFFSET 				2
#define WDT_RESEN					0x00000002
#define WDT_INTEN					0x00000001
#define WDT_LOCK					0x00000001
#define WDT_UNLOCK					0x1ACCE551
#define WDT_WRC						31
#define WDT_WRC_BIT_MASK			0x80000000

#define WDT_INTERRUPT 		18


#define WDTLOCK(BASE_ADDRESS)			(*((volatile uint32*) (BASE_ADDRESS+WDT_WDTLOCK_OFFSET)))
#define WDTLOAD(BASE_ADDRESS)			(*((volatile uint32*) (BASE_ADDRESS+WDT_WDTLOAD_OFFSET)))
#define WDTCTL(BASE_ADDRESS)			(*((volatile uint32*) (BASE_ADDRESS+WDT_WDTCTL_OFFSET) ))


/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/*Pointer the notification function to use in interrupt service routine function*/
void (*NotificationEN_Ptr) (void) = NULL_PTR;

/*Maximum timeout to use in interrupt service routine function*/
static uint16 WdtMaxTimeout = 0; 


#define WDG_CTRL_CLOCK 			(uint32)16000000

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
	/*Error status*/
static Std_ReturnType global_StdReturnErrorStatus = E_OK;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
Syntax          :    Std_Return Wdt_Init(const Wdt_ConfigType * Wdt_ConfigPtr)                              
Description     :    initalize the wdt with initial condition and value
Sync\Async      : 
Reentrancy      : 
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
Std_ReturnType Wdt_Init(const Wdt_ConfigType* Wdt_ConfigPtr)
{
	/*Error status*/
	Std_ReturnType loc_StdReturnErrorStatus = E_OK;
	
	/*Check errors*/
	if((NULL_PTR != Wdt_ConfigPtr) && (NULL_PTR != (Wdt_ConfigPtr->NotificationEN))) /*Check null struct and notification function*/
	{	
		/*Set notification pointer to function*/
		NotificationEN_Ptr = Wdt_ConfigPtr->NotificationEN;
	
		/*Set the maximum time to use in interrupt service routine function*/
		WdtMaxTimeout = (Wdt_ConfigPtr->WdtMaxTimeout_ms);
		
		/*1- Set the value of preload*/
		WDTLOAD(WDT_BASE_ADDRESS) = ((Wdt_ConfigPtr->WdtInitialTimeout_ms));
		/*polling to synchronize with clock*/
		while( (0 == ((uint32)(WDTCTL(WDT1_BASE_ADDRESS)&WDT_WRC_BIT_MASK) >> WDT_WRC) ) && (WDT_BASE_ADDRESS==WDT1_BASE_ADDRESS));
		
		#if WDT_RESET_TRIGGER	== WDT_TRIGGER_STATE
				/*Set the reset enable*/
				WDTCTL(WDT_BASE_ADDRESS) |= WDT_RESEN;
		#endif
		
		/*polling to synchronize with clock*/
		while( (0 == ((WDTCTL(WDT1_BASE_ADDRESS)&WDT_WRC_BIT_MASK) >> WDT_WRC)) && (WDT_BASE_ADDRESS==WDT1_BASE_ADDRESS) );

		/*Interrupt enable*/
		WDTCTL(WDT_BASE_ADDRESS) |= WDT_INTEN;

		/*Set the interrupt type*/
		WDTCTL(WDT_BASE_ADDRESS) |= ((uint32)(Wdt_ConfigPtr->InterruptType)<< WDT_INTTYPE_OFFSET);

		/*TODO: Put interrupt in pending state*/
//		GetReg(CORTEXM4_PERI_BASE_ADDRESS,(INT_CTRL_PENDING_OFFSET+((INTCTRL_WATCHDOG_TIMER_0_AND_1/32)*4))) |= (uint32)1 <<INTCTRL_WATCHDOG_TIMER_0_AND_1;		
		
		/*Lock watchdog timer*/
		WDTLOCK(WDT_BASE_ADDRESS) = WDT_LOCK;			
	}
	else
	{
		loc_StdReturnErrorStatus = E_NOT_OK; /*Set an error*/
	}
	
	/*Return error status*/
	return loc_StdReturnErrorStatus;
}




/******************************************************************************
Syntax          :    void Wdt_SetTriggerCondition(uint16 Copy_uint16TimeoutVal);                           
Description     :    set the preload value
Sync\Async      : 
Reentrancy      : 
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
void Wdt_SetTriggerCondition(uint16 Copy_uint16TimeoutVal)
{
		
			/*Lock watchdog timer*/
			WDTLOCK(WDT_BASE_ADDRESS) = WDT_UNLOCK;	
			/*1- Set the value of preload*/
			WDTLOAD(WDT_BASE_ADDRESS) = (Copy_uint16TimeoutVal);
			
			while( (0 == ((WDTCTL(WDT1_BASE_ADDRESS)&WDT_WRC_BIT_MASK) >> WDT_WRC)) && (WDT_BASE_ADDRESS==WDT1_BASE_ADDRESS) );

			/*TODO: Put interrupt in pending state*/
//			GetReg(CORTEXM4_PERI_BASE_ADDRESS,(INT_CTRL_PENDING_OFFSET+((INTCTRL_WATCHDOG_TIMER_0_AND_1/32)*4))) |= (uint32)1 <<INTCTRL_WATCHDOG_TIMER_0_AND_1;		

			/*Lock watchdog timer*/
			WDTLOCK(WDT_BASE_ADDRESS) = WDT_LOCK;	
}


/******************************************************************************
Syntax          :    void WDT0_Handler(void)                              
Description     :    Function of interrupt service routine
Sync\Async      : 
Reentrancy      : 
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/

void WDT0_Handler(void) __attribute__((signal));
void WDT0_Handler(void) __attribute__((signal))
{
	static uint32 counter =0;
	(*((volatile uint32*)0x400FE61C)) = counter++;
	/*Check null pointer*/
	if(NULL_PTR != NotificationEN_Ptr)
	{
		NotificationEN_Ptr();
	}
	else
	{
		/*Set error status*/
		global_StdReturnErrorStatus = E_NOT_OK;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: Wdt.c
 *********************************************************************************************************************/
