/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
*  GLOBAL FUNCTION LIKE MACROS
 *********************************************************************************************************************/
#define GetReg(PortOffset,RegOffset) 				(*((volatile uint32*)(PortOffset+RegOffset)))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/*Pin Mode type*/
#define PORT_DIO														0xF
#define PORT_AF_USB0ID											0x0
#define PORT_AF_USB0VBUS      							0x0
#define PORT_AF_AIN10         							0x0
#define PORT_AF_AIN11         							0x0
#define PORT_AF_C1_MINUS      							0x0
#define PORT_AF_C1_PLUS       							0x0
#define PORT_AF_C0_PLUS       							0x0
#define PORT_AF_C0_MINUS 	    							0x0
#define PORT_AF_AIN7          							0x0
#define PORT_AF_AIN6          							0x0
#define PORT_AF_AIN5          							0x0
#define PORT_AF_AIN4          							0x0
#define PORT_AF_USB0DM        							0x0
#define PORT_AF_USB0DP        							0x0
#define PORT_AF_AIN3          							0x0
#define PORT_AF_AIN2          							0x0
#define PORT_AF_AIN1          							0x0
#define PORT_AF_AIN0          							0x0
#define PORT_AF_AIN9          							0x0
#define PORT_AF_AIN8          							0x0
#define PORT_AF_U0R0												0x1	
#define PORT_AF_U0T1                        0x1
#define PORT_AF_U1R0                        0x1
#define PORT_AF_U1T1                        0x1
#define PORT_AF_TCK                         0x1
#define PORT_AF_SWCLK                       0x1
#define PORT_AF_TMS                         0x1
#define PORT_AF_SWDIO                       0x1
#define PORT_AF_TDI                         0x1
#define PORT_AF_TDO                         0x1
#define PORT_AF_SWO                         0x1
#define PORT_AF_U4R4                        0x1
#define PORT_AF_U4T5                        0x1
#define PORT_AF_U3R6                        0x1
#define PORT_AF_U3T7                        0x1
#define PORT_AF_SSI3Clk                     0x1
#define PORT_AF_SSI3Fss                     0x1
#define PORT_AF_SSI3Rx                      0x1
#define PORT_AF_SSI3Tx                      0x1
#define PORT_AF_U6R4                        0x1
#define PORT_AF_U6T5                        0x1
#define PORT_AF_U2R6                        0x1
#define PORT_AF_U2T7                        0x1
#define PORT_AF_U7R0                        0x1
#define PORT_AF_U7T1												0x1
#define PORT_AF_U5R4												0x1
#define PORT_AF_U5T5                        0x1
#define PORT_AF_U1RTS0                      0x1
#define PORT_AF_U1CTS1                      0x1
#define PORT_AF_SSI0Clk											0x2
#define PORT_AF_SSI0Fss                     0x2
#define PORT_AF_SSI0R4                      0x2
#define PORT_AF_SSI0T5                      0x2
#define PORT_AF_SSI2Clk                     0x2
#define PORT_AF_SSI2Fss                     0x2
#define PORT_AF_SSI2R6                      0x2
#define PORT_AF_SSI2T7                      0x2
#define PORT_AF_U1R4                        0x2
#define PORT_AF_U1T5                        0x2
#define PORT_AF_SSI1Clk                     0x2
#define PORT_AF_SSI1Fss                     0x2
#define PORT_AF_SSI1R2                      0x2
#define PORT_AF_SSI1T3                      0x2
#define PORT_AF_SSI1R0                      0x2
#define PORT_AF_SSI1T1                      0x2
#define PORT_AF_SSI1Clk                     0x2
#define PORT_AF_SSI1Fss                     0x2
#define PORT_AF_I2C1SCL											0x3
#define PORT_AF_I2C1SDA                     0x3
#define PORT_AF_I2C0SCL                     0x3
#define PORT_AF_I2C0SDA                     0x3
#define PORT_AF_I2C3SCL                     0x3
#define PORT_AF_I2C3SDA                     0x3
#define PORT_AF_I2C2SCL                     0x3
#define PORT_AF_I2C2SDA                     0x3
#define PORT_AF_CAN0R0                      0x3
#define PORT_AF_CAN0T3                      0x3
#define PORT_AF_M0PWM2											0x4
#define PORT_AF_M0PWM3                      0x4
#define PORT_AF_M0PWM0                      0x4
#define PORT_AF_M0PWM1                      0x4
#define PORT_AF_M0PWM6                      0x4
#define PORT_AF_M0PWM7                      0x4
#define PORT_AF_M0PWM6                      0x4
#define PORT_AF_M0PWM7                      0x4
#define PORT_AF_M0FAULT0                    0x4
#define PORT_AF_M0FAULT0                    0x4
#define PORT_AF_M0PWM4                      0x4
#define PORT_AF_M0PWM5                      0x4
#define PORT_AF_M0FAULT0                    0x4
#define PORT_AF_M1PWM2											0x5
#define PORT_AF_M1PWM3								      0x5
#define PORT_AF_M1PWM0                      0x5
#define PORT_AF_M1PWM1                      0x5
#define PORT_AF_M1PWM2                      0x5
#define PORT_AF_M1PWM3                      0x5
#define PORT_AF_M1PWM4                      0x5
#define PORT_AF_M1PWM5                      0x5
#define PORT_AF_M1PWM6                      0x5
#define PORT_AF_M1PWM7                      0x5
#define PORT_AF_M1FAULT0                    0x5
#define PORT_AF_IDX1												0x6
#define PORT_AF_PhA1    										0x6
#define PORT_AF_PhB1    										0x6
#define PORT_AF_IDX0    										0x6
#define PORT_AF_PhA0    										0x6
#define PORT_AF_PhB0    										0x6
#define PORT_AF_PhA0    										0x6
#define PORT_AF_PhB0    										0x6
#define PORT_AF_IDX0    										0x6
#define PORT_AF_T2CCP0											0x7
#define PORT_AF_T2CCP1      								0x7
#define PORT_AF_T3CCP0      								0x7
#define PORT_AF_T3CCP1      								0x7
#define PORT_AF_T1CCP0      								0x7
#define PORT_AF_T1CCP1      								0x7
#define PORT_AF_T0CCP0      								0x7
#define PORT_AF_T0CCP1      								0x7
#define PORT_AF_T4CCP0      								0x7
#define PORT_AF_T4CCP1      								0x7
#define PORT_AF_T5CCP0      								0x7
#define PORT_AF_T5CCP1      								0x7
#define PORT_AF_WT0CCP0     								0x7
#define PORT_AF_WT0CCP1     								0x7
#define PORT_AF_WT1CCP0     								0x7
#define PORT_AF_WT1CCP1     								0x7
#define PORT_AF_WT2CCP0     								0x7
#define PORT_AF_WT2CCP1     								0x7
#define PORT_AF_WT3CCP0     								0x7
#define PORT_AF_WT3CCP1     								0x7
#define PORT_AF_WT4CCP0     								0x7
#define PORT_AF_WT4CCP1     								0x7
#define PORT_AF_WT5CCP0     								0x7
#define PORT_AF_WT5CCP1     								0x7
#define PORT_AF_T0CCP0											0x7
#define PORT_AF_T0CCP1											0x7
#define PORT_AF_T1CCP0											0x7
#define PORT_AF_T1CCP1											0x7
#define PORT_AF_T2CCP0											0x7
#define PORT_AF_CAN1R0											0x8
#define PORT_AF_CAN1T1        							0x8
#define PORT_AF_CAN0R4        							0x8
#define PORT_AF_CAN0T5        							0x8
#define PORT_AF_U1RTS4         							0x8
#define PORT_AF_U1CTS5         							0x8
#define PORT_AF_USB0EPEN      							0x8
#define PORT_AF_USB0PFLT      							0x8
#define PORT_AF_USB0EPEN      							0x8
#define PORT_AF_USB0PFLT      							0x8
#define PORT_AF_NMI7          							0x8
#define PORT_AF_CAN0R4        							0x8
#define PORT_AF_CAN0T5        							0x8
#define PORT_AF_NMI0          							0x8
#define PORT_AF_USB0EPEN      							0x8
#define PORT_AF_C0o													0x9
#define PORT_AF_C1o													0x9
#define PORT_AF_TRD1 												0xE
#define PORT_AF_TRD0 												0xE
#define PORT_AF_TRCLK												0xE


/*Pin level type*/
#define PORT_PIN_LOW														0
#define PORT_PIN_HIGH														1


typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;


typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;





/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))

#define SYSTEM_CONTROL_BASE_ADDRESS 	     	0x400FE000
#define RESC                                 *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x05C))

#define PLLFREQ0 						 *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x160)) /*Read Only*/
#define PLLFREQ1 						 *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x164)) /*Read Only*/
#define PLLSTAT  						 *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x168)) /*Read Only*/



/*RCC Bit field accessing*/
typedef struct
{
	uint32 MOSCDIS   		 	: 1;
	uint32 					 	: 3;
	uint32 OSCSRC    			: 2;
	uint32 XTAL 	   			: 5;
	uint32 BYPASS    			: 1;
	uint32 				   		: 1;
	uint32 PWRDN	   			: 1;
	uint32 			     		: 3;
	uint32 PWMDIV    			: 3;
	uint32 USEPWMDIV 			: 1;
	uint32 			     		: 1;
	uint32 USESYSDIV 			: 1;
	uint32 SYSDIV		 		: 4;
	uint32 ACG			 		: 1;	
	uint32 			     		: 4;
}Mcu_RCC_BF;

typedef struct
{

	
}Mcu_RCC2_BF;

typedef union
{
		uint32 R;
		Mcu_RCC_BF B;
}RCC_TAG;


typedef union
{
		uint32 R;
		Mcu_RCC2_BF B;
}RCC2_TAG;


#define RCC									 (*((volatile RCC_TAG*)(SYSTEM_CONTROL_BASE_ADDRESS+0x060))) 
#define RCC2								 (*((volatile uint32 *)(SYSTEM_CONTROL_BASE_ADDRESS+0x070))) 

/*Offsets*/
#define PORT_DATAPORT_OFFSET						0x3FC
#define PORT_DIR_OFFSET		 							0x400
#define PORT_AFSEL_OFFSET					 			0x420
#define PORT_LOCK_OFFSET 								0x520
#define PORT_COMMIT_OFFSET 							0x524
#define PORT_CTL_OFFSET 								0x52C

#define PORT_PORTA_APB					 				0x40004000
#define PORT_PORTA_AHB									0x40058000
#define PORT_PORTB_APB									0x40005000
#define PORT_PORTB_AHB									0x40059000
#define PORT_PORTC_APB									0x40006000
#define PORT_PORTC_AHB									0x4005A000
#define PORT_PORTD_APB									0x40007000
#define PORT_PORTD_AHB									0x4005B000
#define PORT_PORTE_APB									0x40024000
#define PORT_PORTE_AHB									0x4005C000
#define PORT_PORTF_APB									0x40025000
#define PORT_PORTF_AHB									0x4005D000

/*Pins offset address*/
#define PORT_PIN0_OFFSET								0x004
#define PORT_PIN1_OFFSET								0x008
#define PORT_PIN2_OFFSET								0x010
#define PORT_PIN3_OFFSET								0x020
#define PORT_PIN4_OFFSET								0x040
#define PORT_PIN5_OFFSET								0x080
#define PORT_PIN6_OFFSET								0x100
#define PORT_PIN7_OFFSET								0x200

/*Pin definitions*/
#define PORT_APB_PIN0					0x000
#define PORT_APB_PIN1					0x001
#define PORT_APB_PIN2					0x002
#define PORT_APB_PIN3					0x003
#define PORT_APB_PIN4					0x004
#define PORT_APB_PIN5					0x005
#define PORT_APB_PIN6					0x006
#define PORT_APB_PIN7					0x007
#define PORT_APB_PIN8					0x008
#define PORT_APB_PIN9					0x009
#define PORT_APB_PIN10				0x00A
#define PORT_APB_PIN11				0x00B
#define PORT_APB_PIN12				0x00C
#define PORT_APB_PIN13				0x00D
#define PORT_APB_PIN14				0x00E
#define PORT_APB_PIN15				0x00F
#define PORT_APB_PIN16				0x011
#define PORT_APB_PIN17				0x012
#define PORT_APB_PIN18				0x013
#define PORT_APB_PIN19				0x014
#define PORT_APB_PIN20				0x015
#define PORT_APB_PIN21				0x016
#define PORT_APB_PIN22				0x017
#define PORT_APB_PIN23				0x018
#define PORT_APB_PIN24				0x019
#define PORT_APB_PIN25				0x01A
#define PORT_APB_PIN26				0x01B
#define PORT_APB_PIN27				0x01C
#define PORT_APB_PIN28				0x01D
#define PORT_APB_PIN29				0x01E
#define PORT_APB_PIN30				0x01F
#define PORT_APB_PIN31				0x020
#define PORT_APB_PIN32				0x021
#define PORT_APB_PIN33				0x022
#define PORT_APB_PIN34				0x023
#define PORT_APB_PIN35				0x024
#define PORT_APB_PIN36				0x025
#define PORT_APB_PIN37				0x026
#define PORT_APB_PIN38				0x027
#define PORT_APB_PIN39				0x028
#define PORT_APB_PIN40				0x029
#define PORT_APB_PIN41				0x02A
#define PORT_APB_PIN42				0x02B
#define PORT_APB_PIN43				0x02C
#define PORT_APB_PIN44				0x02D
#define PORT_APB_PIN45				0x02E
#define PORT_APB_PIN46				0x02F
#define PORT_APB_PIN47				0x030

#define PORT_AHB_PIN0					0x600
#define PORT_AHB_PIN1					0x601
#define PORT_AHB_PIN2					0x602
#define PORT_AHB_PIN3					0x603
#define PORT_AHB_PIN4					0x604
#define PORT_AHB_PIN5					0x605
#define PORT_AHB_PIN6					0x606
#define PORT_AHB_PIN7					0x607
#define PORT_AHB_PIN8					0x608
#define PORT_AHB_PIN9					0x609
#define PORT_AHB_PIN10				0x60A
#define PORT_AHB_PIN11				0x60B
#define PORT_AHB_PIN12				0x60C
#define PORT_AHB_PIN13				0x60D
#define PORT_AHB_PIN14				0x60E
#define PORT_AHB_PIN15				0x60F
#define PORT_AHB_PIN16				0x611
#define PORT_AHB_PIN17				0x612
#define PORT_AHB_PIN18				0x613
#define PORT_AHB_PIN19				0x614
#define PORT_AHB_PIN20				0x615
#define PORT_AHB_PIN21				0x616
#define PORT_AHB_PIN22				0x617
#define PORT_AHB_PIN23				0x618
#define PORT_AHB_PIN24				0x619
#define PORT_AHB_PIN25				0x61A
#define PORT_AHB_PIN26				0x61B
#define PORT_AHB_PIN27				0x61C
#define PORT_AHB_PIN28				0x61D
#define PORT_AHB_PIN29				0x61E
#define PORT_AHB_PIN30				0x61F
#define PORT_AHB_PIN31				0x620
#define PORT_AHB_PIN32				0x621
#define PORT_AHB_PIN33				0x622
#define PORT_AHB_PIN34				0x623
#define PORT_AHB_PIN35				0x624
#define PORT_AHB_PIN36				0x625
#define PORT_AHB_PIN37				0x626
#define PORT_AHB_PIN38				0x627
#define PORT_AHB_PIN39				0x628
#define PORT_AHB_PIN40				0x629
#define PORT_AHB_PIN41				0x62A
#define PORT_AHB_PIN42				0x62B
#define PORT_AHB_PIN43				0x62C
#define PORT_AHB_PIN44				0x62D
#define PORT_AHB_PIN45				0x62E
#define PORT_AHB_PIN46				0x62F
#define PORT_AHB_PIN47				0x630

/*WDT Registers*/
#define WDT0_BASE_ADDRESS 							0x40000000
#define WDT1_BASE_ADDRESS 							0x40001000
#define WDT_WDTCTL_OFFSET							0x008
#define WDT_WDTLOAD_OFFSET							0x000
#define WDT_WDTLOCK_OFFSET							0xC00
#define WDT_WDTVALUE_OFFSET							0x004

/*Interrupt control*/
#define INT_CTRL_PENDING_OFFSET			0x200



/*Peripheral base address*/
#define TIVAC_PERI_BASE_ADDRESS					0x40000000
#define ALIAS_TIVAC_PERI_BASE_ADDRESS		0x42000000


#define TIVAc_PERI_BIT_BAND_ALIASING(RegOffset,BitNum)		(*((volatile uint32*)    ( ALIAS_TIVAC_PERI_BASE_ADDRESS + (( (uint32)RegOffset-TIVAC_PERI_BASE_ADDRESS) * 0x00000020) + ((uint32)BitNum*0x00000004) )   ) )
	















/**********************************************************************************************************************************************
**                                MODULE NAME: GENERAL PURPOSE TIMER MODULE
**********************************************************************************************************************************************/

/*Configuration offset*/
#define GPT_GPTMCFG_OFFSET							0x000

/*Timer mode offset*/
#define GPT_GPTMTAMR_OFFSET							0x004
#define GPT_GPTMTBMR_OFFSET							0x008

/*Timer control offset*/
#define GPT_GPTMCTL_OFFSET							0x00C

#define GPT_GPTMTAILR_OFFSET						0x028
#define GPT_GPTMTBILR_OFFSET						0x02C

/*Interrupt mask offset*/
#define GPT_GPTMIMR_OFFSET							0x018

/*Raw interrupt status intterupt offset*/
#define GPT_GPTMRIS_OFFSET							0x01C



#define _16_32_bit_Timer0					 0x40030000
#define _16_32_bit_Timer1                    0x40031000
#define _16_32_bit_Timer2                    0x40032000
#define _16_32_bit_Timer3                    0x40033000
#define _16_32_bit_Timer4                    0x40034000
#define _16_32_bit_Timer5                    0x40035000
#define _32_64_bit_Wide_Timer0               0x40036000
#define _32_64_bit_Wide_Timer1               0x40037000
#define _32_64_bit_Wide_Timer2               0x4004C000
#define _32_64_bit_Wide_Timer3               0x4004D000
#define _32_64_bit_Wide_Timer4               0x4004E000
#define _32_64_bit_Wide_Timer5               0x4004F000







/*Internal memory addresses*/
#define FLASHDRIVER_BASE_ADDRESS	0x400FD000
#define FLASHDRIVER_FMA_OFFSET		0x000
#define FLASHDRIVER_FMD_OFFSET		0x004
#define FLASHDRIVER_FMC_OFFSET		0x008

/*FMC Register*/
#define FLASHDRIVER_FMC_REGISTER		(*((volatile uint32*)(FLASHDRIVER_BASE_ADDRESS+FLASHDRIVER_FMC_OFFSET)))		
/*FMD Register*/
#define FLASHDRIVER_FMD_REGISTER		(*((volatile uint32*)(FLASHDRIVER_BASE_ADDRESS+FLASHDRIVER_FMD_OFFSET)))		

/*Boot configuration*/
#define FLASHDRIVER_CONFIGURATION_BASE_ADDRESS 				0x400FE000
#define FLASHDRIVER_BOOTCFG_OFFSET 										0x1D0










/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
