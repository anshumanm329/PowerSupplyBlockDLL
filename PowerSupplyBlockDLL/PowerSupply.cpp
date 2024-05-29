#include "PowerSupply.h"

	
extern "C" {
	bool PowerSupply::set_current(uint16_t curr_set_pt)
	{
		curr_set_point = curr_set_pt;
		//To set the current set point to user defined value and the voltage set point to 600
		if (PowerSupply::write_register(18, curr_set_pt) == -1)
			return false;//Failed to set current setpoint
		if (PowerSupply::write_register(19, 600) == -1)
			return false;//Failed to set voltage setpoint
		return true;
	}

	bool PowerSupply::read_current()
	{
		current_val = PowerSupply::read_input_register(20);
		if (current_val == -1) {
			current_val = 0;
			return false;//Failed to read current value
		}
		//If the function executed correctly, then current_val stays as it is
		return true;//Function executed correctly

	}

	bool PowerSupply::start_up() {
		if (PowerSupply::write_register(36, 0) == -1) // Обнуляется регистр ЗП 
			return false;
		//To set the bits 272 and 273 to 1
		if (PowerSupply::write_bit(272, 1) == -1) // питание подключается
			return false; //Failed to set 272 to 1
		if (PowerSupply::write_bit(273, 1) == -1) // Затем подключается "пуск"
			return false; //Failed to set 273 to 1

		return true; //Reset the ZP register and then set 272 and 273 to '1'
	}
	bool PowerSupply::shutdown() {
		if (PowerSupply::write_register(18, 0) == -1)
			return false;//Failed to reset current setpoint
		if (PowerSupply::write_register(19, 0) == -1)
			return false;//Failed to reset voltage setpoint
		if (PowerSupply::write_bit(273, 0) == -1)
			return false;//Failed to reset work mode
		if (PowerSupply::write_bit(272, 0) == -1)
			return false;
	}
}