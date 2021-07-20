#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "IntCtrl.h"
#include "Mcu.h"
#include "Mcu_Types.h"
#include "PORT.h"
#include "Dio.h"
#include "Wdt.h"
#include "Gpt.h"
#include "FlashDriver.h"


void CallbackFunc(void);

extern const Mcu_ConfigType Mcu_State[];
extern const uint8 Mcu_PeripheralState[];
extern const Port_ConfigType PortConfig[PORT_CONFIG_SIZE];
extern const DioChannelType DioChannel;
extern const Wdt_ConfigType 	Wdt_Config;
extern const Gpt_ConfigType GptConfigArr[];


static const uint32 Arr[8] = {0xAA, 0xBB, 0x33, 0x44, 0x45, 0x456, 0x47, 0x463};



int main(void)
{
    Std_ReturnType local_uint32ErrorStatus = E_OK;

    /*Initialize MCU*/
    IntCtrl_Init();
    Mcu_Init(Mcu_State);
    local_uint32ErrorStatus = Mcu_InitClock(Mcu_PeripheralState);
    Mcu_DistributePllClock();
    Wdt_Init(&Wdt_Config);
    local_uint32ErrorStatus = PORT_Init(PortConfig);

    local_uint32ErrorStatus = Gpt_Init(GptConfigArr);
    Gpt_StartTimer(6, 4000000);
    FlashDriver_Init();

    local_uint32ErrorStatus = FlashDriver_Write(Arr, 8);

    while(1)
    {
    }
}

void CallbackFunc(void)
{
    /*Set port value*/
    Dio_WriteChannel(16, 1);
}


