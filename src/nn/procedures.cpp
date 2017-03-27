#include <cstdlib>
#include "procedures.h"

double sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

randomgenerator::randomgenerator()
{
	// TODO: Use C++11 or a library
	srand(time(NULL));
}

randomgenerator::reset()
{
	srand(time(NULL));
}

double newdouble()
{
	return (double)rand() / RAND_MAX;
}
