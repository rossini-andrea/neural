#include <iostream>
#include "../nn/network.h"

using namespace std;

int main()
{
	network network1;

	// Add 3 test input neurons,
	// a test output neuron and
	// 2 test hidden neurons
	network1.neurons.resize(6);

	// Build the connections
	network1.neurons.at(4).inputs.push_back(synapse(&network1.neurons.at(0), 0.5));
	network1.neurons.at(4).inputs.push_back(synapse(&network1.neurons.at(1), 0.5));

	network1.neurons.at(5).inputs.push_back(synapse(&network1.neurons.at(1), 0.5));
	network1.neurons.at(5).inputs.push_back(synapse(&network1.neurons.at(2), 0.5));

	network1.neurons.at(3).inputs.push_back(synapse(&network1.neurons.at(4), 0.5));
	network1.neurons.at(3).inputs.push_back(synapse(&network1.neurons.at(5), 0.5));

	// Too lazy to build accessors
	network1.inputNeurons = 3;
	network1.outputNeurons = 1;

	// Test
	network1.neurons.at(0).output = 1.0;
	network1.neurons.at(1).output = 2.0;
	network1.neurons.at(2).output = 3.0;

	network1.evaluate();

	cout << "Output is: " << network1.neurons.at(3).output << "\n";

    return 0;
}
