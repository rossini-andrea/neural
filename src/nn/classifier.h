#pragma once

class classifier
{
private:
	pool& targetPool;
public:
	classifier(pool& p);
	void classifySpecies();
}
