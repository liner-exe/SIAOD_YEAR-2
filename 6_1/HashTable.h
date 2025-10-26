#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <vector>

#include "Specialization.h"

using Bucket = std::list<Specialization>;

class HashTable
{
	std::vector<Bucket> table;
	size_t size;
	size_t capacity;
	const double MAX_LOAD_FACTOR = 0.75;
	std::string CHAIN_DELIMITER = " -> ";

	unsigned int hashFunction(const std::string& key);

	void rehash();
public:
	HashTable(int initialCapacity = 8) : size(0), capacity(initialCapacity)
	{
		table.resize(capacity);
	}

	void insert(const std::string& code, const std::string& university);
	void remove(const std::string& code);
	void search(const std::string& code);
	void display() const;

	void autofill();
};

#endif //HASHTABLE_H