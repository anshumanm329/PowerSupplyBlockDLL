#pragma once
#include "modbus.h"
#include <iostream>
class modbus_dev
{
	private:
		modbus_t* ctx{ nullptr };//A modbus device
		char* port{ nullptr }; //To set COM port
		int baudrate{};
		int databits{};
		int stopbits{};
		char parity{};
	public:
		//Methods
		
		virtual void set_comm_parameters(char* com_port_id, int baud, int db, int sb, char par);//To set COM port
		virtual int connect();//To establish connection
		virtual int write_register(int addr, uint16_t data);//Write data to register
		virtual int write_bit(int addr, int data);//write bit to a register
		virtual int read_holding_register(int addr);//Read data from holding register
		virtual int read_input_register(int addr);//Read data from input register
		virtual ~modbus_dev()//Destructor
		{
			modbus_free(ctx);
			delete ctx;
		}


};

