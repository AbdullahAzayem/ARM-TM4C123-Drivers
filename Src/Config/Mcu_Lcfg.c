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

#include "Mcu_Cfg.h"
#include "Mcu_Types.h"
#include "Mcu.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


const Mcu_ConfigType Mcu_State[MCU_COFIG_TYPES_SIZE] = 
{
																			/*Clock Source         							PLL USE      			Frequency*/
		/*MCU_CLOCK0*/										{MCU_PRECISION_INTERNAL_OSCILLATOR, MCU_PLL_ENABLE 		, 12500},
		/*MCU_CLOCK1*/										{MCU_PRECISION_INTERNAL_OSCILLATOR, MCU_PLL_DISABLE   , 20000}
};

/*MCU_RUN_GATE_MODE:
		MCU_RUN_GATE_MODE_RCGCWD1	
		MCU_RUN_GATE_MODE_RCGCWD0	
		MCU_RUN_GATE_MODE_RCGCTIMER5
		MCU_RUN_GATE_MODE_RCGCTIMER4
		MCU_RUN_GATE_MODE_RCGCTIMER3
		MCU_RUN_GATE_MODE_RCGCTIMER2
		MCU_RUN_GATE_MODE_RCGCTIMER1
		MCU_RUN_GATE_MODE_RCGCTIMER0
		MCU_RUN_GATE_MODE_RCGCGPIOF	
		MCU_RUN_GATE_MODE_RCGCGPIOE	
		MCU_RUN_GATE_MODE_RCGCGPIOD	
		MCU_RUN_GATE_MODE_RCGCGPIOC	
		MCU_RUN_GATE_MODE_RCGCGPIOB	
		MCU_RUN_GATE_MODE_RCGCGPIOA	
		MCU_RUN_GATE_MODE_RCGCDMA	
		MCU_RUN_GATE_MODE_RCGCHIB	
		MCU_RUN_GATE_MODE_RCGCUART7  
		MCU_RUN_GATE_MODE_RCGCUART6  
		MCU_RUN_GATE_MODE_RCGCUART5  
		MCU_RUN_GATE_MODE_RCGCUART4  
		MCU_RUN_GATE_MODE_RCGCUART3  
		MCU_RUN_GATE_MODE_RCGCUART2  
		MCU_RUN_GATE_MODE_RCGCUART1  
		MCU_RUN_GATE_MODE_RCGCUART0  
		MCU_RUN_GATE_MODE_RCGCSSI3   
		MCU_RUN_GATE_MODE_RCGCSSI2   
		MCU_RUN_GATE_MODE_RCGCSSI1   
		MCU_RUN_GATE_MODE_RCGCSSI0   
		MCU_RUN_GATE_MODE_RCGCI2C3   
		MCU_RUN_GATE_MODE_RCGCI2C2   
		MCU_RUN_GATE_MODE_RCGCI2C1   
		MCU_RUN_GATE_MODE_RCGCI2C0   
		MCU_RUN_GATE_MODE_RCGCUSB    
		MCU_RUN_GATE_MODE_RCGCCAN1   
		MCU_RUN_GATE_MODE_RCGCCAN0   
		MCU_RUN_GATE_MODE_RCGCADC1   
		MCU_RUN_GATE_MODE_RCGCADC0   
		MCU_RUN_GATE_MODE_RCGCACMP   
		MCU_RUN_GATE_MODE_RCGCPWM1   
		MCU_RUN_GATE_MODE_RCGCPWM0   
		MCU_RUN_GATE_MODE_RCGCQEI1   
		MCU_RUN_GATE_MODE_RCGCQEI0   
		MCU_RUN_GATE_MODE_RCGCEEPROM 
		MCU_RUN_GATE_MODE_RCGCWTIMER5
		MCU_RUN_GATE_MODE_RCGCWTIMER4
		MCU_RUN_GATE_MODE_RCGCWTIMER3
		MCU_RUN_GATE_MODE_RCGCWTIMER2
		MCU_RUN_GATE_MODE_RCGCWTIMER1
		MCU_RUN_GATE_MODE_RCGCWTIMER0
*/
const uint8 Mcu_PeripheralState[MCU_ACTIVATED_CLOCK_GATES_SIZE]=
{
			/* Peripherals*/
			MCU_RUN_GATE_MODE_RCGCWD0  ,
			MCU_RUN_GATE_MODE_RCGCEEPROM  ,
			MCU_RUN_GATE_MODE_RCGCGPIOB,	
			MCU_RUN_GATE_MODE_RCGCGPIOA,
			MCU_RUN_GATE_MODE_RCGCWTIMER0
};
/**********************************************************************************************************************
 *  END OF FILE: Mcu_Lcfg.c
 *********************************************************************************************************************/
