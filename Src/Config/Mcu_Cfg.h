/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_CFG_H_
#define MCU_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 /*MCU_CLOCK_SETTING_STAGE:
				MCU_CLOCK0
				MCU_CLOCK1
				MCU_CLOCK2
				MCU_CLOCK3
				MCU_CLOCK4
				MCU_CLOCK5
*/
#define MCU_CLOCK_SETTING_STAGE      MCU_CLOCK0
#define MCU_COFIG_TYPES_SIZE         2


/*MCU_PERFORM_RESET
		1- MCU_RESET_ON
		2- MCU_RESET_OFF
*/
#define MCU_PERFORM_RESET 						MCU_RESET_ON

/*MCU_RESET_TYPE: 
	1- MCU_CORE_RESET
	2- MCU_PERIPHERAL_RESET
	3- MCU_SYSTEM_RESET
*/
#define MCU_RESET_TYPE 								MCU_SYSTEM_RESET



/*MCU_PRECISION_INTERNAL_OSCILLATOR:
		1- MCU_MAIN_OSCILLATOR 					
		2- MCU_PRECISION_INTERNAL_OSCILLATOR 		
		3- MCU_PRECISION_INTERNAL_OSCILLATOR_DEV4
		4- MCU_LOW_FREQUENCY_INTERNAL_OSCILLATOR 
*/
#define MCU_OSCILLATOR_SOURCE					MCU_PRECISION_INTERNAL_OSCILLATOR


/*MCU_MAIN_OSCILLATOR_FREQ
	Without:	
		1-  MCU_CRYSTAL_FREQ_4MHZ 	
		2-  MCU_CRYSTAL_FREQ_4_096MHZ 
		3-  MCU_CRYSTAL_FREQ_4_9152MHZ 
	With PLL:	
		1-  MCU_CRYSTAL_FREQ_5MHZ 		
		2-  MCU_CRYSTAL_FREQ_5_12MHZ 		
		3-  MCU_CRYSTAL_FREQ_6MHZ 			
		4-  MCU_CRYSTAL_FREQ_6_144MHZ 	
		5-  MCU_CRYSTAL_FREQ_7_3728MHZ 	
		6-  MCU_CRYSTAL_FREQ_8MHZ 		
		7-  MCU_CRYSTAL_FREQ_8_192MHZ 	
		8-  MCU_CRYSTAL_FREQ_10MHZ 		
		9-  MCU_CRYSTAL_FREQ_12MHZ 		
		10- MCU_CRYSTAL_FREQ_12_288MHZ 	
		11- MCU_CRYSTAL_FREQ_13_56MHZ 	
		12- MCU_CRYSTAL_FREQ_14_31818MHZ 	
		13- MCU_CRYSTAL_FREQ_16MHZ 		
		14- MCU_CRYSTAL_FREQ_16_384MHZ 	
		15- MCU_CRYSTAL_FREQ_18MHZ 		
		16- MCU_CRYSTAL_FREQ_20MHZ 		
		17- MCU_CRYSTAL_FREQ_24MHZ 		
		18- MCU_CRYSTAL_FREQ_25MHZ 		
*/
#define MCU_MAIN_OSCILLATOR_FREQ 					MCU_CRYSTAL_FREQ_25MHZ		
	

/*MCU_SYSCLK_DIV_STATE 
		1- MCU_SYSCLK_DIV_ENABLE
		2- MCU_SYSCLK_DIV_dISABLE
*/
#define  MCU_SYSCLK_DIV_STATE 					MCU_SYSCLK_DIV_ENABLE

/*Peripheral numbers*/
#define  MCU_ACTIVATED_CLOCK_GATES_SIZE 									5 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#endif  /* MCU_CFG_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Mcu_Cfg.h
 *********************************************************************************************************************/
