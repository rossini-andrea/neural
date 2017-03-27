#pragma once
#include <string>
#include "genome.h"

class pool
{
public:
	std::vector<genome> genomes;
	int inputNeurons;
	int outputNeurons;

	double weightMutationChance;
	double linkMutationChance;
	double biasMutationChance;
	double nodeMutationChance;
	double enableMutationChance;
	double disableMutationChance;
	double weightMutationPower;

	pool();
	pool(const std::string &file);
	void loadfile(const std::string &file);
	void mutate(genome& g);
};
