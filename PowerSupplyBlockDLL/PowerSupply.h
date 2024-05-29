#pragma once
#include "modbus.h"
#include "modbus_dev.h"

using funcConstRef = std::function<bool()> const&;

class PowerSupply: public modbus_dev
{
	public:
		int current_val{}, voltage_val{};
		int timer_val{};
		uint16_t curr_set_point{};
	//Methods
		virtual void set_timer(int t);//Set the minutes for which you want the PSU to work
		virtual bool set_current(uint16_t curr_set_pt); //Setting current setpoint
		virtual bool read_current();//Read current and voltage
		virtual bool start_up();//To start up operations by writing '1' to the control registers
		virtual bool shutdown();//Reset the setpoints and reset the control registers
		virtual bool on_off_with_timer();//Use timer to turn on the PSU and then turn it off
		virtual ~PowerSupply() = default;//Using default destructor


};

