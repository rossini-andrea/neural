#include <cmath>
#include "classifier.h"

classifier::classifier(pool& p) :
	targetPool(p)
{

}

void classifySpecies(genome &g)
{
	for (targetPool.species::iterator it = targetPool.species.begin(); it != targetPool.species.end(); ++it)
	{
		// TODO: "first" should be "random"
		if (genomeDelta(it->genomes.first(), g) < compatibilityThreshold)
		{
			it->genomes.push_back(g);
			return;
		}
	}

	targetPool.species.resize(targetPool.species.size() + 1);
	targetPool.species.back().genomes.push_back(g);
}

void genomeDelta(genome &g1, genome &g2)
{
	int disjoint = 0, excess = 0, matches = 0;
	double weight = 0;
	g1.genes::iterator it1 = g1.genes.begin();
	g2.genes::iterator it2 = g2.genes.begin();

	while (it1 != g1.genes.end() || it2 != g2.genes.end())
	{
		if (it1 == g1.genes.end())
		{
			++excess;
			++it2;
			continue;
		}

		if (it2 == g2.genes.end())
		{
			++excess;
			++it1;
			continue;
		}

		if (it1->innovation > it2->innovation)
		{
			++disjoint;
			++it2;
			continue;
		}
		else if (it1->innovation < it2->innovation)
		{
			++disjoint;
			++it1;
			continue;
		}

		++it1;
		++it2;
		++matches;
		weight += std::abs(it1->weight - it2->weight);
	}

	int n1 = g1.genes.size();
	int n2 = g2.genes.size();

	return
		(excessCoefficient * excess + disjointCoefficient * disjoint) / (n1 > n2 ? n1 : n2) +
		(weightCoefficient * weight / matches);
}
