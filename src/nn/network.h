#pragma once
#include <vector>

class neuron;

class synapse
{
private:
	neuron* source;
	double weight;

public:
	synapse(neuron* source, double weight);
	double evaluate();
};

class neuron
{
public:
	std::vector<synapse> inputs;
	double output;

	void evaluate();
};

class network
{
public:

	std::vector<neuron> neurons;

	void evaluate();
};
