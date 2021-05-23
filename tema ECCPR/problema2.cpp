#include <bits/stdc++.h>

using namespace std;

int findMax(vector<int> const &valori, double medie)
{
	double maxDist = INT_MIN;
	int maxPos = 0;

	for (int i = 0; i < valori.size(); i++)
	{
		double currentDist = 0.0;

		currentDist = abs(medie - valori[i]);

		if (currentDist > maxDist)
		{
			maxDist = currentDist;
			maxPos = i;
		}
	}

	return maxPos;
}

double getDeviatie(vector<int> const &valori, double medie)
{
	double sumaDeviatie = 0.0;

	for (int i : valori)
	{
		sumaDeviatie += pow((medie - i), 2);
	}

	return sqrt(sumaDeviatie / valori.size());
}

double getMedie(vector<int> const &valori)
{
	double sumaMedie = 0.0;

	for (int i : valori)
	{
		sumaMedie += i;
	}

	return sumaMedie / valori.size();
}

int main()
{
	int nrValori;
	cin >> nrValori;

	vector<int> valori(nrValori, 0);

	for (int i = 0; i < nrValori; i++)
	{
		cin >> valori[i];
	}

	double medie = getMedie(valori);
	double deviatie = getDeviatie(valori, medie);

	int errorNr = 0;

	while (deviatie / medie >= 0.1)
	{
		errorNr++;

		int errorPos = findMax(valori, medie);

		valori.erase(valori.begin() + errorPos);
		nrValori--;

		medie = getMedie(valori);
		deviatie = getDeviatie(valori, medie);
	}

	cout << errorNr;

	return 0;
}