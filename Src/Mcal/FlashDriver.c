/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file      FlashDriver.c
 *         \brief     Microcontroller Driver
 *         \details   The Driver configure the FlashDriver driver
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu_HW.h"
#include "FlashDriver_Cfg.h"
#include "FlashDriver.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/*Commit register offset*/
#define FLASHDRIVER_COMMIT_BIT_OFFSET 		3
/*Mass Erase Flash Memory offset*/
#define FLASHDRIVER_MASS_ERASE_BIT_OFFSET	2

/*Erease page offset*/
#define FLASHDRIVER_ERASE_PAGE_BIT_OFFSET	1

/*Write word offset*/
#define FLASHDRIVER_WRITE_BIT_OFFSET			0

/*KEY Select offset*/
#define FLASHDRIVER_KEY_SELECT_BIT_OFFSET	4


/*Flash FMA Address mask*/
#define FLASH_DRIVER_FMA_MASK									0xFFFC0000

/*Flash base address*/
#define FLASH_BASE_ADDRESS							( (volatile uint32*)  0x00004000 )

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/*Flash key*/
static uint16 global_FlashKeyVal = 0 ;



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
Syntax          :    void FlashDriver_Init(void)                        
Description     :    
Sync\Async      : 
Reentrancy      : 
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
void FlashDriver_Init(void)
{
	/*Key select value*/
	uint8 loc_KeySelectValue = 0 ;
	
	/*Get the key value of config register*/
	loc_KeySelectValue = (uint8)TIVAc_PERI_BIT_BAND_ALIASING((FLASHDRIVER_CONFIGURATION_BASE_ADDRESS+FLASHDRIVER_BOOTCFG_OFFSET),FLASHDRIVER_KEY_SELECT_BIT_OFFSET);

	if(!loc_KeySelectValue)
	{
		global_FlashKeyVal = 0x71D5;
	}
	else
	{
		global_FlashKeyVal = 0xA442;
	}
}
/******************************************************************************
Syntax          :   Std_ReturnType FlashDriver_Erase(uint8 BlockCount)                      
Description     :    
Sync\Async      : 
Reentrancy      : 
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
Std_ReturnType FlashDriver_Erase(uint8 BlockCount)
{
	/*Error status*/
	Std_ReturnType loc_ErrorStatus = E_OK;
	/*Counter*/
	uint8 loc_Counter = 0;
	
	
	if(global_FlashKeyVal)
	{
		/*Loop on blocks and erase*/
		for(loc_Counter=0;loc_Counter<BlockCount;loc_Counter++)
		{
			/*Flash mask address*/
			GetReg(FLASHDRIVER_BASE_ADDRESS,FLASHDRIVER_FMA_OFFSET) = FLASH_DRIVER_FMA_MASK;
			
			/*Address of the next block to erase*/
			GetReg(FLASHDRIVER_BASE_ADDRESS,FLASHDRIVER_FMA_OFFSET) = ((uint32)(FLASH_BASE_ADDRESS))+(loc_Counter*1024);
			
			/*Set erase bit in control register*/
			GetReg(FLASHDRIVER_BASE_ADDRESS,FLASHDRIVER_FMC_OFFSET) = (uint32)((global_FlashKeyVal<<16) | 0x2);
			/*Poll until it is cleared*/
			while(FLASHDRIVER_FMC_REGISTER&0x2);
		}
	}
	else
	{
		/*Set error*/
		loc_ErrorStatus = E_NOT_OK;
	}
	return loc_ErrorStatus;
}


/******************************************************************************
Syntax          :    Std_ReturnType FlashDriver_Write(static void* DataPtr,uint8 WordCount)                      
Description     :    
Sync\Async      : 
Reentrancy      : 
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
Std_ReturnType FlashDriver_Write(const void* DataPtr,uint8 WordCount)
{
	/*Error status*/
	Std_ReturnType loc_ErrorStatus = E_OK;
	/*Block count*/
	uint8 loc_BlockCount = 0;	
	/*Counter*/
	uint8 loc_Counter = 0;
	
	/*Check the flash key*/
	if(global_FlashKeyVal)
	{	
		/*Calculate the block count*/
		loc_BlockCount = ((WordCount*sizeof(uint32))/1024)+1;
		
		/*Erase the blocks*/
		loc_ErrorStatus = FlashDriver_Erase(loc_BlockCount);
		
		/*Write data words one by one*/
		for(loc_Counter=0;loc_Counter<WordCount;loc_Counter++)
		{			
			/*set the data*/
			FLASHDRIVER_FMD_REGISTER = ((volatile uint32*)DataPtr)[loc_Counter];
			
			/*Flash mask address*/
			GetReg(FLASHDRIVER_BASE_ADDRESS,FLASHDRIVER_FMA_OFFSET) = FLASH_DRIVER_FMA_MASK;
			
			/*Address of the next word to write*/
			GetReg(FLASHDRIVER_BASE_ADDRESS,FLASHDRIVER_FMA_OFFSET) = ((uint32)(FLASH_BASE_ADDRESS))+(loc_Counter*sizeof(uint32));
			
			/*Set erase bit in control register*/
			GetReg(FLASHDRIVER_BASE_ADDRESS,FLASHDRIVER_FMC_OFFSET) = (uint32)((global_FlashKeyVal<<16) | 0x1);
			
			/*Poll until it is cleared*/
			while(FLASHDRIVER_FMC_REGISTER&0x1);
			
		}	
	}
	else
	{
		/*Set error*/
		loc_ErrorStatus = E_NOT_OK;
	}
	/*Return the state*/
	return loc_ErrorStatus;
}


/******************************************************************************
Syntax          :   Std_ReturnType FlashDriver_Read(const void* DataPtr,uint8 WordCount);                    
Description     :    
Sync\Async      : 
Reentrancy      : 
Parameters (in) : 
Parameters (out):   
Return value:   : 
*******************************************************************************/
Std_ReturnType FlashDriver_Read(const void* DataPtr,uint8 WordCount)
{
	/*Error status*/
	Std_ReturnType loc_ErrorStatus = E_OK;

	/*Counter*/
	uint8 loc_Counter = 0;
	
	/*Check the flash key*/
	if(global_FlashKeyVal)
	{	
		/*Write data words one by one*/
		for(loc_Counter=0;loc_Counter<WordCount;loc_Counter++)
		{			
			/*set the data*/
			((volatile uint32*)DataPtr)[loc_Counter] = FLASH_BASE_ADDRESS[loc_Counter];			
		}	
	}
	else
	{
		/*Set error*/
		loc_ErrorStatus = E_NOT_OK;
	}
	/*Return the state*/
	return loc_ErrorStatus;	
}

/**********************************************************************************************************************
 *  END OF FILE: FlashDriver.c
 *********************************************************************************************************************/
