/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT_Types.h"
#include "Mcu_Hw.h"
#include "PORT_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 /*PortPinNumber:			PortPinDirection:							PortPinMode:														PortPinLevelValue   PortPinInternalAttach;   	PortPinOutputCurrent;
		PORT_APB_PIN0			PORT_PIN_OUTPUT								PORT_DIO									              PORT_PIN_HIGH,   		PORT_PIN_PULLUP,   				PORT_PIN_DR2R
		PORT_APB_PIN1	   	PORT_PIN_INPUT            		PORT_AF_USB0ID						              PORT_PIN_LOW,   		PORT_PIN_PULLDOWN,   			PORT_PIN_DR4R
		PORT_APB_PIN2	                                  PORT_AF_USB0VBUS      																			PORT_PIN_OPEN_DRAIN				PORT_PIN_DR8R
		PORT_APB_PIN3	                                  PORT_AF_AIN10         		
		PORT_APB_PIN4	                                  PORT_AF_AIN11         		
		PORT_APB_PIN5	                                  PORT_AF_C1_MINUS      		
		PORT_APB_PIN6	                                  PORT_AF_C1_PLUS       		
		PORT_APB_PIN7	                                  PORT_AF_C0_PLUS       		
		PORT_APB_PIN8	                                  PORT_AF_C0_MINUS 	    		
		PORT_APB_PIN9	                                  PORT_AF_AIN7          		
		PORT_APB_PIN10                                  PORT_AF_AIN6          		
		PORT_APB_PIN11                                  PORT_AF_AIN5          		
		PORT_APB_PIN12                                  PORT_AF_AIN4          		
		PORT_APB_PIN13                                  PORT_AF_USB0DM        		
		PORT_APB_PIN14                                  PORT_AF_USB0DP        		
		PORT_APB_PIN15                                  PORT_AF_AIN3          		
		PORT_APB_PIN16                                  PORT_AF_AIN2          		
		PORT_APB_PIN17                                  PORT_AF_AIN1          		
		PORT_APB_PIN18                                  PORT_AF_AIN0          		
		PORT_APB_PIN19                                  PORT_AF_AIN9          		
		PORT_APB_PIN20                                  PORT_AF_AIN8          		
		PORT_APB_PIN21                                  PORT_AF_U0R0							
		PORT_APB_PIN22                                  PORT_AF_U0T1              
		PORT_APB_PIN23                                  PORT_AF_U1R0              
		PORT_APB_PIN24                                  PORT_AF_U1T1              
		PORT_APB_PIN25                                  PORT_AF_TCK               
		PORT_APB_PIN26                                  PORT_AF_SWCLK             
		PORT_APB_PIN27                                  PORT_AF_TMS               
		PORT_APB_PIN28                                  PORT_AF_SWDIO             
		PORT_APB_PIN29                                  PORT_AF_TDI               
		PORT_APB_PIN30                                  PORT_AF_TDO               
		PORT_APB_PIN31                                  PORT_AF_SWO               
		PORT_APB_PIN32                                  PORT_AF_U4R4              
		PORT_APB_PIN33                                  PORT_AF_U4T5              
		PORT_APB_PIN34                                  PORT_AF_U3R6              
		PORT_APB_PIN35                                  PORT_AF_U3T7              
		PORT_APB_PIN36                                  PORT_AF_SSI3Clk           
		PORT_APB_PIN37                                  PORT_AF_SSI3Fss           
		PORT_APB_PIN38                                  PORT_AF_SSI3Rx            
		PORT_APB_PIN39                                  PORT_AF_SSI3Tx            
		PORT_APB_PIN40                                  PORT_AF_U6R4              
		PORT_APB_PIN41                                  PORT_AF_U6T5              
		PORT_APB_PIN42                                  PORT_AF_U2R6              
		PORT_APB_PIN43                                  PORT_AF_U2T7              
		PORT_APB_PIN44                                  PORT_AF_U7R0              
		PORT_APB_PIN45                                  PORT_AF_U7T1							
		PORT_APB_PIN46                                  PORT_AF_U5R4							
		PORT_APB_PIN47                                  PORT_AF_U5T5              
																									  PORT_AF_U1RTS0            
		PORT_AHB_PIN0	                                  PORT_AF_U1CTS1            
		PORT_AHB_PIN1	                                  PORT_AF_SSI0Clk						
		PORT_AHB_PIN2	                                  PORT_AF_SSI0Fss           
		PORT_AHB_PIN3	                                  PORT_AF_SSI0R4            
		PORT_AHB_PIN4	                                  PORT_AF_SSI0T5            
		PORT_AHB_PIN5	                                  PORT_AF_SSI2Clk           
		PORT_AHB_PIN6	                                  PORT_AF_SSI2Fss           
		PORT_AHB_PIN7	                                  PORT_AF_SSI2R6            
		PORT_AHB_PIN8	                                  PORT_AF_SSI2T7            
		PORT_AHB_PIN9	                                  PORT_AF_U1R4              
		PORT_AHB_PIN10                                  PORT_AF_U1T5              
		PORT_AHB_PIN11                                  PORT_AF_SSI1Clk           
		PORT_AHB_PIN12                                  PORT_AF_SSI1Fss           
		PORT_AHB_PIN13                                  PORT_AF_SSI1R2            
		PORT_AHB_PIN14                                  PORT_AF_SSI1T3            
		PORT_AHB_PIN15                                  PORT_AF_SSI1R0            
		PORT_AHB_PIN16                                  PORT_AF_SSI1T1            
		PORT_AHB_PIN17                                  PORT_AF_SSI1Clk           
		PORT_AHB_PIN18                                  PORT_AF_SSI1Fss           
		PORT_AHB_PIN19                                  PORT_AF_I2C1SCL						
		PORT_AHB_PIN20                                  PORT_AF_I2C1SDA           
		PORT_AHB_PIN21                                  PORT_AF_I2C0SCL           
		PORT_AHB_PIN22                                  PORT_AF_I2C0SDA           
		PORT_AHB_PIN23                                  PORT_AF_I2C3SCL           
		PORT_AHB_PIN24                                  PORT_AF_I2C3SDA           
		PORT_AHB_PIN25                                  PORT_AF_I2C2SCL           
		PORT_AHB_PIN26                                  PORT_AF_I2C2SDA           
		PORT_AHB_PIN27                                  PORT_AF_CAN0R0            
		PORT_AHB_PIN28                                  PORT_AF_CAN0T3            
		PORT_AHB_PIN29                                  PORT_AF_M0PWM2						
		PORT_AHB_PIN30                                  PORT_AF_M0PWM3            
		PORT_AHB_PIN31                                  PORT_AF_M0PWM0            
		PORT_AHB_PIN32                                  PORT_AF_M0PWM1            
		PORT_AHB_PIN33                                  PORT_AF_M0PWM6            
		PORT_AHB_PIN34                                  PORT_AF_M0PWM7            
		PORT_AHB_PIN35                                  PORT_AF_M0PWM6            
		PORT_AHB_PIN36                                  PORT_AF_M0PWM7            
		PORT_AHB_PIN37                                  PORT_AF_M0FAULT0          
		PORT_AHB_PIN38                                  PORT_AF_M0FAULT0          
		PORT_AHB_PIN39                                  PORT_AF_M0PWM4            
		PORT_AHB_PIN40                                  PORT_AF_M0PWM5            
		PORT_AHB_PIN41                                  PORT_AF_M0FAULT0          
		PORT_AHB_PIN42                                  PORT_AF_M1PWM2						
		PORT_AHB_PIN43                                  PORT_AF_M1PWM3						
		PORT_AHB_PIN44                                  PORT_AF_M1PWM0            
		PORT_AHB_PIN45                                  PORT_AF_M1PWM1            
		PORT_AHB_PIN46                                  PORT_AF_M1PWM2            
		PORT_AHB_PIN47                                  PORT_AF_M1PWM3            
																									  PORT_AF_M1PWM4            
																									  PORT_AF_M1PWM5            
																									  PORT_AF_M1PWM6            
																									  PORT_AF_M1PWM7            
																									  PORT_AF_M1FAULT0          
																									  PORT_AF_IDX1							
																									  PORT_AF_PhA1    					
																									  PORT_AF_PhB1    					
																									  PORT_AF_IDX0    					
																									  PORT_AF_PhA0    					
																									  PORT_AF_PhB0    					
																									  PORT_AF_PhA0    					
																									  PORT_AF_PhB0    					
																									  PORT_AF_IDX0    					
																									  PORT_AF_T2CCP0						
																									  PORT_AF_T2CCP1      			
																									  PORT_AF_T3CCP0      			
																									  PORT_AF_T3CCP1      			
																									  PORT_AF_T1CCP0      			
																									  PORT_AF_T1CCP1      			
																									  PORT_AF_T0CCP0      			
																									  PORT_AF_T0CCP1      			
																									  PORT_AF_T4CCP0      			
																									  PORT_AF_T4CCP1      			
																									  PORT_AF_T5CCP0      			
																									  PORT_AF_T5CCP1      			
																									  PORT_AF_WT0CCP0     			
																									  PORT_AF_WT0CCP1     			
																									  PORT_AF_WT1CCP0     			
																									  PORT_AF_WT1CCP1     			
																									  PORT_AF_WT2CCP0     			
																									  PORT_AF_WT2CCP1     			
																									  PORT_AF_WT3CCP0     			
																									  PORT_AF_WT3CCP1     			
																									  PORT_AF_WT4CCP0     			
																									  PORT_AF_WT4CCP1     			
																									  PORT_AF_WT5CCP0     			
																									  PORT_AF_WT5CCP1     			
																									  PORT_AF_T0CCP0						
																									  PORT_AF_T0CCP1						
																									  PORT_AF_T1CCP0						
																									  PORT_AF_T1CCP1						
																									  PORT_AF_T2CCP0						
																									  PORT_AF_CAN1R0						
																									  PORT_AF_CAN1T1        		
																									  PORT_AF_CAN0R4        		
																									  PORT_AF_CAN0T5        		
																									  PORT_AF_U1RTS4         		
																									  PORT_AF_U1CTS5         		
																									  PORT_AF_USB0EPEN      		
																									  PORT_AF_USB0PFLT      		
																									  PORT_AF_USB0EPEN      		
																									  PORT_AF_USB0PFLT      		
																									  PORT_AF_NMI7          		
																									  PORT_AF_CAN0R4        		
																									  PORT_AF_CAN0T5        		
																									  PORT_AF_NMI0          		
																									  PORT_AF_USB0EPEN      		
																									  PORT_AF_C0o								
																									  PORT_AF_C1o								
																									  PORT_AF_TRD1 							
																									  PORT_AF_TRD0 							
																									  PORT_AF_TRCLK																					
*/

const Port_ConfigType PortConfig[PORT_CONFIG_SIZE]=
{
	/*PortPinNumber      	 PortPinDirection         PortPinMode                PortPinLevelValue   PortPinInternalAttach;   	PortPinOutputCurrent;*/
	{ PORT_APB_PIN0,        PORT_PIN_OUTPUT,	        PORT_DIO,                  PORT_PIN_HIGH,   		PORT_PIN_PULLUP,   				PORT_PIN_DR2R},
	{ PORT_AHB_PIN6,        PORT_PIN_OUTPUT,	        PORT_DIO,                  PORT_PIN_HIGH,   		PORT_PIN_PULLUP,   				PORT_PIN_DR4R},
	{ PORT_APB_PIN8,        PORT_PIN_OUTPUT,	        PORT_DIO,                  PORT_PIN_HIGH,   		PORT_PIN_PULLUP,   				PORT_PIN_DR8R},
	{ PORT_AHB_PIN13,       PORT_PIN_OUTPUT,          PORT_DIO,                  PORT_PIN_HIGH,   		PORT_PIN_PULLUP,   				PORT_PIN_DR4R}
};








/**********************************************************************************************************************
 *  END OF FILE: Mcu_Lcfg.c
 *********************************************************************************************************************/
