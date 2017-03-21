#include "pool.h"
#include <cstdlib>
#include <fstream>

pool::pool()
{

}

pool::pool(const std::string &file)
{
	loadfile(file);
}

void pool::loadfile(const std::string &file)
{
	std::fstream fs(file, std::fstream::in);
	std::string s;
// TODO test eofbit
	while (1)
	{
		genome gn;

		while (std::getline(fs, s, ','))
		{
			if (s == "Genome")
			{
				break;
			}

			gene g;
			g.source = atoi(s);
			std::getline(fs, s, ',');
			g.destination = atoi(s);
			std::getline(fs, s, ',');
			g.weight = strtod(s);
			std::getline(fs, s, ',');
			g.innovation = atoi(s);
			std::getline(fs, s, ',');
			g.enabled = atoi(s);
			gn.genes.push_back(g);
		}

		genomes.push_back(gn);
	}
}
