/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file      PORT.c
 *         \brief     Microcontroller Driver
 *         \details   The Driver Configure general input and output pins
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Compiler.h"
#include "PORT_Types.h"
#include "PORT_Cfg.h"
#include "PORT.h"
#include "Mcu_Hw.h"




/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/*GPIO Commited*/
#define GPIO_PORT_COMMIT											(uint32)1
/*Unlock Port*/
#define GPIO_PORT_UNLOCK 											0x4C4F434B

#define PORTS_NUM																				12
#define PINS_NUM																				8
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static const uint32 PortBaseAddress[PORTS_NUM] = 
{
	PORT_PORTA_APB,					
	PORT_PORTB_APB,
	PORT_PORTC_APB,
	PORT_PORTD_APB,
	PORT_PORTE_APB,
	PORT_PORTF_APB,
	PORT_PORTA_AHB,
	PORT_PORTB_AHB,
	PORT_PORTC_AHB,
	PORT_PORTD_AHB,
	PORT_PORTE_AHB,
	PORT_PORTF_AHB
};

static const uint32 PinOffsetAddress[PINS_NUM] = 
{
	PORT_PIN0_OFFSET,
	PORT_PIN1_OFFSET,
	PORT_PIN2_OFFSET,
	PORT_PIN3_OFFSET,
	PORT_PIN4_OFFSET,
	PORT_PIN5_OFFSET,
	PORT_PIN6_OFFSET,
	PORT_PIN7_OFFSET
};



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
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
Syntax          :   Std_ReturnType PORT_Init(Port_ConfigType* Port_ConfigPtr);
Description     :   configure the ports and pins states
Sync\Async      :
Reentrancy      :
Parameters (in) :
Parameters (out):
Return value:   :  Std_ReturnType
*******************************************************************************/
Std_ReturnType PORT_Init(const Port_ConfigType* Port_ConfigPtr)
{
	
		/*Port index*/
		uint8 loc_PortIndex = 0;
		/*Pin index*/
		uint8 loc_PinIndex = 0;
		/*Port type*/
		uint8 loc_PortType = 0;

    /*Define error status*/
    Std_ReturnType loc_StdErrorStatus = E_OK;

    /*Counter*/
    static uint8 loc_Counter = 0;

    if(NULL_PTR != Port_ConfigPtr)
    {
        for(loc_Counter = 0 ; loc_Counter < PORT_CONFIG_SIZE; loc_Counter++)
        {
						/*Pin index*/
						loc_PinIndex  = ((Port_ConfigPtr[loc_Counter].PortPinNumber)%(PORT_SIZE*4));
						/*Port type*/
						loc_PortType = (uint8)((Port_ConfigPtr[loc_Counter].PortPinNumber)/((1 <<PORT_SIZE)-1));
						/*Port index*/
						loc_PortIndex = (loc_PinIndex / PORT_SIZE)+loc_PortType;		
						/*Get the real index 0 to 7 in specific port*/
						loc_PinIndex  = loc_PinIndex%PORT_SIZE; 
						
						GetReg(PortBaseAddress[loc_PortIndex],PORT_LOCK_OFFSET) = GPIO_PORT_UNLOCK;
						
						/*Commit registers*/
						/*GetReg(PortBaseAddress[loc_PortIndex],PORT_COMMIT_OFFSET) |= GPIO_PORT_COMMIT << loc_PinIndex;*/
						TIVAc_PERI_BIT_BAND_ALIASING((PortBaseAddress[loc_PortIndex]+PORT_COMMIT_OFFSET),loc_PinIndex) = GPIO_PORT_COMMIT;
	
						/*Set direction*/
						/*GetReg(PortBaseAddress[loc_PortIndex],PORT_DIR_OFFSET) |= (uint32)1 << loc_PinIndex;*/
						TIVAc_PERI_BIT_BAND_ALIASING((PortBaseAddress[loc_PortIndex]+PORT_DIR_OFFSET),loc_PinIndex) = 1;
	
            /*Set mode*/
            /*GetReg(PortBaseAddress[loc_PortIndex], PORT_AFSEL_OFFSET) = (uint32)PORT_FUNCTION << loc_PinIndex;*/
						TIVAc_PERI_BIT_BAND_ALIASING((PortBaseAddress[loc_PortIndex]+PORT_AFSEL_OFFSET),loc_PinIndex) = PORT_FUNCTION;
	
						if(PORT_DIO != Port_ConfigPtr[loc_Counter].PortPinMode)
						{
										/*Masking*/
										/*GetReg(PortBaseAddress[loc_PortIndex],PORT_CTL_OFFSET) &= ~((uint32)(0xF) << (((Port_ConfigPtr[loc_Counter].PortPinNumber)%PORT_SIZE)*4));
										GetReg(PortBaseAddress[loc_PortIndex],PORT_CTL_OFFSET) |= (uint32)(Port_ConfigPtr[loc_Counter].PortPinMode) << ((loc_PinIndex)*4);*/
										TIVAc_PERI_BIT_BAND_ALIASING((PortBaseAddress[loc_PortIndex]+PORT_CTL_OFFSET),loc_PinIndex) = (Port_ConfigPtr[loc_Counter].PortPinMode);
							
						}
            
						/*Set levelPort_ConfigPtr[loc_Counter].PortPin*/
            /*GetReg(PortBaseAddress[loc_PortIndex],PinOffsetAddress[loc_PinIndex]) = (uint32)(Port_ConfigPtr[loc_Counter].PortPinLevelValue)<<(loc_PinIndex); */
            /*GetReg(PortBaseAddress[loc_PortIndex],PinOffsetAddress[loc_PinIndex]) = (uint32)(Port_ConfigPtr[loc_Counter].PortPinLevelValue);*/
						TIVAc_PERI_BIT_BAND_ALIASING((PortBaseAddress[loc_PortIndex]+PORT_DATAPORT_OFFSET),loc_PinIndex) = 1;
						
						/*Internal attach*/
            /*GetReg(PortBaseAddress[loc_PortIndex], Port_ConfigPtr[loc_Counter].PortPinInternalAttach) |= (0xFF & (uint32)1 )<<loc_PinIndex;*/
						TIVAc_PERI_BIT_BAND_ALIASING((PortBaseAddress[loc_PortIndex]+(Port_ConfigPtr[loc_Counter].PortPinInternalAttach)),loc_PinIndex) = 1;
		
            /*Output current*/
            /*GetReg(PortBaseAddress[loc_PortIndex], Port_ConfigPtr[loc_Counter].PortPinOutputCurrent) |= (0xFF & (uint32)1 ) <<loc_PinIndex;*/
						TIVAc_PERI_BIT_BAND_ALIASING((PortBaseAddress[loc_PortIndex]+(Port_ConfigPtr[loc_Counter].PortPinOutputCurrent)),loc_PinIndex) = 1;
	
        }
    }
    else
    {
        /*Set null pointer error*/
        loc_StdErrorStatus = E_NULL_POINTER;
    }
    return loc_StdErrorStatus;
}


/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
