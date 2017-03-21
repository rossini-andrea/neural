#include <cmath>
#include <vector>

#include "network.h"

double sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

synapse::synapse(neuron* source, double weight) :
	source(source),
	weight(weight)
{

}

double synapse::evaluate()
{
	return source->output * weight;
}

void neuron::evaluate()
{
	if (inputs.size() <= 0)
	{
		return;
	}

	double result = 0;

	for (std::vector<synapse>::iterator it = inputs.begin(); it != inputs.end(); ++it)
	{
		result += it->evaluate();
	}

	output = sigmoid(result);
}

void network::evaluate()
{
	int n = neurons.size();

	// Evaluate the network.
	for (int i = inputNeurons + outputNeurons; i < n; ++i)
	{
		neurons[i].evaluate();
	}

	// Evaluate outputs.
	n = inputNeurons + outputNeurons;

	for (int i = inputNeurons; i < n; ++i)
	{
		neurons[i].evaluate();
	}
}
