#include <bits/stdc++.h>

using namespace std;

struct tara
{
	string nume {};
	int durata;
};

int main()
{
	string aux;

	vector<tara> programari;
	map<string, int> progr;
	string nume;
	int durata;
	while (getline(cin, aux, '\n'))
	{
		nume = aux.substr(0, aux.rfind(' '));
		durata = stoi(aux.substr(aux.rfind(' ') + 1));

		if (progr.find(nume) != progr.end())
		{
			if (progr[nume] < durata)
			{
				progr[nume] = durata;
			}
		}
		else
		{
			if (durata < 10 || durata > 60)
			{
				continue;
			}
			progr[nume] = durata;
		}
	}
	double sumaDisc = 0;
	int nr = 0;

	for (auto &i : progr)
	{
		sumaDisc += i.second;
		nr++;
	}

	vector<pair<string, int>> forSort;
	for (auto &i : progr)
	{
		forSort.emplace_back(i);
	}

	sort(forSort.begin(), forSort.end(), [](auto l, auto r)
	{
		if (l.second == r.second)
		{
			return l.first < r.first;
		}
		return l.second > r.second;
	});

	if (sumaDisc > 8 * 60)
	{
		while (sumaDisc > 8 * 60)
		{
			sumaDisc -= forSort[0].second;
			nr--;
			forSort.erase(forSort.begin());
		}

		for (const auto &i:forSort)
		{
			cout << i.first << "," << i.second << endl;
		}
		cout << sumaDisc << " " << fixed << setprecision(2) << sumaDisc / nr;

		return 0;
	}

	for (const auto &i:forSort)
	{
		cout << i.first << "," << i.second << endl;
	}
	cout << sumaDisc << " " << fixed << setprecision(2) << sumaDisc / nr;

	return 0;
}
