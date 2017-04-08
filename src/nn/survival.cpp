#include <algorithm>
#include "survival.h"

survival::survival(pool& p) :
	targetPool(p)
{

}

void survival::performSelection()
{
	// Update fitness for species.
	updateFitness();

	// Remove unfit genomes.
	removeGenomes();

	// Update fitness for species **again**.
	updateFitness();

	// Remove unfit species.
	removeSpecies();

	// Update average pool fitness.
	updatePoolFitness();
}

bool compareGenomes(genome& i, genome& j)
{
  return (i.fitness > j.fitness);
}

bool compareSpecies(species& i, species& j)
{
  return (i.averageFitness > j.averageFitness);
}

void updateFitness()
{
	for (targetPool.species::iterator s = targetPool.species.begin(); s != targetPool.species.end(); ++s)
	{
		std::sort(s->genomes.begin(), s->genomes.end(), compareGenomes);
		double fitness(0);

		for (s->genomes::iterator g = s->genomes.begin(); g != s->genomes.end(); ++g)
		{
			fitness += g->fitness;
		}

		s->averageFitness = fitness / s->genomes.size();
	}

	std::sort(targetPool.species.begin(), targetPool.species.end(), compareSpecies);
}

void survival::updatePoolFitness()
{
	double poolFitness(0);

	for (targetPool.species::iterator s = targetPool.species.begin(); s != targetPool.species.end(); ++s)
	{
		poolFitness += s->averageFitness;
	}

	targetPool.averageFitness = poolFitness / targetPool.species.size();
}

void removeGenomes()
{
	for (targetPool.species::iterator s = targetPool.species.begin(); s != targetPool.species.end(); ++s)
	{
		if (s->genomes.size() > maxGenomesPerSpecies)
		{
			s->genomes.resize(maxGenomesPerSpecies);
		}
	}
}

void removeSpecies()
{
	if (targetPool.species.size() <= maxSpecies) return;

	targetPool.species.resize(maxSpecies);
}
