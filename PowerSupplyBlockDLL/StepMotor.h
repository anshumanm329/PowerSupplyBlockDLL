#pragma once
#include "modbus.h"
#include "modbus_dev.h"
class StepMotor: public modbus_dev
{
	private:
		// No private members
	public:
		// Only methods
		virtual bool forward();// Forward motion
		virtual bool reverse(); // Reverse motion
		virtual bool stop(); //Stop motion
		virtual ~StepMotor() = default; // Default virtual destructor

};

