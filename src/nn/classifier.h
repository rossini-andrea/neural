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
}
