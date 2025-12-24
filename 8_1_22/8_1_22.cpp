#include "Huffman.h"
#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::cout << "Алгоритм Хаффмана\n";

	std::string filename;
	std::cout << "Введите имя файла: ";
	std::getline(std::cin, filename);

	std::string original = readFile(filename);

	HuffmanCoder coder;
	std::string compressed = coder.compress(original);
	writeFile("compressed.bin", compressed);

	std::string restored = coder.decompress(compressed);
	writeFile("decompressed.txt", restored);

	std::cout << "Сжатие завершено\n";
	std::cout << "Сжатый файл: compressed.bin\n";
	std::cout << "Восстановленный файл: decompressed.txt\n";

	if (original == restored)
		std::cout << "Оригинальный файл совпадает с восстановленным.\n";
	else
		std::cout << "Ошибка восстановления.\n";

	return 0;
}
