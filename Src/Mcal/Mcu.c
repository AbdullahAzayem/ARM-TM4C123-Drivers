/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file      Mcu.c
 *         \brief     Microcontroller Driver
 *         \details   The Driver Configure All MCU reset and clock controls
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Mcu.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
/*APINT VECTKEY*/
#define APINT_VECTKEY 															0x05FA
/*APINT VECTKEY Field offset*/
#define APINT_VECTKEY_FIELD_OFFSET									16u

/*APINT SYSRESREQ Field offset*/
#define APINT_SYSRESREQ_FIELD_OFFSET								2u

/*PLL output divided by 2 When using the PLL, the VCO frequency of 400 MHz is predivided by 2 before the
divisor is applied.*/
#define MCU_PLL_DIV2 																200


/*Raw of resets*/
#define MCU_EXTERNAL_RESET													(uint32)1
#define MCU_POWER_ON_RESET	 												(uint32)2
#define MCU_BROWN_OUT_RESET									    		(uint32)4
#define MCU_WATCHDOG_TIMER0_RESET  									(uint32)8
#define MCU_SOFTWARE_RESET		   										(uint32)16
#define MCU_WATCHDOG_TIMER1_RESET  									(uint32)32
#define MCU_MOSC_FAILURE_RESET     									(uint32)65536

/*PLL Power Down*/
#define MCU_PLL_POWER_DOWN													13
/*Main oscilator disable*/
#define MCU_MAIN_OSCILLATOR_ENABLE									0
#define MCU_MAIN_OSCILLATOR_DISABLE									1

#define MCU_RCC_USESYSDIV 													22



/*Bypass value for PLL*/
#define MCU_BYPASS_STATE														 11


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static const Mcu_ConfigType* Mcu_ConfigTypePtr = NULL_PTR;
static Mcu_StatusType Mcu_Status = MCU_NOT_INITIALIZED;



/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define MCU_GET_PERIPHERAL_REG(RegNo) 				(*((volatile uint32*)(( (RegNo/16)*4 ) + 0x400FE600) ))
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Mcu_PerformReset(void)                                      
* \Description     :                                                              
* \Sync\Async      :                                            
* \Reentrancy      :                                            
* \Parameters (in) :           
* \Parameters (out):                                            
* \Return value:   : 
*******************************************************************************/

#if MCU_PERFORM_RESET == MCU_RESET_ON
void Mcu_PerformReset(void)
{
	/*System Reset*/
	APINT |= ( (APINT_VECTKEY << APINT_VECTKEY_FIELD_OFFSET) | ((uint32)1 << APINT_SYSRESREQ_FIELD_OFFSET) );		
	
	/*configure the reset type*/
	#if  MCU_RESET_TYPE == MCU_SYSTEM_RESET 
	#elif MCU_RESET_TYPE == MCU_PERIPHERAL_RESET
	#elif MCU_RESET_TYPE == MCU_CORE_RESET
	#else
		#error "Wrong Configuration"
	#endif
}
#endif


/******************************************************************************
Syntax          : Mcu_RawResetType Mcu_GetResetRawValue(void)                                      
Description     : To know the cause of reset action                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void)
{
	Mcu_RawResetType local_Mcu_RawResetVar = (Mcu_RawResetType)RESC ;
	
	/*Clear reset cause*/
	RESC = 0x0;
	
	return local_Mcu_RawResetVar;
}

/******************************************************************************
Syntax          : Mcu_PllStatusType Mcu_GetPllStatus(void)                                      
Description     : To get PLL use                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus( void)
{
	return (1 & PLLSTAT);
}

/******************************************************************************
Syntax          : void Mcu_Init( const Mcu_ConfigType* ConfigPtr)                                      
Description     : To Configure Mcu                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/
Std_ReturnType Mcu_Init(const Mcu_ConfigType* ConfigPtr)
{
	Std_ReturnType loc_StdReturnErrorStatus = E_OK;
	
	/*Check on null pointer, clock source, PLL_use, and MCU_freq*/
	if( (  NULL_PTR !=ConfigPtr                                                                         )		&& \
		  ( (ConfigPtr[MCU_CLOCK_SETTING_STAGE].Mcu_ClockSource >= MCU_MAIN_OSCILLATOR                    )   && \
			  (ConfigPtr[MCU_CLOCK_SETTING_STAGE].Mcu_ClockSource <= MCU_LOW_FREQUENCY_INTERNAL_OSCILLATOR  ) ) && \
      ( (ConfigPtr[MCU_CLOCK_SETTING_STAGE].MCU_Freq >= 12500) && \
				(ConfigPtr[MCU_CLOCK_SETTING_STAGE].MCU_Freq <= 66670)																					) && \
			(	(ConfigPtr[MCU_CLOCK_SETTING_STAGE].Mcu_PLLUse == MCU_PLL_ENABLE ) ||\
	      (ConfigPtr[MCU_CLOCK_SETTING_STAGE].Mcu_PLLUse == MCU_PLL_DISABLE)                              )
	)
	{			
			Mcu_ConfigTypePtr = ConfigPtr;  /*Callback mcu configuration*/ 
			Mcu_Status 				= MCU_INITIALIZED; 	/*Mcu initialized*/
	}
	else
	{
		/*Set an error status*/
		loc_StdReturnErrorStatus = E_NOT_OK;
	}

	return loc_StdReturnErrorStatus;
}
 
 
 /******************************************************************************
Syntax          : Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)                                     
Description     : To Configure Mcu                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/

Std_ReturnType Mcu_InitClock(const uint8 ClockSetting[])
{
	
		/*Counter*/
		uint8 loc_uint8Counter = 0;
		/*offset of gate peripheral register*/
		uint8 loc_uint8GateRegNo = 0;
		/*bit offset of gate peripheral register*/
		uint8 loc_uint8GateBitOffset = 0; 
		
		/*local oscilator frequency*/
		uint32 local_uint32SourceFreq_MHz=0;
	
		/*Error status*/
		Std_ReturnType local_Std_ReturnTypeErrorStatus = E_OK;

		if(MCU_INITIALIZED == Mcu_Status)
		{
				
				for(loc_uint8Counter=0;loc_uint8Counter < MCU_ACTIVATED_CLOCK_GATES_SIZE;loc_uint8Counter++)
				{
						/*Get the peripheral register number*/
						loc_uint8GateRegNo     = (ClockSetting[loc_uint8Counter])/16;
						/*Get the bit offset of the register*/
						loc_uint8GateBitOffset = (ClockSetting[loc_uint8Counter])%16;
					
						/*Set specific register for specific peripheral*/
						MCU_GET_PERIPHERAL_REG(loc_uint8GateRegNo) |= (uint32)1 << loc_uint8GateBitOffset;

				}				
				/*XTAL initialization*/
				RCC.B.XTAL = MCU_MAIN_OSCILLATOR_FREQ;
				
/**********************************************************************/								
/*															TODO Source Clock 									 */
				/*Clock source*/
				RCC.B.OSCSRC = Mcu_ConfigTypePtr[MCU_CLOCK_SETTING_STAGE].Mcu_ClockSource;
			
			
/**********************************************************************/				
/*												TODO System PLL USE													*/
				/*Check on PLL*/
				if(MCU_PLL_ENABLE == Mcu_ConfigTypePtr[MCU_CLOCK_SETTING_STAGE].Mcu_PLLUse)
				{
						/*Check on main oscilator value*/
						if ((MCU_MAIN_OSCILLATOR_FREQ >= MCU_CRYSTAL_FREQ_5MHZ) &&\
							  (MCU_MAIN_OSCILLATOR_FREQ <= MCU_CRYSTAL_FREQ_25MHZ)
						) 
						{
								/*Enable PLL*/
								RCC.B.PWRDN = 0;
							
								/*Set frequency when using PLL*/
								RCC.B.SYSDIV = ((MCU_PLL_DIV2/(Mcu_ConfigTypePtr[MCU_CLOCK_SETTING_STAGE].MCU_Freq/1000))-1);
								local_Std_ReturnTypeErrorStatus = Mcu_DistributePllClock(); /* Activate PLL */
						}
						else
						{
								local_Std_ReturnTypeErrorStatus = E_NOT_OK; 
						}
				}
				else
				{		

					if(MCU_LOW_FREQUENCY_INTERNAL_OSCILLATOR == Mcu_ConfigTypePtr[MCU_CLOCK_SETTING_STAGE].Mcu_ClockSource)
					{
							RCC.B.SYSDIV = MCU_LOW_FREQUENCY_INTERNAL_OSCILLATOR;
					}
					else
					{					
								if(MCU_MAIN_OSCILLATOR == Mcu_ConfigTypePtr[MCU_CLOCK_SETTING_STAGE].Mcu_ClockSource)
								{						
										if ((MCU_MAIN_OSCILLATOR_FREQ >= MCU_CRYSTAL_FREQ_4MHZ) &&\
											  (MCU_MAIN_OSCILLATOR_FREQ <= MCU_CRYSTAL_FREQ_4_9152MHZ )
										) 
										{
												/*main Oscillator enable*/
												RCC.B.MOSCDIS = MCU_MAIN_OSCILLATOR_ENABLE;
												
												/*Set cystal*/
												RCC.B.XTAL = MCU_MAIN_OSCILLATOR_FREQ;
												/*main oscilator value for System clock */
												local_uint32SourceFreq_MHz = 25;		
										}
										else
										{
												local_Std_ReturnTypeErrorStatus = E_NOT_OK; 
										}
								}
								else if(MCU_PRECISION_INTERNAL_OSCILLATOR == Mcu_ConfigTypePtr[MCU_CLOCK_SETTING_STAGE].Mcu_ClockSource)
								{
										local_uint32SourceFreq_MHz = 16;
								}
								else if(MCU_PRECISION_INTERNAL_OSCILLATOR_DEV4 == Mcu_ConfigTypePtr[MCU_CLOCK_SETTING_STAGE].Mcu_ClockSource)
								{
										local_uint32SourceFreq_MHz = 4 ;
								}
								else{}
					}
								RCC.B.SYSDIV = (MCU_PLL_DIV2/(Mcu_ConfigTypePtr[MCU_CLOCK_SETTING_STAGE].MCU_Freq/1000))-1;
				} 
		}
		else
		{	
			/*Set std error type*/
			local_Std_ReturnTypeErrorStatus = E_NOT_OK;
		}
	return local_Std_ReturnTypeErrorStatus;
}
 /******************************************************************************
Syntax          : Std_ReturnType Mcu_DistributePllClock( void)                                     
Description     : To Configure Mcu                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock(void) /*Activate the PLL*/
{
	Std_ReturnType local_stdReturnTypeErrorStatus = E_OK;
	
	/*Check that PLL is activated*/
	if( MCU_PLL_ENABLE == RCC.B.PWRDN)
	{
			/*Set PLL to be locked*/
			RCC.B.BYPASS = MCU_PLL_LOCKED;
			/*Polling on PLL*/
			while(MCU_PLL_LOCKED != Mcu_GetPllStatus()); 
	}
	else 
	{
			local_stdReturnTypeErrorStatus = E_NOT_OK;
	}
	return local_stdReturnTypeErrorStatus;
}

/**********************************************************************************************************************
 *  END OF FILE: Mcu.c
 *********************************************************************************************************************/
