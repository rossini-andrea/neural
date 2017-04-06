#include <algorithm>
#include "mutation.h"

mutation::mutation(pool& p) :
	targetPool(p)
{

}

void mutation::mutate(genome& g)
{
	// Mutation rate
	if (g.mutationrate < random.newdouble())
	{
		return;
	}

	// Weight
	if (random.newdouble() <= weightMutationChance)
	{
		mutateWeight(g);
	}

	// Enable
	if (random.newdouble() <= enableMutationChance)
	{
		mutateEnable(g, true);
	}

	// Disable
	if (random.newdouble() <= disableMutationChance)
	{
		mutateEnable(g, false);
	}

	// Link
	if (random.newdouble() <= linkMutationChance)
	{
		mutateLink(g);
	}

	// Bias
	if (random.newdouble() <= biasMutationChance)
	{
		mutateBias(g);
	}

	// Node
	if (random.newdouble() <= nodeMutationChance)
	{
		mutateNode(g);
	}
}

void mutation::mutateWeight(genome& g)
{
	int i = random.newint(0, g.genes.size() - 1);

	if (random.newbool())
	{
		g.genes.at(i)->weight *= weightMutationPower;
	}
	else
	{
		g.genes.at(i)->weight /= weightMutationPower;
	}
}

void mutation::mutateEnable(genome& g, bool enable)
{
	int i = random.newint(0, g.genes.size() - 1);
	g.genes.at(i)->enabled = enable;
}

void mutation::mutateLink(genome& g)
{
	innovationkey key;
	key.from = random.newint(0, g.neurons - 1);
	key.to = random.newint(targetPool.inputs, g.neurons - 1);
	addConnection(key);
}

void mutation::mutateBias(genome& g)
{
	innovationkey key;
	key.from = targetPool.inputs - 1;
	key.to = random.newint(targetPool.inputs, g.neurons - 1);
	addConnection(key);
}

void mutation::mutateNode(genome& g)
{
	gene& splitNode = g.genes.at(random.newint(0, g.genes.size() - 1));
	splitNode.enabled = false;
	innovationkey key;
	key.from = splitNode.from;
	key.to = g.neurons;
	gene firstHalf = makeInnovationGene(key);
	key.from = g.neurons;
	key.to = splitNode.from;
	gene secondHalf = makeInnovationGene(key);
	secondHalf.weight = splitNode.weight;
	g.genes.push_back(secondHalf);
	g.genes.push_back(firstHalf);
	++g.neurons;
}

void mutation::addConnection(innovationkey& key)
{
	for (std::vector<gene>::iterator it = g.genes.begin(); it != g.genes.end(); ++it)
	{
		if (it->source == key.from && it->destination == key.to)
		{
			it->enabled = true;
			return;
		}
	}

	g.genes.push_back(makeInnovationGene(key));
}

gene mutation::makeInnovationGene(innovationkey& key)
{
	gene newgene;
	newgene.source = key.from;
	newgene.destination = key.to;
	newgene.weight = 1;
	newgene.enabled = true;

	innovations_iterator inn = innovations.find(key);

	if (inn == innovations.end())
	{
		innovations.insert(
			std::pair<innovationkey, int>(key, ++targetPool.innovationIndex)
		);
		newgene.innovation = targetPool.innovationIndex;
	}
	else
	{
		newgene.innovation = inn->second;
	}

	return newgene;
}
