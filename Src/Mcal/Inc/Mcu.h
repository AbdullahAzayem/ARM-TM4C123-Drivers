/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu.h
 *       Module:  Mcu.c
 *
 *  Description:  header file for Mcu.c Module    
 *  
 *********************************************************************************************************************/
#ifndef MCU_H_
#define MCU_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Types.h"
#include "Mcu_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/					

#define MCU_CLOCK0 (uint8)0
#define MCU_CLOCK1 (uint8)1
#define MCU_CLOCK2 (uint8)2
#define MCU_CLOCK3 (uint8)3
#define MCU_CLOCK4 (uint8)4
#define MCU_CLOCK5 (uint8)5


/*MCU_PERFORM_RESET*/
#define	 MCU_RESET_ON 							0x0
#define  MCU_RESET_OFF							0x1


/*MCU_SYSCLK_DIV_STATE*/
#define MCU_SYSCLK_DIV_ENABLE		    1
#define MCU_SYSCLK_DIV_dISABLE		  0



/*Periperial gate*/
#define MCU_RUN_GATE_MODE_RCGCWD1					   0x01
#define MCU_RUN_GATE_MODE_RCGCWD0					   0x00
#define MCU_RUN_GATE_MODE_RCGCTIMER5				 0x15
#define MCU_RUN_GATE_MODE_RCGCTIMER4				 0x14
#define MCU_RUN_GATE_MODE_RCGCTIMER3				 0x13
#define MCU_RUN_GATE_MODE_RCGCTIMER2				 0x12
#define MCU_RUN_GATE_MODE_RCGCTIMER1				 0x11
#define MCU_RUN_GATE_MODE_RCGCTIMER0				 0x10
#define MCU_RUN_GATE_MODE_RCGCGPIOF					 0x25
#define MCU_RUN_GATE_MODE_RCGCGPIOE					 0x24
#define MCU_RUN_GATE_MODE_RCGCGPIOD					 0x23
#define MCU_RUN_GATE_MODE_RCGCGPIOC					 0x22
#define MCU_RUN_GATE_MODE_RCGCGPIOB					 0x21
#define MCU_RUN_GATE_MODE_RCGCGPIOA					 0x20
#define MCU_RUN_GATE_MODE_RCGCDMA					   0x30
#define MCU_RUN_GATE_MODE_RCGCHIB					   0x40
#define MCU_RUN_GATE_MODE_RCGCUART7          0x57
#define MCU_RUN_GATE_MODE_RCGCUART6          0x56
#define MCU_RUN_GATE_MODE_RCGCUART5          0x55
#define MCU_RUN_GATE_MODE_RCGCUART4          0x54
#define MCU_RUN_GATE_MODE_RCGCUART3          0x53
#define MCU_RUN_GATE_MODE_RCGCUART2          0x52
#define MCU_RUN_GATE_MODE_RCGCUART1          0x51
#define MCU_RUN_GATE_MODE_RCGCUART0          0x50
#define MCU_RUN_GATE_MODE_RCGCSSI3           0x63
#define MCU_RUN_GATE_MODE_RCGCSSI2           0x62
#define MCU_RUN_GATE_MODE_RCGCSSI1           0x61
#define MCU_RUN_GATE_MODE_RCGCSSI0           0x60
#define MCU_RUN_GATE_MODE_RCGCI2C3           0x73
#define MCU_RUN_GATE_MODE_RCGCI2C2           0x72
#define MCU_RUN_GATE_MODE_RCGCI2C1           0x71
#define MCU_RUN_GATE_MODE_RCGCI2C0           0x70
#define MCU_RUN_GATE_MODE_RCGCUSB            0x80
#define MCU_RUN_GATE_MODE_RCGCCAN1           0x91
#define MCU_RUN_GATE_MODE_RCGCCAN0           0x90
#define MCU_RUN_GATE_MODE_RCGCADC1           0xA1
#define MCU_RUN_GATE_MODE_RCGCADC0           0xA0
#define MCU_RUN_GATE_MODE_RCGCACMP           0xB0
#define MCU_RUN_GATE_MODE_RCGCPWM1           0xC1
#define MCU_RUN_GATE_MODE_RCGCPWM0           0xC0
#define MCU_RUN_GATE_MODE_RCGCQEI1           0xD1
#define MCU_RUN_GATE_MODE_RCGCQEI0           0xD0
#define MCU_RUN_GATE_MODE_RCGCEEPROM         0xE1
#define MCU_RUN_GATE_MODE_RCGCWTIMER5        0xF5
#define MCU_RUN_GATE_MODE_RCGCWTIMER4        0xF4
#define MCU_RUN_GATE_MODE_RCGCWTIMER3        0xF3
#define MCU_RUN_GATE_MODE_RCGCWTIMER2        0xF2
#define MCU_RUN_GATE_MODE_RCGCWTIMER1        0xF1
#define MCU_RUN_GATE_MODE_RCGCWTIMER0        0xF0

/*main oscilator cystal frequency not using PLL*/
#define MCU_CRYSTAL_FREQ_4MHZ 												0x06 
#define MCU_CRYSTAL_FREQ_4_096MHZ 										0x07 
#define MCU_CRYSTAL_FREQ_4_9152MHZ 										0x08 


/*main source clock frequency using PLL*/
#define MCU_CRYSTAL_FREQ_5MHZ 												0x09 
#define MCU_CRYSTAL_FREQ_5_12MHZ 											0x0A 
#define MCU_CRYSTAL_FREQ_6MHZ 												0x0B 
#define MCU_CRYSTAL_FREQ_6_144MHZ 										0x0C 
#define MCU_CRYSTAL_FREQ_7_3728MHZ 										0x0D 
#define MCU_CRYSTAL_FREQ_8MHZ 												0x0E 
#define MCU_CRYSTAL_FREQ_8_192MHZ 										0x0F 
#define MCU_CRYSTAL_FREQ_10MHZ 												0x10 
#define MCU_CRYSTAL_FREQ_12MHZ 												0x11 
#define MCU_CRYSTAL_FREQ_12_288MHZ 										0x12 
#define MCU_CRYSTAL_FREQ_13_56MHZ 										0x13 
#define MCU_CRYSTAL_FREQ_14_31818MHZ 									0x14 
#define MCU_CRYSTAL_FREQ_16MHZ 												0x15 
#define MCU_CRYSTAL_FREQ_16_384MHZ 										0x16 
#define MCU_CRYSTAL_FREQ_18MHZ 												0x17 
#define MCU_CRYSTAL_FREQ_20MHZ 												0x18 
#define MCU_CRYSTAL_FREQ_24MHZ 												0x19 
#define MCU_CRYSTAL_FREQ_25MHZ 												0x1A 

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
Syntax          : Mcu_PerformReset(void)                                      
Description     :  
Sync\Async      :   
Reentrancy      :   
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
void Mcu_PerformReset(void);
 
/******************************************************************************
Syntax          : Mcu_RawResetType Mcu_GetResetRawValue(void)                                      
Description     : To know the cause of reset action                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void);
 
/******************************************************************************
Syntax          : Mcu_PllStatusType Mcu_GetPllStatus(void)                                      
Description     : To get PLL use                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus( void);


/******************************************************************************
Syntax          :  void Mcu_Init(const Mcu_ConfigType* ConfigPtr,const uint8* Mcu_ConfigRunGateMode);                                       
Description     : To get PLL use                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/
/*void Mcu_Init(const Mcu_ConfigType* ConfigPtr,const uint8* Mcu_ConfigRunGateMode);*/
Std_ReturnType Mcu_Init(const Mcu_ConfigType* ConfigPtr);


 /******************************************************************************
Syntax          : Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)                                      
Description     : To Configure Mcu                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/
Std_ReturnType Mcu_InitClock(const uint8 ClockSetting[]);

 /******************************************************************************
Syntax          : Std_ReturnType Mcu_DistributePllClock( void)                                     
Description     : To Configure Mcu                                                            
Sync\Async      :                                            
Reentrancy      :                                            
Parameters (in) :           
Parameters (out):                                            
Return value:   : 
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock(void);

#endif  /* MCU_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu.h
 *********************************************************************************************************************/
