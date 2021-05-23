#include <bits/stdc++.h>

using namespace std;

struct info
{
	int nrBil {};
	int idx {};
};

int main()
{
	string cerinta;
	cin >> cerinta;

	if (cerinta == "a")
	{
		int tranz;
		cin >> tranz;

		int inx = 0;
		unordered_map<string, info> festival;
		for (int i = 0; i < tranz; i++)
		{
			string aux;
			cin >> aux;

			string nume = aux.substr(0, aux.find(','));
			int nrBil = stoi(aux.substr(aux.find(',') + 1));

			if (festival.find(nume) == festival.end())
			{
				inx++;
				festival[nume].idx = inx;
			}
			festival[nume].nrBil += nrBil;
		}

		vector<pair<string, info>> afis;

		for (const auto &i:festival)
		{
			if (i.second.nrBil >= 5)
			{
				afis.emplace_back(i);
			}
		}

		sort(afis.begin(), afis.end(), [](auto l, auto r)
		{
			return l.second.idx < r.second.idx;
		});

		for (auto &afi : afis)
		{
			cout << afi.first << ", " << afi.second.nrBil << endl;
		}
	}
	else if (cerinta == "b")
	{
		int nrZile;
		cin >> nrZile;

		vector<string> populare;
		vector<string> medii;
		vector<string> joase;

		string aux;
		string nume;
		getline(cin, aux, '\n');
		while (getline(cin, aux, '\n'))
		{
			nume = aux.substr(0, aux.find(','));
			int pop = stoi(aux.substr(aux.find(',') + 1));

			if (pop == 1)
			{
				populare.push_back(nume);
			}
			else if (pop == 2)
			{
				medii.push_back(nume);
			}
			else if (pop == 3)
			{
				joase.push_back(nume);
			}
		}

		while (nrZile > 0)
		{
			nrZile--;
			if (!populare.empty())
			{
				cout << populare[0] << " ";
				populare.erase(populare.begin());
			}
			if (!medii.empty())
			{
				cout << medii[0] << " ";
				medii.erase(medii.begin());
			}
			if (!joase.empty())
			{
				cout << joase[0];
				joase.erase(joase.begin());
			}
			cout << endl;
		}
	}
	else if (cerinta == "c")
	{
		int T;
		cin >> T;
		vector<string> formatii(T);
		for (auto &i:formatii)
		{
			cin >> i;
		}
		sort(formatii.begin(), formatii.end());
		for (auto &i:formatii)
		{
			cout << i << endl;
		}
	}

	return 0;
}
