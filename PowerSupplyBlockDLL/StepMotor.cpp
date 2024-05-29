#include "StepMotor.h"

extern "C" {
	// Function definitions
	bool StepMotor::forward() {
		if (StepMotor::read_holding_register(514) != 1) {
			//Заслонка не открыта, можно двигаться дальше
			int rc1 = StepMotor::write_register(512, 1);
			int rc2 = StepMotor::write_register(513, 0);
			if (rc1 == -1 || rc2 == -1)
				return false; //Writing values to registers failed
			return true; //Writing successful			
		}
		else {
			//Display message: Заслонка открыта
			if (StepMotor::stop())
				return false;//Заслонка открыта, двитаель не движется дальше
			return false; //Остановление движение неуспешно
		}
	}

	bool StepMotor::reverse() {
		if (StepMotor::read_holding_register(515) != 1) {
			// Заслонка пока не закрыта, можно обратно двигаться
			int rc1 = StepMotor::write_register(512, 1);
			int rc2 = StepMotor::write_register(513, 1);
			// Sets conditions for the reverse motion
			if (rc1 == -1 || rc2 == -1)
				return false;// Error: Запись неуспешна
			return true;
		}
		else {
			if (StepMotor::stop())
				return false; // Заслонка закрыта, дальше двигаться не будет
			return false; // Остановление движение неуспешно
		}
	}
	bool StepMotor::stop()
	{
		int rc1 = StepMotor::write_register(512, 0);
		int rc2 = StepMotor::write_register(513, 1);
		if (rc1 == -1 || rc2 == -1)
			return false; //Запись неуспешна
		return true; //Движение остановлено
			
	}
	bool StepMotor::is_fully_open() {
		if (StepMotor::read_holding_register(514) == 1)
			return true;
		else
			return false;
	}
	bool StepMotor::is_fully_closed() {
		if (StepMotor::read_holding_register(515) == 1)
			return true;
		else
			return false;
	}
}
