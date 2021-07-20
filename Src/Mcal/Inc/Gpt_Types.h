/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Types.h
 *       Module:  Gpt.c
 *
 *  Description:  header file for Gpt.c Module
 *
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H_
#define GPT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPT_CONCATENATED							0x1
#define GPT_INDIVIDUAL							0x0



  
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
 
 /*Type for channel ID*/
typedef uint8 Gpt_ChannelType;
 
 /*Gpt_ChannelId*/
#define GPT_TIMER0_16_32_BIT					0x0
#define GPT_TIMER1_16_32_BIT					0x1
#define GPT_TIMER2_16_32_BIT					0x2
#define GPT_TIMER3_16_32_BIT					0x3
#define GPT_TIMER4_16_32_BIT					0x4
#define GPT_TIMER5_16_32_BIT					0x5
#define GPT_WIDE_TIMER0_32_64_BIT				0x6
#define GPT_WIDE_TIMER1_32_64_BIT				0x7
#define GPT_WIDE_TIMER2_32_64_BIT				0x8
#define GPT_WIDE_TIMER3_32_64_BIT				0x9
#define GPT_WIDE_TIMER4_32_64_BIT				0xA
#define GPT_WIDE_TIMER5_32_64_BIT				0xB



/*Mode type*/
typedef uint8 Gpt_ModeType;
#define GPT_ONESHOT_TIMER_MODE              0X1 
#define GPT_PERIODIC_TIMER_MODE             0X2
#define GPT_CAPTURE_MODE					GPT_EDGE_TIME_TIMER_MODE
#define GPT_RTC_TIMER_MODE					0x4
#define GPT_PWM_TIMER_MODE					0x5  

/*Capture mode states*/ 
#define GPT_EDGE_TIME_TIMER_MODE			0x03
#define GPT_EDGE_COUNT_TIMER_MODE			0x13
 
 
 
 /*Count direction*/
 #define GPT_TIMER_COUNT_UP					1
 #define GPT_TIMER_COUNT_DOWN               0
 
 
 /*Snap shot state*/
 #define GPT_SNAPSHOT_ENABLE				1
 #define GPT_SNAPSHOT_DISABLE				0
 
 
 /*Interrupt stateus*/
 #define GPT_INTERRUPT_ENABLE				1
 #define GPT_INTERRUPT_DISABLE				0
 
	
 

/*Value type*/
typedef uint32 Gpt_ValueType; 
 /*Structure of configuration*/
typedef struct 
{
	Gpt_ChannelType ChannelId;
	Gpt_ModeType	ChannelMode;
	Gpt_ValueType 	ChannelTickFrequency;
	Gpt_ValueType 	ChannelTickValMax;
	void 			(*GptNotifcation)(void);
}Gpt_ConfigType;



#endif  /* GPT_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Types.h
 *********************************************************************************************************************/
