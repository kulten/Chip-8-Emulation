#include<iostream>
#include <iomanip>
using namespace std;
void display_hex(uint8_t x, uint8_t y)
{
	cout << hex << setfill('0') << setw(2) << uppercase << (uint16_t)x << " ";
	cout << hex << setfill('0') << setw(2) << uppercase << (uint16_t)y << " ";
}
	
uint8_t get_second_bit(uint8_t x)
{
	uint8_t left_shift, right_shift;
	left_shift = (x << 4);
	right_shift = (left_shift >> 4);
	return right_shift;
}
void DisassemblerChip8(uint8_t *buffer, int size)
{
	int pc = 0;
	while (pc<size)
	{
		uint8_t *temp = &buffer[pc];
		uint8_t first = temp[0] >> 4;
		display_hex(temp[0], temp[1]);
		uint8_t second;
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
		case 0x8: 
			 second = get_second_bit(temp[1]);
			switch (second)
			{
			case 0x00: cout << " ASSIGN REG\n"; break;
			case 0x1: cout << " BITWISE OR\n"; break;
			case 0x2: cout << " BITWISE AND\n"; break;
			case 0x3: cout << " BITWISE XOR\n"; break;
			case 0x4: cout << " ADD\n"; break;
			case 0x5: cout << " SUBTRACT\n"; break;
			case 0x6: cout << " BITWISE RIGHT SHIFT\n"; break;
			case 0x7: cout << " SUBTRACT WITH BORROW\n"; break;
			case 0xe: cout << " BITWISE LEFT SHIFT\n"; break;
			}
			break;
		case 0x9: cout << " SKIP not equals REG\n"; break;
		case 0xa: cout << " MEM\n"; break;
		case 0xb: cout << " JUMP to ADDR + REG\n"; break;
		case 0xc: cout << " RAND\n"; break;
		case 0xd: cout << " DRAW\n"; break;
		case 0xe:
			switch (temp[1])
			{
			case 0x9e: cout << " KEYOP SKIP PRESSED\n"; break;
			case 0xa1: cout << " KEYOP SKIP NOT PRESSED\n"; break;
			}
			break;
		case 0xf: 
			switch (temp[1])
			{
			case 0x07: cout << " TIMER SET VALUE TO REG\n"; break;
			case 0x0a: cout << " KEYOP WAIT FOR KEY\n"; break;
			case 0x15: cout << " TIME SET VALUE\n"; break;
			case 0x18: cout << " SOUND\n"; break;
			case 0x1e: cout << " MEM ADD VX TO I\n"; break;
			case 0x29: cout << " MEM I LOCATION TO SPRITE\n"; break;
			case 0x33: cout << " BCD\n"; break;
			case 0x55: cout << " MEM REG DUMP\n"; break;
			case 0x65: cout << " MEM REG LOAD\n"; break;
			}
			break;
		default:cout << "default\n"; break;

		}
		pc = pc + 2;
	}
}