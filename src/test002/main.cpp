#include <iostream>
#include "../nn/pool.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2) return 0;

	pool pool;
	pool.loadfile(argv[1]);
	pool.genomes.at(0).generate_network();

	// Too lazy to build accessors
	pool.genomes.at(0).network.inputNeurons = 3;
	pool.genomes.at(0).network.outputNeurons = 1;

	// Test
	pool.genomes.at(0).network.neurons.at(0).output = 1.0;
	pool.genomes.at(0).network.neurons.at(1).output = 2.0;
	pool.genomes.at(0).network.neurons.at(2).output = 3.0;

	pool.genomes.at(0).network.evaluate();

	cout << "Output is: " << pool.genomes.at(0).network.neurons.at(3).output << "\n";

	return 0;
}
