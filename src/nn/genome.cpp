#include "genome.h"

#include <algorithm>

bool compare_genes(gene i, gene j)
{
	return (i.destination < j.destination);
}

void genome::generate_network()
{
	network.neurons.clear();
	std::sort(genes.begin(), genes.end(), compare_genes);
	int max = (genes.end() - 1)->destination + 1;
	network.neurons.resize(max);

	for (std::vector<gene>::iterator it = genes.begin(); it != genes.end(); ++it)
	{
		if (!it->enabled) continue;

		network.neurons[it->destination].inputs.push_back(
			synapse(
				&network.neurons.at(it->source),
				it->weight
			)
		);
	}
}
