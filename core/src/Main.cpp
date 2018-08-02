#include <iostream>
#include <fstream>
#include <iomanip>
#include "chip8.h"
using namespace std;
int main()
{
	ifstream file("C:/Users/Skinet/Desktop/Chip-8-Emulation/core/src/pong.rom",ios::binary);
	if (!file.is_open())
	{
		cout << "Error";
	}
	else
	{
		file.seekg(0, ios::end);
		int size = (int)file.tellg();
		file.seekg(0, ios::beg);
		char *temp_buffer = new char[size];
		file.read(temp_buffer, size);
		file.close();
		uint8_t *buffer = new uint8_t[size];
		for (int i = 0; i < size; i++)
		{
			buffer[i] = (uint8_t)temp_buffer[i];
		}
		delete[] temp_buffer;
		DisassemblerChip8(buffer, size);
		delete[] buffer;

	}
	cin.get();
}