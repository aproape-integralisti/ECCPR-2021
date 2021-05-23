#include <bits/stdc++.h>

using namespace std;

struct xoyoz
{
	int x {};
	int y {};
	int z {};
};

double distEuc(xoyoz const &P1, xoyoz const &P2)
{
	return sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2) + pow(P1.z - P2.z, 2));
}

int main()
{
	int nrPlanets = 0;
	cin >> nrPlanets;
	vector<xoyoz> coord(nrPlanets);

	for (auto &i:coord)
	{
		cin >> i.x >> i.y >> i.z;
	}

	xoyoz racheta;
	cin >> racheta.x >> racheta.y >> racheta.z;

	double dist = 0;

	for (int i = 0; i < nrPlanets; i++)
	{
		double minDist = INT_MAX;
		int minPoz = -1;

		for (int j = 0; j < coord.size(); j++)
		{
			double currentDist = distEuc(coord[j], racheta);

			if (currentDist < minDist)
			{
				minDist = currentDist;
				minPoz = j;
			}
		}

		dist += minDist;
		racheta = coord[minPoz];
		coord.erase(coord.begin() + minPoz);
	}

	cout << fixed << setprecision(2) << dist;

	return 0;
}
