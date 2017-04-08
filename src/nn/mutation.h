#pragma once
#include <map>
#include "pool.h"
#include "genome.h"
#include "procedures.h"

class innovationkey
{
	int from;
	int to;
};

class mutation
{
private:
	randomgenerator random;
	pool& targetPool;
	std::map<innovationkey, int> innovations;
	typedef std::map<innovationkey, int>::iterator innovations_iterator;

	void mutateWeight(genome& g);
	void mutateEnable(genome& g, bool enable);
	void mutateLink(genome& g);
	void mutateBias(genome& g);
	void mutateNode(genome& g);
	gene makeInnovationGene(innovationkey& key);
	void addConnection(innovationkey& key);

public:
	double weightMutationChance;
	double linkMutationChance;
	double biasMutationChance;
	double nodeMutationChance;
	double enableMutationChance;
	double disableMutationChance;
	double weightMutationPower;

	mutation(pool& p);
	void mutate(genome& g);
};
