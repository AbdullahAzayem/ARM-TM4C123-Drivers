/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Cfg.h
 *       Module:  Gpt.c
 *  Description:  <Write File DESCRIPTION here>     
 *********************************************************************************************************************/
#ifndef GPT_CFG_H_
#define GPT_CFG_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*Timer width state
		1- GPT_CONCATENATED
		2- GPT_INDIVIDUAL
*/
#define GPT_TIMER_16_32_WIDTH_STATE						GPT_INDIVIDUAL
#define GPT_TIMER_32_64_WIDTH_STATE						GPT_INDIVIDUAL


/*Count direction:
	1- GPT_TIMER_COUNT_UP
	2- GPT_TIMER_COUNT_DOWN
*/
#define GPT_TIMER_COUNT_DIRECTION			GPT_TIMER_COUNT_DOWN
	

/*Snap shot mode state
	1- GPT_SNAPSHOT_ENABLE
	2- GPT_SNAPSHOT_DISABLE
*/
#define GPT_SNAPSHOT_STATE 					GPT_SNAPSHOT_DISABLE

#define GPT_ACTIVATED_CHANNELS_SIZE							1
#define GPT_TIMER_MAX_CHANNEL										12
/*Interrup gate
	GPT_INTERRUPT_ENABLE
	GPT_INTERRUPT_DISABLE	
*/
#define GPT_INTERRUPT_GATE					GPT_INTERRUPT_ENABLE


#define GPT_ENABLE 				1
#define GPT_DISABLE 			0
/*Predefine configuration
		1- GPT_ENABLE
		2- GPT_DISABLE
*/
#define GPT_PREDEF_TIMER_100US_32BIT		GPT_ENABLE
#define GPT_PREDEF_TIMER_1US_16BIT			GPT_ENABLE
#define GPT_PREDEF_TIMER_1US_32BIT			GPT_ENABLE
#define GPT_PREDEF_TIMER_1US_24BIT			GPT_ENABLE
#define GPT_PREDEF_TIMER_1US_32BIT			GPT_ENABLE
		

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/





#endif  /* Gpt_CFG_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Gpt_Cfg.h
 *********************************************************************************************************************/
