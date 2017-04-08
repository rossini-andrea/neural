#pragma once
#include "pool.h"

class survival
{
private:
	pool& targetPool;

	void updateFitness();
	void updatePoolFitness();
	void removeGenomes();
	void removeSpecies();

public:
	int maxGenomesPerSpecies;
	int maxSpecies;

	survival(pool& p);
	void performSelection();
};
