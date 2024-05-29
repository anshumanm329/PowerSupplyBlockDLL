// PowerSupplyBlockDLL.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "PowerSupplyBlockDLL.h"


// This is an example of an exported variable
POWERSUPPLYBLOCKDLL_API int nPowerSupplyBlockDLL=0;

// This is an example of an exported function.
POWERSUPPLYBLOCKDLL_API int fnPowerSupplyBlockDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.

CPowerSupplyBlockDLL::CPowerSupplyBlockDLL(void)
{
}
extern "C" {
    bool CPowerSupplyBlockDLL::powersupply_connect(PowerSupply psu1) {
        if (psu1.connect() == -1)
            return false; //Установление связи прошло неуспешно
        else if (psu1.connect() == 0)
            return true; //Связь установлена
    }
    bool CPowerSupplyBlockDLL::powersupply_turn_on(PowerSupply psu1) {
        if (psu1.start_up())
            return true; // Блок запущн
        else
            return false; // Блок незапущен
    }

    bool CPowerSupplyBlockDLL::powersupply_set_setpoints(PowerSupply psu1, uint16_t current_set_point) {
        if (psu1.set_current(current_set_point))
            return true;
        else
            return false;
    }
    bool CPowerSupplyBlockDLL::powersupply_get_values(PowerSupply psu1) {
        if (psu1.read_current())
            return true;
        else
            return false;
    }
    bool CPowerSupplyBlockDLL::stepmotor_connect(StepMotor motor1) {
        if (motor1.connect())
            return true;// Связь установлена
        else
            return false; //Связь не установлена

    }
    bool CPowerSupplyBlockDLL::stepmotor_forward(StepMotor motor1) {
        if (motor1.forward())
            return true;
        else
            return false;
    }
    bool CPowerSupplyBlockDLL::stepmotor_reverse(StepMotor motor1) {
        if (motor1.reverse())
            return true;
        else
            return false;
    }
    bool CPowerSupplyBlockDLL::stepmotor_stop(StepMotor motor1){
        if (motor1.stop())
            return true;
        else
            return false;
    }
}
