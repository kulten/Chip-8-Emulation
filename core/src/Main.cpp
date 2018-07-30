#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream file("C:/Users/Skinet/Desktop/Chip-8-Emulation/core/src/Fishie.ch8",ios::binary);
	if (!file.is_open())
	{
		cout << "Error";
	}
	else
	{
		cout.width(2);
		cout.fill('0');
		file.seekg(0, ios::end);
		streamoff size = file.tellg();
		file.seekg(0, ios::beg);
		char *buffer = new char[size];
		file.read(buffer, size);
		file.close();
		for (int i = 0; i < size; i++)
		{
			cout <<hex<< (unsigned int)(unsigned char)buffer[i] << " ";
		}
		delete[] buffer;
	}
	cin.get();
}