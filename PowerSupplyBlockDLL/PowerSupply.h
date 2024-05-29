#pragma once
#include "modbus.h"
#include "modbus_dev.h"
class PowerSupply: public modbus_dev
{
	public:
		int current_val{};
		uint16_t curr_set_point{};
	//Methods
		virtual bool set_current(uint16_t curr_set_pt); //Setting current setpoint
		virtual bool read_current();//Read current and voltage
		virtual bool start_up();//To start up operations by writing '1' to the control registers
		virtual bool shutdown();//Reset the setpoints and reset the control registers
		virtual ~PowerSupply() = default;//Using default destructor

};

