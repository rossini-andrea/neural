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

	for (std::vector<gene>::iterator it = genes.begin(); it != genes.end(); ++it)
	{
		if (!it->enabled) continue;

		int max =
			it->destination > it->source ?
			it->destination : it->source;
		++max;

		if (network.neurons.size() < max)
		{
			network.neurons.resize(max);
		}

		network.neurons[it->destination].inputs.push_back(
			synapse(
				&network.neurons.at(it->source),
				it->weight
			)
		);
	}
}
