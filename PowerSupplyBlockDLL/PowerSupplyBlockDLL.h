// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the POWERSUPPLYBLOCKDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// POWERSUPPLYBLOCKDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef POWERSUPPLYBLOCKDLL_EXPORTS
#define POWERSUPPLYBLOCKDLL_API __declspec(dllexport)
#else
#define POWERSUPPLYBLOCKDLL_API __declspec(dllimport)
#endif
#include "modbus.h"
#include "modbus_dev.h"
#include "PowerSupply.h"
#include "StepMotor.h"

// This class is exported from the dll
class POWERSUPPLYBLOCKDLL_API CPowerSupplyBlockDLL {

public:

	CPowerSupplyBlockDLL(void);
	PowerSupply psu1{};
	StepMotor motor1{};
	//Methods
	bool powersupply_connect(PowerSupply psu1); // Creates a modbus instance of the power supply block
	bool powersupply_turn_on(PowerSupply psu1); // Writes to the necessary registers to make the PSU ready for operation
	bool powersupply_turn_on_with_timer(PowerSupply psu1, int t);// Turn on using time limit provided by user
	bool powersupply_set_setpoints(PowerSupply psu1, uint16_t current_set_point); //To write the current and voltage setpoints to necessary registers
	bool powersupply_get_values(PowerSupply psu1); //To get the current readback
	bool stepmotor_connect(StepMotor motor1); //Connect to the stepmotor through relay
	bool stepmotor_forward(StepMotor motor1); //Step motor forward motion
	bool stepmotor_reverse(StepMotor motor1); //Step motor reverse motion
	bool stepmotor_stop(StepMotor motor1); //Stop the motion
	bool stepmotor_is_fully_open(StepMotor motor1); //Check for fully open 
	bool stepmotor_is_fully_closed(StepMotor motor1); //Check for fully closed
};

extern POWERSUPPLYBLOCKDLL_API int nPowerSupplyBlockDLL;


