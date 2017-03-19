#pragma once

class gene
{
public:
	int from;
	int to;
	double weight;
	int evolution;
	bool enabled;
};

class genome
{
public:
	std::vector<gene> genes;
};
