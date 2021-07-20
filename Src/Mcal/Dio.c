/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file      Dio.c
 *         \brief     Microcontroller Driver
 *         \details   The Driver Configure general input and output pins
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Types.h"
#include "Dio.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define DIO_PORT_SIZE						8
#define DIO_PORTS_NUM						16
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static const uint32 PortBaseAddress[DIO_PORTS_NUM] =
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

static const uint32 PinOffsetAddress[DIO_PORT_SIZE] =
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
Syntax          :   DioPinLevelType Dio_ReadChannel(DioChannelType ChannelID)
Description     :   read the value of digital pin
Sync\Async      :
Reentrancy      :
Parameters (in) :
Parameters (out):
Return value:   :
*******************************************************************************/
DioPinLevelType Dio_ReadChannel(DioChannelType ChannelID)
{
    /*Port index*/
    uint8 loc_PortIndex = 0;
    /*Pin index*/
    uint8 loc_PinIndex = 0;
    /*Port type*/
    uint8 loc_PortType = 0;

    /*Pin index*/
    loc_PinIndex  = (ChannelID) % (DIO_PORT_SIZE * 4);

    /*Port type*/
    loc_PortType = (uint8)((ChannelID) / ((1 << DIO_PORT_SIZE) - 1));
    /*Port index*/
    loc_PortIndex = (loc_PinIndex / DIO_PORT_SIZE) + loc_PortType;

    /*Index number in port*/
    loc_PinIndex  = loc_PinIndex % DIO_PORT_SIZE;

    return (uint8)GetReg(PortBaseAddress[loc_PortIndex], PinOffsetAddress[loc_PinIndex]);
}


/******************************************************************************
Syntax          :  void Dio_WriteChannel(DioChannelType ChannelID,DioPinLevelType ChannelLevel)
Description     :   set the value of digital pin
Sync\Async      :
Reentrancy      :
Parameters (in) :
Parameters (out):
Return value:   :
*******************************************************************************/
void Dio_WriteChannel(DioChannelType ChannelID, DioPinLevelType ChannelLevel)
{
    /*Port index*/
    uint8 loc_PortIndex = 0;
    /*Pin index*/
    uint8 loc_PinIndex = 0;
    /*Port type*/
    uint8 loc_PortType = 0;

    /*Pin index*/
    loc_PinIndex  = (ChannelID) % (DIO_PORT_SIZE * 4);

    /*Port type*/
    loc_PortType = (uint8)((ChannelID) / ((1 << DIO_PORT_SIZE) - 1));
    /*Port index*/
    loc_PortIndex = (loc_PinIndex / DIO_PORT_SIZE) + loc_PortType;

    /*Index number in port*/
    loc_PinIndex  = loc_PinIndex % DIO_PORT_SIZE;

    /*Set level*/
    /*GetReg(PortBaseAddress[loc_PortIndex],PinOffsetAddress[loc_PinIndex]) = (uint32)ChannelLevel;*/
    TIVAc_PERI_BIT_BAND_ALIASING((PortBaseAddress[loc_PortIndex] + PORT_DATAPORT_OFFSET), loc_PinIndex) = ChannelLevel;


}
/******************************************************************************
Syntax          :   DioPortLevelType Dio_ReadPort(DioPortType PortID);
Description     :   read the value of digital port
Sync\Async      :
Reentrancy      :
Parameters (in) :
Parameters (out):
Return value:   :
*******************************************************************************/
DioPortLevelType Dio_ReadPort(DioPortType PortID)
{
    return 	(0xFF & GetReg(PortBaseAddress[PortID], PORT_DATAPORT_OFFSET) );
}

/******************************************************************************
Syntax          :   void Dio_WritePort (DioPortType ChannelPort, DioPortLevelType ChannelLevel);
Description     :   read the value of digital port
Sync\Async      :
Reentrancy      :
Parameters (in) :
Parameters (out):
Return value:   :
*******************************************************************************/
void Dio_WritePort(DioPortType PortID, DioPortLevelType PortLevel)
{
    /*Set level*/
    GetReg(PortBaseAddress[PortID], PORT_DATAPORT_OFFSET) = (uint32)PortLevel;
}

/******************************************************************************
Syntax          :   void GPIO_FlipChannel(DioChannelType Channel)
Description     :   read the value of digital port
Sync\Async      :
Reentrancy      :
Parameters (in) :
Parameters (out):
Return value:   :
*******************************************************************************/
void GPIO_FlipChannel(DioChannelType Channel)
{
    /*Toggle level*/
    Dio_WriteChannel(Channel, ~Dio_ReadChannel(Channel));
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
