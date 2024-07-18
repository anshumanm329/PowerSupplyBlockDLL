#include "StepMotor.h"

extern "C" {
	// Function definitions
	bool StepMotor::forward() {
		if (StepMotor::read_holding_register(514) != 1) {
			//�������� �� �������, ����� ��������� ������
			int rc1 = StepMotor::write_register(512, 1);
			int rc2 = StepMotor::write_register(513, 0);
			if (rc1 == -1 || rc2 == -1)
				return false; //Writing values to registers failed
			return true; //Writing successful			
		}
		else {
			//Display message: �������� �������
			if (StepMotor::stop())
				return false;//�������� �������, �������� �� �������� ������
			return false; //������������ �������� ���������
		}
	}

	bool StepMotor::reverse() {
		if (StepMotor::read_holding_register(515) != 1) {
			// �������� ���� �� �������, ����� ������� ���������
			int rc1 = StepMotor::write_register(512, 1);
			int rc2 = StepMotor::write_register(513, 1);
			// Sets conditions for the reverse motion
			if (rc1 == -1 || rc2 == -1)
				return false;// Error: ������ ���������
			return true;
		}
		else {
			if (StepMotor::stop())
				return false; // �������� �������, ������ ��������� �� �����
			return false; // ������������ �������� ���������
		}
	}
	bool StepMotor::stop()
	{
		int rc1 = StepMotor::write_register(512, 0);
		int rc2 = StepMotor::write_register(513, 1);
		if (rc1 == -1 || rc2 == -1)
			return false; //������ ���������
		return true; //�������� �����������
			
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
