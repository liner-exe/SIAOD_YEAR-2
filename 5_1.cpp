#include <iostream>

void task1_a()
{
	unsigned char x = 255;
	unsigned char mask = 1;
	x = x & (~(mask << 4));
	std::cout << (int)x << std::endl;
}

void task1_b()
{
	unsigned char x = 0;
	x = x | (1 << 6);
	std::cout << (int)x << std::endl;
}

void task1_c()
{

}

void task2_a()
{
	unsigned char bitmask = 0;
	int n, x;
	std::cout << "Введите количество чисел (<=8): ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		bitmask |= (1 << x);
	}

	std::cout << "Отсортированная последовательность: ";
	for (int i = 0; i < 8; i++)
	{
		if (bitmask & (1 << i))
			std::cout << i << " ";
	}
}

void task2_b()
{
	unsigned long long bitmask = 0;
	int n, x;
	std::cout << "Введите количество чисел (<=8): ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		bitmask |= (1ULL << x);
	}

	std::cout << "Отсортированная последовательность: ";
	for (int i = 0; i < 8; i++)
	{
		if (bitmask & (1 << i))
			std::cout << i << " ";
	}
}

int main()
{
	short taskNumber;
	std::cin >> taskNumber;

	switch (taskNumber)
	{
		case 1:
			task1_a();
			break;
		case 2:
			task1_b();
			break;
	}
}