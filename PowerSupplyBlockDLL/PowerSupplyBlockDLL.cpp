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

    bool CPowerSupplyBlockDLL::powersupply_turn_on_with_timer(PowerSupply psu1, int t) 
    {
        
        //Here it is assumed that the value of 't' is given by the user
        // set the timer value
        if (t>0) {
            psu1.set_timer(t); //The timer is set
        }
        else
            return false; // timer value can't be zero or negative (Give error message)
        //Proceeding with a set timer
        if (psu1.on_off_with_timer())
            return true; // The operation worked as intended
        else
            return false; // Error: Turning on with timer failed!
                          // Check for the reason it returned false and give appropriate error message
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
    bool CPowerSupplyBlockDLL::stepmotor_is_fully_open(StepMotor motor1)
    {
        if (motor1.is_fully_open())
            return true;
        else
            return false;
    }
    bool CPowerSupplyBlockDLL::stepmotor_is_fully_closed(StepMotor motor1)
    {
        if (motor1.is_fully_closed())
            return true;
        else
            return false;
    }
}
