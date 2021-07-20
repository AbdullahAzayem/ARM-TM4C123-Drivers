/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Types.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**Group priority definition*/
#define INTCTRL_GROUPING_8G_1S				0x4
#define INTCTRL_PRIGROUP_4G_2S				0x5
#define INTCTRL_PRIGROUP_2G_4S				0x6
#define INTCTRL_PRIGROUP_1G_8S      	0x7


/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#define INTCTRL_NVIC_ENx_ENABLE  1
#define INTCTRL_NVIC_ENx_DISABLE 2



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

typedef struct
{
    IntCtrl_InterruptType IntCtrl_InterruptNumber;
    uint8 IntCtrl_InterruptGroup;
    uint8 IntCtrl_InterruptSubGroup;

} IntCtrl_InterruptConfigType;

extern const IntCtrl_InterruptConfigType IntCtrl_InterruptState[];




/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/*Macro like function GET_NVEC_PRIx Register*/
#define GET_NVEC_PRIX_REG(InterruptNumber) *( (volatile uint32*) (0xE000E400 +(uint32)( (InterruptNumber/4)*4)) )
/*Macro like function GET_NVEC_ENx Register*/
#define GET_NVEC_ENX_REG(InterruptNumber)  *( (volatile uint32*) (0xE000E100 +( (InterruptNumber /32)*4) ) )
/*Macro like function GET_NVEC_DISx Register*/
#define GET_NVEC_DISX_REG(InterruptNumber) *( (volatile uint32*) (0xE000E180 +( (InterruptNumber /32)*4)  ) )

/*Pending register*/
#define GET_NVEC_PEND_REG(InterruptNumber)  *( (volatile uint32*) (0xE000E200 +( (InterruptNumber /32)*4) ) )
#define GET_NVEC_UNPEND_REG(InterruptNumber)  *( (volatile uint32*) (0xE000E280 +( (InterruptNumber /32)*4) ) )


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)
* \Description     : initialize Nvic\SCB Module by parsing the Configuration
*                    into Nvic\SCB registers
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
Std_ReturnType IntCtrl_Init(void)
{
    Std_ReturnType  local_uint8ErrorStatus = E_OK;
    uint8 local_u8InterruptNumber;
    uint8 local_u8InterruptGroup;
    uint8 local_u8InterruptSubGroup;
    /*Define counter*/
    uint8 local_u8Counter = 0;

    /*bit field number*/
    uint8 local_uint8BitField = 0 ;


    /*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT  =  ((uint32)0x05FA0000) | ((uint32)INTCTRL_GROUPING_STATE << 8);


    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
    for(local_u8Counter = 0; local_u8Counter < INTCTRL_ACTIVE_GROUP_NUMBER ; local_u8Counter++)
    {
        local_u8InterruptNumber   = IntCtrl_InterruptState[local_u8Counter].IntCtrl_InterruptNumber;
        local_u8InterruptGroup    = IntCtrl_InterruptState[local_u8Counter].IntCtrl_InterruptGroup; // 0b111100011
        local_u8InterruptSubGroup = IntCtrl_InterruptState[local_u8Counter].IntCtrl_InterruptSubGroup;


        /*Get the bit field*/
        local_uint8BitField       = ((local_u8InterruptNumber % 4) * 8) + 5 ;

#if INTCTRL_GROUPING_STATE == INTCTRL_GROUPING_8G_1S  		/* 0x0 | 0x4 xxx*/
        if( ( local_u8InterruptGroup >= 0 && local_u8InterruptGroup <= 7 ) && ( local_u8InterruptSubGroup == 0 ))
        {
            GET_NVEC_PRIX_REG(local_u8InterruptNumber) |= (uint32)(((local_u8InterruptGroup & 0x7) ) << local_uint8BitField );
        }
        else
        {
            local_uint8ErrorStatus = E_NOT_OK;
        }
#elif INTCTRL_GROUPING_STATE == INTCTRL_PRIGROUP_4G_2S 		/* 0x5 => xxy*/
        if(( local_u8InterruptGroup >= 0 && local_u8InterruptGroup <= 3 ) && ( (local_u8InterruptSubGroup >= 0) && ((local_u8InterruptSubGroup <= 1) ) ))
        {
            GET_NVEC_PRIX_REG(local_u8InterruptNumber) |=  ( (uint32)(( (local_u8InterruptGroup << 1 ) | local_u8InterruptSubGroup) & 0b00000111 ) ) << local_uint8BitField ;
        }
        else
        {
            local_uint8ErrorStatus = E_NOT_OK;
        }
#elif INTCTRL_GROUPING_STATE == INTCTRL_PRIGROUP_2G_4S 		/* 0x6 => xyy*/
        if(( local_u8InterruptGroup >= 0 && local_u8InterruptGroup <= 1 ) && ( (local_u8InterruptSubGroup >= 0) && ((local_u8InterruptSubGroup <= 3) ) ))
        {
            GET_NVEC_PRIX_REG(local_u8InterruptNumber) |= ((uint32)( ((local_u8InterruptGroup  << 2 ) | local_u8InterruptSubGroup & 0b00000111) ) ) << local_uint8BitField);
        }
        else
        {
            local_uint8ErrorStatus = E_NOT_OK;
        }
#elif INTCTRL_GROUPING_STATE == INTCTRL_PRIGROUP_1G_8S 		/* 0x7 => yyy */
        if(( local_u8InterruptGroup == 0 ) && ( (local_u8InterruptSubGroup >= 0) && ((local_u8InterruptSubGroup <= 7) ) ))
        {
            GET_NVEC_PRIX_REG(local_u8InterruptNumber) |= ((uint32)(local_u8InterruptSubGroup & 0b00000111)) << local_uint8BitField);
        }
        else
        {
            local_uint8ErrorStatus = E_NOT_OK;
        }
#else
#error "Wrong Configuration"
#endif

        /*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
#if INTCTRL_NVIC_ENx_STATE == INTCTRL_NVIC_ENx_ENABLE
        /*2- Enable the ENx register for spectific register*/
        GET_NVEC_ENX_REG(local_u8InterruptNumber) |= (uint32)1 << local_u8InterruptNumber;
#elif 	INTCTRL_NVIC_ENx_STATE == INTCTRL_NVIC_ENx_DISABLE
        /*2- Disable the ENx register for spectific register*/
        GET_NVEC_DISX_REG(local_u8InterruptNumber) &= ~((uint32)0 << local_u8InterruptNumber);
#else
#error "Wrong Configuration"
#endif


    }

    return local_uint8ErrorStatus;

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
