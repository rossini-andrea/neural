#include <cmath>
#include <vector>

#include "network.h"

double sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

synapse::synapse(int source, double weight) :
	source(source),
	weight(weight)
{

}

void network::evaluateNeuron(neuron& which)
{
	if (which.inputs.size() <= 0)
	{
		return;
	}

	double result = 0;

	for (std::vector<synapse>::iterator it = which.inputs.begin(); it != which.inputs.end(); ++it)
	{
		result += neurons.at(it->source).output * it->weight;
	}

	which.output = sigmoid(result);
}

// Sorts nodes topologically (TODO: refactor into an algorithm)
void network::sorttopology()
{
	int n = neurons.size();
	std::vector<int> sorted;
	std::vector<bool> marked(n, false);

	for (int i = 0; i < n; ++i)
	{
		visit(i, sorted, marked);
	}

	evaluationOrder = sorted;
}

// Visits nodes for the sort operation (TODO: refactor into an algorithm)
void network::visit(int i, std::vector<int>& sorted, std::vector<bool>& marked)
{
	if (marked[i])
	{
		return;
	}

	marked[i] = true;

	for (
		std::vector<synapse>::iterator it = neurons[i].inputs.begin();
		it != neurons[i].inputs.end();
		++it
	)
	{
		visit(it->source, sorted, marked);
	}

	sorted.push_back(i);
}

void network::evaluate()
{
	for (std::vector<int>::iterator it = evaluationOrder.begin(); it != evaluationOrder.end(); ++it)
	{
		evaluateNeuron(neurons[*it]);
	}
}
