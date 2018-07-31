#include<iostream>
using namespace std;
void DisassemblerChip8(uint8_t *buffer, int size)
{
	int pc = 0;
	while (pc<size)
	{
		uint8_t *temp = &buffer[pc];
		uint8_t first = temp[0] >> 4;
		cout << (int)pc << " ";
		cout << hex << (uint16_t)temp[0] << " " << (uint16_t)temp[1];
		switch (first)
		{
		case 0x00:
			switch (temp[1])
			{
			case 0xe0: cout << " CLR \n"; break;
			case 0xee: cout << " RTS \n"; break;
			default: cout << " NOP\n"; break;
			}
			break;
		case 0x1: cout << " JUMP to ADDR\n"; break;
		case 0x2: cout << " JUMP to sub\n"; break;
		case 0x3: cout << " SKIP equals NN\n"; break;
		case 0x4: cout << " SKIP not equals NN\n"; break;
		case 0x5: cout << " SKIP equals REG\n"; break;
		case 0x6: cout << " MVI\n"; break;
		case 0x7: cout << " ADD to REG\n"; break;
		case 0x8: cout << " unimplemented 8\n"; break;
		case 0x9: cout << " SKIP not equals REG\n"; break;
		case 0xa: cout << " MEM\n"; break;
		case 0xb: cout << " JUMP to ADDR + REG\n"; break;
		case 0xc: cout << " RAND\n"; break;
		case 0xd: cout << " DRAW\n"; break;
		case 0xe: cout << " unimplemented e\n"; break;
		case 0xf: cout << " unimplemented f\n"; break;
		default:cout << "default\n"; break;

		}
		pc = pc + 2;
	}
}