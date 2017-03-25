#pragma once
#include <vector>

class neuron;

class synapse
{
public:
	int source;
	double weight;
	synapse(int source, double weight);
};

class neuron
{
public:
	std::vector<synapse> inputs;
	double output;
};

class network
{
public:
	int inputNeurons;
	int outputNeurons;
	std::vector<neuron> neurons;
	std::vector<int> evaluationOrder;

	void visit(int i, std::vector<int>& sorted, std::vector<bool>& marked);
	void sorttopology();
	void evaluate();
	void evaluateNeuron(neuron& which);
};
