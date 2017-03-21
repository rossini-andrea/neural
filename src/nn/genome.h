#pragma once

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
};
