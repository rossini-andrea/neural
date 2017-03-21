#include <iostream>
#include "../nn/pool.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (!argc) return 0;

	pool pool;
	pool.loadfile(argv[0]);

	// Too lazy to build accessors
	pool.genomes[0].network.inputNeurons = 3;
	pool.genomes[0].network.outputNeurons = 1;

	// Test
	pool.genomes[0].network.neurons.at(0).output = 1.0;
	pool.genomes[0].network.neurons.at(1).output = 2.0;
	pool.genomes[0].network.neurons.at(2).output = 3.0;

	pool.genomes[0].network.evaluate();

	cout << "Output is: " << pool.genomes[0].network.neurons.at(3).output << "\n";

	return 0;
}
