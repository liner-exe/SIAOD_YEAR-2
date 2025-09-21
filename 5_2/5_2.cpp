#include <bitset>
#include <iostream>
#include <windows.h>

void task_1()
{
	unsigned int x;

	x = 0xFFFFFFFF;
	unsigned int mask = 0xFFFFFF87;
	unsigned int result1 = x & mask;
	unsigned int result2 = x & ~((1 << 3) | (1 << 4) | (1 << 5) | (1 << 6));

	std::cout << "Задача 1 (обнуление): " << std::endl;
	std::cout << "result1 = 0x" << std::hex << result1 << " (" << std::bitset<32>(result1) << ")" << std::endl;
	std::cout << "result2 = 0x" << std::hex << result2 << " (" << std::bitset<32>(result2) << ")" << std::endl;
}

void task_2()
{
	unsigned int x = 0x0;
	unsigned int mask = 0x1802;
	unsigned int result1 = x | mask;
	unsigned int result2 = x | ((1 << 12) | (1 << 11) | (1 << 1));

	std::cout << "Задача 2 (установка): " << std::endl;
	std::cout << "result1 = 0x" << std::hex << result1 << " (" << std::bitset<32>(result1) << ")" << std::endl;
	std::cout << "result2 = 0x" << std::hex << result2 << " (" << std::bitset<32>(result2) << ")" << std::endl;
}

void task_3()
{
	unsigned int x = 7;
	unsigned int result = x << 5;

	std::cout << "Задача 3 (умножение): " << std::endl;
	std::cout << std::dec << x << " * 32 = " << result << std::endl;
}

void task_4()
{
	unsigned int x = 1024;
	unsigned int result = x >> 5;

	std::cout << "Задача 4 (деление): " << std::endl;
	std::cout << std::dec << x << " / 32 = " << result << std::endl;
}
void task_5()
{
	unsigned int x = 0xAAAAAAAA;
	unsigned int mask = 0x20020014;
	unsigned int result1 = x ^ mask;
	unsigned int result2 = x ^ ((1 << 2) | (1 << 17) | (1 << 4) | (1 << 29));

	std::cout << "Задача 5 (инверсия): " << std::endl;
	std::cout << "result1 = 0x" << std::hex << result1 << " (" << std::bitset<32>(result1) << ")" << std::endl;
	std::cout << "result2 = 0x" << std::hex << result2 << " (" << std::bitset<32>(result2) << ")" << std::endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(CP_UTF8);

	// task_1();
	// task_2();
	// task_3();
	// task_4();
	// task_5();

	return 0;
}