#include <algorithm>
#include "generation.h"

generation::generation(pool& p) :
	targetPool(p)
{

}

void generation::mutate(genome& g)
{
	// Mutation rate
	if (g.mutationrate < random.newdouble())
	{
		return;
	}

	// Weight
	if (random.newdouble() <= targetPool.weightMutationChance)
	{
		mutateWeight(g);
	}

	// Enable
	if (random.newdouble() <= targetPool.enableMutationChance)
	{
		mutateEnable(g, true);
	}

	// Disable
	if (random.newdouble() <= targetPool.disableMutationChance)
	{
		mutateEnable(g, false);
	}

	// Link
	if (random.newdouble() <= targetPool.linkMutationChance)
	{
		mutateLink(g);
	}

	// Bias
	if (random.newdouble() <= targetPool.biasMutationChance)
	{
		mutateBias();
	}

	// Node
	if (random.newdouble() <= targetPool.nodeMutationChance)
	{
		mutateNode(g);
	}
}

void generation::mutateWeight(genome& g)
{
	int i = random.newint(0, g.genes.size() - 1);

	if (random.newbool())
	{
		g.genes.at(i)->weight *= targetPool.weightMutationPower;
	}
	else
	{
		g.genes.at(i)->weight /= targetPool.weightMutationPower;
	}
}

void generation::mutateEnable(genome& g, bool enable)
{
	int i = random.newint(0, g.genes.size() - 1);
	g.genes.at(i)->enabled = enable;
}

void generation::mutateLink(genome& g)
{
	innovationkey key;
	key.from = random.newint(0, g.genes.size() - 1);
	key.to = random.newint(targetPool.inputs, (g.genes.end() - 1)->destination);

	for (std::vector<gene>::iterator it = g.genes.begin(); it != g.genes.end(); ++it)
	{
		if (it->source == key.from && it->destination == key.to)
		{
			it->enabled = true;
			return;
		}
	}

	gene newgene;
	newgene.source = key.from;
	newgene.destination = key.to;
	newgene.weight = 1;
	newgene.enabled = true;

	innovations_iterator inn = innovations.find(key);

	if (inn == innovations.end())
	{

	}
	else
	{
		newgene.innovation = inn->second;
	}
}

void generation::mutateBias(genome& g){}
void generation::mutateNode(genome& g){}
