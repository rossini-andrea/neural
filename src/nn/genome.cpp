#include "genome.h"

#include <algorithm>

bool compare_genes(gene i, gene j)
{
	return (i.destination < j.destination);
}

void genome::generate_network()
{
	neuralnetwork.neurons.clear();
	std::sort(genes.begin(), genes.end(), compare_genes);
	neurons = (genes.end() - 1)->destination + 1; // TODO: Put in a safer place
	neuralnetwork.neurons.resize(neurons);

	for (std::vector<gene>::iterator it = genes.begin(); it != genes.end(); ++it)
	{
		if (!it->enabled) continue;

		neuralnetwork.neurons[it->destination].inputs.push_back(
			synapse(
				it->source,
				it->weight
			)
		);
	}

	neuralnetwork.sorttopology();
}
