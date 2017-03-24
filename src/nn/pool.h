#pragma once
#include <string>
#include "genome.h"

class pool
{
public:
	std::vector<genome> genomes;
	int inputNeurons;
	int outputNeurons;

	pool();
	pool(const std::string &file);
	void loadfile(const std::string &file);
};
