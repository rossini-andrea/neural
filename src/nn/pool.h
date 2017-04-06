#pragma once
#include <string>
#include "genome.h"
#include "species.h"

class pool
{
public:
	std::vector<species> allSpecies;

	int inputNeurons;
	int outputNeurons;
	int generationCount;
	int innovationIndex;

	pool();
	pool(const std::string &file);
	void loadfile(const std::string &file);
	void mutate(genome& g);
};
