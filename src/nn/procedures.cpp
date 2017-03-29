#include <cstdlib>
#include <cmath>
#include <ctime>
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

void randomgenerator::reset()
{
	srand(time(NULL));
}

double randomgenerator::newdouble()
{
	return (double)rand() / RAND_MAX;
}

int randomgenerator::newint(int min, int max)
{
	return min + (rand() * (max - min) / RAND_MAX);
}

bool randomgenerator::newbool()
{
	return rand() & 1;
}
