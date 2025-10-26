#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include <iostream>
#include <ostream>
#include <string>

struct Specialization
{
	std::string code;
	std::string university;

	Specialization(std::string code, std::string university) : code(code), university(university) {}

	void print() const
	{
		std::cout << "ВУЗ: " << university << ", СПЕЦИАЛИЗАЦИЯ: " << code << std::endl;
	}
};

#endif //SPECIALIZATION_H