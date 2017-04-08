#pragma once

class classifier
{
private:
	pool& targetPool;
public:
	double compatibilityThreshold;
	double excessCoefficient;
	double disjointCoefficient;
	double weightCoefficient;

	classifier(pool& p);
	void classifySpecies();
	double genomeDelta(genome &g1, genome &g2);
};
