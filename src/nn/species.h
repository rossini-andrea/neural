#pragma once
#include "genome.h"

class species
{
public:
	// First member is for the moment the sample gene.
	std::vector<genome> genomes;
	double averageFitness;
};
