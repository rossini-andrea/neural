#pragma once

double sigmoid(double x);

class randomgenerator
{
public:
	randomgenerator();
	void reset();
	double newdouble();
	int newint(int min, int max);
	bool newbool();
};

