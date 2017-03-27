#pragma once
#include "network.h"

class gene
{
public:
	int source;
	int destination;
	double weight;
	int innovation;
	bool enabled;
};

class genome
{
public:
	std::vector<gene> genes;
	network neuralnetwork;
	double fitness;
	double mutationrate;
	void generate_network();
};
