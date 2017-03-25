#include <iostream>
#include "../nn/pool.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2) return 0;

	pool pool;
	pool.loadfile(argv[1]);
	pool.genomes.at(0).generate_network();

	for (int i = 0; i < pool.inputNeurons; ++i)
	{
		double d;
		cout << "Input n°" << i+1 << ": ";
		cin >> d;
		pool.genomes.at(0).neuralnetwork.neurons.at(i).output = d;
	}

	pool.genomes.at(0).neuralnetwork.evaluate();
	cout << "Output is: " << pool.genomes.at(0).neuralnetwork.neurons.at(pool.inputNeurons).output << "\n";

	return 0;
}
