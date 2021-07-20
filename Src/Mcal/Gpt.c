/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file      Gpt.c
 *         \brief     Microcontroller Driver
 *         \details   The Driver configure the general purpose timer
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpt_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt.h"
#include "Mcu_Hw.h"
#include "Std_Types.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define F_HEXA		0xF

#define GPT_BIT0	0
#define GPT_BIT1	1
#define GPT_BIT2	2
#define GPT_BIT3	3
#define GPT_BIT4	4
#define GPT_BIT5	5
#define GPT_BIT6	6
#define GPT_BIT7	7
#define GPT_BIT8	8
#define GPT_BIT9	9
#define GPT_BIT10	10
#define GPT_BIT11	11
#define GPT_BIT16	16

/*Hold on Value*/
#define GPT_HOLD_ON_VAL				1000u


/*Gpt timer disable*/
#define GPT_TIMER_DISABLE							0
#define GPT_TIMER_ENABLE							1

/*Start count enable*/
#define GPT_START_COUNT_ENABLE						1

/*System clock*/
#define GPT_SYSTEM_CLOCK		16000000u




/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/


static const Gpt_TimerChannel[GPT_TIMER_MAX_CHANNEL] = 
{
	_16_32_bit_Timer0	 			,
	_16_32_bit_Timer1     	,
  _16_32_bit_Timer2     	,
  _16_32_bit_Timer3     	,
  _16_32_bit_Timer4     	,
  _16_32_bit_Timer5     	,
	_32_64_bit_Wide_Timer0	,
	_32_64_bit_Wide_Timer1	,
	_32_64_bit_Wide_Timer2	,
	_32_64_bit_Wide_Timer3	,
	_32_64_bit_Wide_Timer4	,
	_32_64_bit_Wide_Timer5
};
  
  
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

static const Gpt_ConfigType *  global_Config;

/*typedef void (*PtrToFuncType) (void) ;*/

/*PtrToFuncType GptNotification[];*/

static void (*GptNotification[GPT_TIMER_MAX_CHANNEL]) (void);

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
Syntax          :   void Gpt_Init(const Gpt_ConfigType* ConfigPtr) 
Description     :    
Sync\Async      : 
Reentrancy      : 
Parameters (in) : 
Parameters (out):   
Return value    : 
*******************************************************************************/
Std_ReturnType Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
	/*Counter*/
	uint8 loc_Counter = 0 ;
	
	/*Error status*/
	Std_ReturnType loc_ErrorStatus = E_OK;
	
	/*Define Gpt Channel Id*/
	Gpt_ChannelType loc_ChannelId = 0;
	
	/*Define Gpt channel mode*/
	Gpt_ModeType loc_ChannelMode = 0;
	
	/*Tick frequency*/
	Gpt_ValueType loc_TickFrequency = 0 ;
	
	/*Tick maximum value*/
	Gpt_ValueType loc_TickValMax = 0;

	
	/*Gpt base address*/
	uint32 loc_GptBaseAddress = 0;
	
	
	/*Check null pointer*/
	if(NULL_PTR != ConfigPtr)
	{
		/*Point the configuration to global variable*/
		global_Config = ConfigPtr;
		
		for(loc_Counter = 0;loc_Counter < GPT_ACTIVATED_CHANNELS_SIZE;loc_Counter++)
		{
			/*Get the Gpt channel Id*/
			loc_ChannelId = ConfigPtr[loc_Counter].ChannelId;
			
			/*Get the channel mode*/
			loc_ChannelMode =ConfigPtr[loc_Counter].ChannelMode;
			
			/*Tick frequency type*/
			loc_TickFrequency = ConfigPtr[loc_Counter].ChannelTickFrequency;
			
			/*Set the maximum value*/
			loc_TickValMax = ConfigPtr[loc_Counter].ChannelTickValMax;
			
			/*Set the callback function*/
			GptNotification[loc_Counter] = ConfigPtr[loc_Counter].GptNotifcation;
			
			/*Set the Gtp base address*/
			loc_GptBaseAddress = (uint32)Gpt_TimerChannel[loc_ChannelId];
			
			
			if( (loc_ChannelId > 5) && (loc_ChannelId < 12) ) /*Wide Timer*/
			{
				/*Make sure that timer is disabled*/
				TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMCTL_OFFSET),GPT_BIT0) = GPT_TIMER_DISABLE;			
				
				
				switch(loc_ChannelMode)
				{
					case GPT_PERIODIC_TIMER_MODE:
					case GPT_ONESHOT_TIMER_MODE: 					
						#if GPT_TIMER_32_64_WIDTH_STATE == GPT_INDIVIDUAL
							/*Set the channel mode to be oneshot mode or periodic mode*/
							TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[loc_ChannelId]+GPT_GPTMTAMR_OFFSET),GPT_BIT0) = 0;
							TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[loc_ChannelId]+GPT_GPTMTAMR_OFFSET),GPT_BIT1) = 1;

							/*Set the state to be individual 0x4*/
							TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[loc_ChannelId]+GPT_GPTMCFG_OFFSET),GPT_BIT0) = 0;
							TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[loc_ChannelId]+GPT_GPTMCFG_OFFSET),GPT_BIT1) = 0;
							TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[loc_ChannelId]+GPT_GPTMCFG_OFFSET),GPT_BIT2) = 1;
							
							/*Define the counter direction up or down*/
							TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[loc_ChannelId]+GPT_GPTMTAMR_OFFSET),GPT_BIT4) = GPT_TIMER_COUNT_DIRECTION;
							
							/*Snap shot state*/
							TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[loc_ChannelId]+GPT_GPTMTAMR_OFFSET),GPT_BIT7) = GPT_SNAPSHOT_STATE;
									
					
							/*Load the initial value to preload register*/
							GetReg((uint32)Gpt_TimerChannel[loc_ChannelId],GPT_GPTMTAILR_OFFSET) = (loc_TickValMax*GPT_SYSTEM_CLOCK)/loc_TickFrequency;
							
							/*Disable all notifications*/
							Gpt_DisableNotification(loc_ChannelId);
						#elif GPT_TIMER_32_64_WIDTH_STATE == GPT_CONCATENATED
						#else 
							#error "Wrong configuration"
						#endif
					break;
					case GPT_CAPTURE_MODE:
					break;
					case GPT_PWM_TIMER_MODE:
					break;
					case GPT_RTC_TIMER_MODE:		
					break;
					default:
						/*Set error*/
						loc_ErrorStatus = E_NOT_OK;
					break;	
				}
			}
			else if(loc_ChannelId < 5) /*Timer 16-32 */
			{
			}
			else
			{
				/*Set error*/
				loc_ErrorStatus = E_NOT_OK;
			}		
		}
		
		/*Predefine configuration*/
		#if GPT_PREDEF_TIMER_100US_32BIT == GPT_ENABLE		
			/*Make sure that timer is disabled*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER0_32_64_BIT]+GPT_GPTMCTL_OFFSET),GPT_BIT0) = GPT_TIMER_DISABLE;			
							
			/*Set the channel mode to be oneshot mode or periodic mode*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER0_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT0) = 0;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER0_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT1) = 1;

			/*Set the state to be individual 0x4*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER0_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT0) = 0;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER0_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT1) = 0;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER0_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT2) = 1;
			
			/*Define the counter direction up or down*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER0_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT4) = GPT_TIMER_COUNT_DOWN;
			
			/*Snap shot state*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER0_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT7) = GPT_SNAPSHOT_STATE;
			
			/*Load the initial value to preload register*/
			GetReg((uint32)Gpt_TimerChannel[loc_ChannelId],GPT_GPTMTAILR_OFFSET) = 10000/GPT_SYSTEM_CLOCK;
	
			/*Disable all notifications*/
			Gpt_DisableNotification(GPT_WIDE_TIMER0_32_64_BIT);	
		#endif


		#if GPT_PREDEF_TIMER_1US_16BIT == GPT_ENABLE
			/*Make sure that timer is disabled*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_TIMER0_16_32_BIT]+GPT_GPTMCTL_OFFSET),GPT_BIT0) = GPT_TIMER_DISABLE;			
							
			/*Set the channel mode to be oneshot mode or periodic mode*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_TIMER0_16_32_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT0) = GPT_PERIODIC_TIMER_MODE;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_TIMER0_16_32_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT1) = GPT_PERIODIC_TIMER_MODE;

			/*Set the state to be individual 0x4*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_TIMER0_16_32_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT0) = 0;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_TIMER0_16_32_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT1) = 0;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_TIMER0_16_32_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT2) = 1;
			
			/*Define the counter direction up or down*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_TIMER0_16_32_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT4) = GPT_TIMER_COUNT_DOWN;
			
			/*Snap shot state*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_TIMER0_16_32_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT7) = GPT_SNAPSHOT_STATE;
			
			/*Load the initial value to preload register*/
			GetReg((uint32)Gpt_TimerChannel[loc_ChannelId],GPT_GPTMTAILR_OFFSET) = 1000000/GPT_SYSTEM_CLOCK;
			/*Disable all notifications*/
			Gpt_DisableNotification(GPT_TIMER0_16_32_BIT);			
		#endif
		
		
		
		#if GPT_PREDEF_TIMER_1US_24BIT == GPT_ENABLE
					/*Make sure that timer is disabled*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER1_32_64_BIT]+GPT_GPTMCTL_OFFSET),GPT_BIT0) = GPT_TIMER_DISABLE;			
							
			/*Set the channel mode to be oneshot mode or periodic mode*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER1_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT0) = GPT_PERIODIC_TIMER_MODE;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER1_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT1) = GPT_PERIODIC_TIMER_MODE;

			/*Set the state to be individual 0x4*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER1_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT0) = 0;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER1_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT1) = 0;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER1_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT2) = 1;
			
			/*Define the counter direction up or down*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER1_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT4) = GPT_TIMER_COUNT_DOWN;
			
			/*Snap shot state*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER1_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT7) = GPT_SNAPSHOT_STATE;
			
			/*Disable all notifications*/
			Gpt_DisableNotification(GPT_WIDE_TIMER1_32_64_BIT);	
		#endif
		
		#if GPT_PREDEF_TIMER_1US_32BIT == GPT_ENABLE
			/*Make sure that timer is disabled*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER2_32_64_BIT]+GPT_GPTMCTL_OFFSET),GPT_BIT0) = GPT_TIMER_DISABLE;			
							
			/*Set the channel mode to be oneshot mode or periodic mode*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER2_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT0) = GPT_PERIODIC_TIMER_MODE;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER2_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT1) = GPT_PERIODIC_TIMER_MODE;

			/*Set the state to be individual 0x4*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER2_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT0) = 0;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER2_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT1) = 0;
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER2_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT2) = 1;
			
			/*Define the counter direction up or down*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER2_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT4) = GPT_TIMER_COUNT_DOWN;
						/*Load the initial value to preload register*/
			GetReg((uint32)Gpt_TimerChannel[loc_ChannelId],GPT_GPTMTAILR_OFFSET) = 10000/GPT_SYSTEM_CLOCK;
			/*Snap shot state*/
			TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[GPT_WIDE_TIMER2_32_64_BIT]+GPT_GPTMTAMR_OFFSET),GPT_BIT7) = GPT_SNAPSHOT_STATE;
			
			/*Disable all notifications*/
			Gpt_DisableNotification(GPT_WIDE_TIMER2_32_64_BIT);			
		#endif
	}
	else
	{
		/*Set error*/
		loc_ErrorStatus = E_NOT_OK;
	}
	return loc_ErrorStatus;
}

/******************************************************************************
* \Syntax          : void Gpt_DisableNotification(Gpt_ChannelType ChannelId)        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType ChannelId)
{
	uint32 loc_GptBaseAddress;
	loc_GptBaseAddress = (uint32)Gpt_TimerChannel[ChannelId];
	
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT0) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT1) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT2) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT3) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT4) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT5) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT8) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT9) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT10) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT11) = GPT_INTERRUPT_DISABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT16) = GPT_INTERRUPT_DISABLE;
}
/******************************************************************************
* \Syntax          : void Gpt_EnableNotification(Gpt_ChannelType ChannelId);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType ChannelId)
{
	uint32 loc_GptBaseAddress;
	loc_GptBaseAddress = (uint32)Gpt_TimerChannel[ChannelId];
	
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT0) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT1) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT2) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT3) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT4) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT5) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT8) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT9) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT10) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT11) = GPT_INTERRUPT_ENABLE;
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMIMR_OFFSET),GPT_BIT16) = GPT_INTERRUPT_ENABLE;
}


/******************************************************************************
* \Syntax          : void Gpt_StartTimer(Gpt_ChannelType ChannelId,Gpt_ValueType Valeu);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType ChannelId,Gpt_ValueType Value)
{
		/*Counter*/
	uint8 loc_Counter = 0;
		/*Flag*/
	uint8 loc_Flag = 0;
	
	/*Tick frequency*/
	Gpt_ValueType loc_TickFrequency = 0; 
	
	/*Prescaler value*/
	uint8 loc_PrescalerVal = 0;
	
	/*base address*/
	uint32 loc_GptBaseAddress;
	
	loc_GptBaseAddress = (uint32)Gpt_TimerChannel[ChannelId];


	
	for(loc_Counter =0;(loc_Counter < GPT_TIMER_MAX_CHANNEL)&&(loc_Flag == 0);loc_Counter++)
	{
		
		if(global_Config[loc_Counter].ChannelId == ChannelId)
		{
			/*Get the tick frequency of the required channel*/
			loc_TickFrequency = global_Config[loc_Counter].ChannelTickFrequency;
			
			/*Set flag*/
			loc_Flag = 1;
		}
		else
		{
			
		}
	}
	/*Reset the flag*/
	loc_Flag = 0;
	/*Calculation of prescaler*/
	loc_PrescalerVal = (uint8)(GPT_SYSTEM_CLOCK/loc_TickFrequency);
	
	for(loc_Counter=2;(loc_Flag == 0);loc_Counter*=2)
	{
		if(loc_PrescalerVal/loc_Counter == 1)
		{
			if(loc_PrescalerVal%loc_Counter <= (loc_Counter/2))
			{
				loc_PrescalerVal = loc_Counter;
			}
			else
			{
				loc_PrescalerVal = loc_Counter*2;
			}
			loc_Flag = 1;
		}
	}
	
	/*Activate the prescaler extension*/
	/*Set the preload value*/
	GetReg(Gpt_TimerChannel[ChannelId],GPT_GPTMTAILR_OFFSET) = Value * loc_PrescalerVal;
	Gpt_EnableNotification(ChannelId);
	/*Start counting*/
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMCTL_OFFSET),GPT_BIT0) = GPT_TIMER_ENABLE;
}

/******************************************************************************
* \Syntax          : void Gpt_StopTimer(Gpt_ChannelType ChannelId);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType ChannelId)
{
	uint32 loc_GptBaseAddress;
	loc_GptBaseAddress = (uint32)Gpt_TimerChannel[ChannelId];
	
	/*Stop counting*/
	TIVAc_PERI_BIT_BAND_ALIASING((loc_GptBaseAddress+GPT_GPTMCTL_OFFSET),GPT_BIT0) = GPT_TIMER_DISABLE;
}



/******************************************************************************
* \Syntax          : void TIMER0A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void TIMER0A_Handler(void) __attribute__((used));
void TIMER0A_Handler(void)
{	
	if(GptNotification[0] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[0]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[0]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
	
}


/******************************************************************************
* \Syntax          : void TIMER1A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void TIMER1A_Handler(void) __attribute__((used));
void TIMER1A_Handler(void)
{
	
	if(GptNotification[1] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[1]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[1]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
	
}


/******************************************************************************
* \Syntax          : void TIMER2A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void TIMER2A_Handler(void) __attribute__((used));
void TIMER2A_Handler(void)
{	
	if(GptNotification[2] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[2]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[2]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
	
}

/******************************************************************************
* \Syntax          : void TIMER3A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void TIMER3A_Handler(void) __attribute__((used));
void TIMER3A_Handler(void)
{
	if(GptNotification[3] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[3]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[3]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
	
}


/******************************************************************************
* \Syntax          : void TIMER4A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void TIMER4A_Handler(void) __attribute__((used));
void TIMER4A_Handler(void)
{
	if(GptNotification[4] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[4]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[4]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
}


/******************************************************************************
* \Syntax          : void TIMER5A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void TIMER5A_Handler(void) __attribute__((used));
void TIMER5A_Handler(void)
{
	if(GptNotification[5] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[5]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[5]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
	
}


/******************************************************************************
* \Syntax          : void WTIMER0A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void WTIMER0A_Handler(void) __attribute__((used));
void WTIMER0A_Handler(void)
{
	if(GptNotification[6] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[6]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[6]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
	
}


/******************************************************************************
* \Syntax          : void WTIMER1A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void WTIMER1A_Handler(void) __attribute__((used));
void WTIMER1A_Handler(void)
{
	if(GptNotification[7] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[7]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[7]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
}


/******************************************************************************
* \Syntax          : void WTIMER2A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void WTIMER2A_Handler(void) __attribute__((used));
void WTIMER2A_Handler(void)
{
	if(GptNotification[8] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[8]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[8]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
	
}


/******************************************************************************
* \Syntax          : void WTIMER3A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void WTIMER3A_Handler(void) __attribute__((used));
void WTIMER3A_Handler(void)
{
	if(GptNotification[9] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[9]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[9]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
	
}


/******************************************************************************
* \Syntax          : void WTIMER4A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void WTIMER4A_Handler(void) __attribute__((used));
void WTIMER4A_Handler(void)
{	
	if(GptNotification[10] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[10]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[10]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
	
}


/******************************************************************************
* \Syntax          : void WTIMER5A_Handler(void);        
* \Description     :                                                                                                
* \Sync\Async      :           
* \Reentrancy      :           
* \Parameters (in) :                      
* \Parameters (out):           
* \Return value:   : 
*******************************************************************************/
void WTIMER5A_Handler(void) __attribute__((used));
void WTIMER5A_Handler(void)
{
	if(GptNotification[11] != NULL_PTR)
	{
		/*Call the funciton*/
		GptNotification[11]();
		
		/*Clear the flag*/
		TIVAc_PERI_BIT_BAND_ALIASING(((uint32)Gpt_TimerChannel[11]+GPT_GPTMRIS_OFFSET),GPT_BIT0) = 0;
	}
	else
	{
		
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/
