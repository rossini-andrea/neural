#include <iostream>
#include "../nn/network.h"

using namespace std;

int main()
{
	network network1;

	// Add 3 test input neurons
	neuron in1;
	neuron in2;
	neuron in3;

	network1.neurons.push_back(in1);
	network1.neurons.push_back(in2);
	network1.neurons.push_back(in3);

	// Add a test output neuron
	neuron out;
	network1.neurons.push_back(out);

	// Add 2 test hidden neurons
	neuron hidden1;
	neuron hidden2;
	network1.neurons.push_back(hidden1);
	network1.neurons.push_back(hidden2);

	// Build the connections
	hidden1.inputs.push_back(synapse(&in1, 0.5));
	hidden1.inputs.push_back(synapse(&in2, 0.5));

	hidden2.inputs.push_back(synapse(&in2, 0.5));
	hidden2.inputs.push_back(synapse(&in3, 0.5));

	out.inputs.push_back(synapse(&hidden1, 0.5));
	out.inputs.push_back(synapse(&hidden2, 0.5));

	// Too lazy to build accessors
	network1.inputNeurons = 3;
	network1.outputNeurons = 1;

	// Test
	in1.output = 1.0;
	in2.output = 2.0;
	in3.output = 3.0;

	network1.evaluate();

	cout << "Output is: " << out.output << "\n";

    return 0;
}
