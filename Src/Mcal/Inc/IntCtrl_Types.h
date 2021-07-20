/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  IntCtrl
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

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

/*INERRUPTS TYPES IN VECTOR TABLE*/
/*
    INTCTRL_RESET = 1,
    INTCTRL_NONMASKABLE_INTERRUPT,
    INTCTRL_HARD_FAULT,
    INTCTRL_MEMORY_MANAGEMENT,
    INTCTRL_BUS_FAULT,
	INTCTRL_USAGE_FAULT,
	INTCTRL_SV_CALL = 11,
	INTCTRL_DEBUG_MONITOR,
	INTCTRL_PEND_SV = 14,
	INTCTRL_SYS_TICK,
*/

typedef enum
{
	INTCTRL_GPIO_PORTA = 0,
	INTCTRL_GPIO_PORTB,
	INTCTRL_GPIO_PORTC,
	INTCTRL_GPIO_PORTD,
	INTCTRL_GPIO_PORTE,
	INTCTRL_UART0,
	INTCTRL_UART1,
	INTCTRL_SSI0,
	INTCTRL_I2C0,
	INTCTRL_PWM0_FAULT,
	INTCTRL_PWM0_GENERATOR0,
	INTCTRL_PWM0_GENERATOR1,
	INTCTRL_PWM0_GENERATOR2,
	INTCTRL_QEI0,
	INTCTRL_ADC0_SEQUENCE0,
	INTCTRL_ADC0_SEQUENCE1,
	INTCTRL_ADC0_SEQUENCE2,
	INTCTRL_ADC0_SEQUENCE3,
	INTCTRL_WATCHDOG_TIMER_0_AND_1,
	INTCTRL_16_32_BIT_TIMER0A,
	INTCTRL_16_32_BIT_TIMER0B,
	INTCTRL_16_32_BIT_TIMER1A,
	INTCTRL_16_32_BIT_TIMER1B,
	INTCTRL_16_32_BIT_TIMER2A,
	INTCTRL_16_32_BIT_TIMER2B,
	INTCTRL_ANALOG_COMPARATOR0,
	INTCTRL_ANALOG_COMPARATOR1,
	INTCTRL_SYSTEM_CONTROL = 44,
	INTCTRL_FLAH_MEMORY_AND_EEPROM_CONTROL,
	INTCTRL_GPIO_PORTF,
	INTCTRL_UART2 = 49,
	INTCTRL_SSI1,
	INTCTRL_16_32_BIT_TIMER3A,
	INTCTRL_16_32_BIT_TIMER3B,
	INTCTRL_I2C1,
	INTCTRL_QEI1,
	INTCTRL_CAN0,
	INTCTRL_CAN1,
	INTCTRL_HYPERNATION_MODULE= 59,
	INTCTRL_USB,
	INTCTRL_PWM_GENERATOR3,
	INTCTRL_UDMA_SOFTWARE,
	INTCTRL_UDMA_ERROR,
	INTCTRL_ADC1_SEQUENCE0,
	INTCTRL_ADC1_SEQUENCE1,
	INTCTRL_ADC1_SEQUENCE2,
	INTCTRL_ADC1_SEQUENCE3,
	INTCTRL_SSI2 = 73,
	INTCTRL_SSI3,
	INTCTRL_UART3,
	INTCTRL_UART4,
	INTCTRL_UART5,
	INTCTRL_UART6,
	INTCTRL_UART7,
  INTCTRL_I2C2 = 84,
	INTCTRL_I2C3,
	INTCTRL_16_32_BIT_TIMER4A,
	INTCTRL_16_32_BIT_TIMER4B,
	INTCTRL_16_32_BIT_TIMER5A =108,
	INTCTRL_16_32_BIT_TIMER5B,
	INTCTRL_32_64_BIT_TIMER0A,
	INTCTRL_32_64_BIT_TIMER0B,
	INTCTRL_32_64_BIT_TIMER1A,
	INTCTRL_32_64_BIT_TIMER1B,
	INTCTRL_32_64_BIT_TIMER2A,
	INTCTRL_32_64_BIT_TIMER2B,
	INTCTRL_32_64_BIT_TIMER3A,
	INTCTRL_32_64_BIT_TIMER3B,
	INTCTRL_32_64_BIT_TIMER4A,
	INTCTRL_32_64_BIT_TIMER4B,
	INTCTRL_32_64_BIT_TIMER5A,
	INTCTRL_32_64_BIT_TIMER5B,
	INTCTRL_SYSTEM_EXCEPTION_EMPRECISE,
	INTCTRL_PWM1_GENERATOR0 =150,
	INTCTRL_PWM1_GENERATOR1,
	INTCTRL_PWM1_GENERATOR2,
	INTCTRL_PWM1_GENERATOR3,
	INTCTRL_PWM1_FAULT,	
}IntCtrl_InterruptType;


#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
