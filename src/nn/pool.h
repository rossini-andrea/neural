#pragma once
#include <string>
#include "genome.h"

class pool
{
public:
	pool();
	pool(const std::string &file);
	std::vector<genome> genomes;
	void loadfile(const std::string &file);
};
