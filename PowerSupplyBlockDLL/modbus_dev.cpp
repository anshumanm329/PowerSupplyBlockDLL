#include "modbus_dev.h"
#include <iostream>


extern "C" {
	//Wrapper functions

	void modbus_dev::set_comm_parameters(char* com_port_id, int baud, int db, int sb, char par) {
		port = com_port_id;
		baudrate = baud;
		databits = db;
		stopbits = sb;
		parity = par;
		//Create a messagebox from where the COM port and the other parameters can be chosen
	}

	int modbus_dev::connect()
	{
		ctx = modbus_new_rtu(port, baudrate, parity, databits, stopbits);//To create instance
		if (ctx == nullptr) {
			return -1;//Failed to create instance
		}
		modbus_set_slave(ctx, 1); //Set slave id
		if (modbus_connect(ctx) == -1)
			return -1;//Dialogue box: Connection failed
		return 0;//Connection established
	}
	int modbus_dev::write_register(int addr, uint16_t data) {
		//To write data to modbus device
		if (modbus_write_register(ctx, addr, data) == -1) {
			return -1; //Writing failed
		}
		return 0;//Writing successful (Message box; show that data was written to register at addr)
	}
	int modbus_dev::write_bit(int addr, int data) {
		//To write a bit to modbus register
		// int data can only be 0 or 1
		if (modbus_write_bit(ctx, addr, data) == -1)
			return -1;//Setting bit failed
		return 0;//Writing successful, return that register at "addr" has been set to "data"
	}
	int modbus_dev::read_holding_register(int addr) {
		//Reads a register at int addr
		uint16_t readbacks[100]{};
		if (modbus_read_registers(ctx, addr, 1, readbacks) == -1)
			return -1;//Reading failed
		return static_cast<int>(readbacks[0]);//Returns the value that was read
	}
	int modbus_dev::read_input_register(int addr) {
		uint16_t readbacks[100]{};
		if (modbus_read_input_registers(ctx, addr, 1, readbacks) == -1)
			return -1;//Reading failed
		return static_cast<int>(readbacks[0]);//Returns the value that was read at address
	}

}