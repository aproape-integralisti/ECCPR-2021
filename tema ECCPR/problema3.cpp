#include <bits/stdc++.h>

using namespace std;

template<class T>
double getDeviatie(vector<T> &valori, double medie)
{
	double sumaDeviatie = 0.0;

	for (int i : valori)
	{
		sumaDeviatie += pow((medie - i), 2);
	}

	return sqrt(sumaDeviatie / valori.size());
}

template<class T>
double getMedie(vector<T> &valori)
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
	int nrRezistori;
	cin >> nrRezistori;

	vector<double> valori(nrRezistori, 0);

	for (double &i : valori)
	{
		cin >> i;
	}

	double medie = getMedie(valori);
	double deviatie = getDeviatie(valori, medie);

	double ok = 0;

	for (double &i : valori)
	{
		if (i <= (medie + deviatie) && i >= (medie - deviatie))
		{
			ok++;
		}
	}

	double proc = (ok / nrRezistori) * 100;

	cout << fixed << setprecision(2) << proc;

	return 0;
}
