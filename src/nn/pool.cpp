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
	std::getline(fs, s);

	if (s != "Genome")
	{
		return; // TODO: throw
	}

	while (!fs.eof())
	{
		genome gn;

		while (!fs.eof())
		{
			std::getline(fs, s);

			if (s == "")
			{
				continue;
			}

			// New genome found, go commit the current one.
			if (s == "Genome")
			{
				break;
			}

			gene g;
			int p;

			p = s.find(',');
			g.source = atoi(s.substr(0, p).c_str());
			p = s.erase(0, p + 1).find(',');
			g.destination = atoi(s.substr(0, p).c_str());
			p = s.erase(0, p + 1).find(',');
			g.weight = strtod(s.substr(0, p).c_str(), NULL);
			p = s.erase(0, p + 1).find(',');
			g.innovation = atoi(s.substr(0, p).c_str());
			s.erase(0, p + 1);
			g.enabled = atoi(s.substr(0, p).c_str());

			gn.genes.push_back(g);
		}

		genomes.push_back(gn);
	}
}
