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
	std::ifstream fs(file.c_str());
	std::string s;

	// Consume first line
	std::getline(fs, s, ',');

	if (s != "Genome")
	{
		return; // TODO: throw
	}

	while (!fs.eof())
	{
		genome gn;

		while (!fs.eof())
		{
			std::getline(fs, s, ',');

			// New genome found, go commit the current one.
			if (s == "Genome")
			{
				break;
			}

			gene g;
			g.source = atoi(s.c_str());
			std::getline(fs, s, ',');
			g.destination = atoi(s.c_str());
			std::getline(fs, s, ',');
			g.weight = strtod(s.c_str(), NULL);
			std::getline(fs, s, ',');
			g.innovation = atoi(s.c_str());
			std::getline(fs, s, ',');
			g.enabled = atoi(s.c_str());
			gn.genes.push_back(g);
		}

		genomes.push_back(gn);
	}
}
