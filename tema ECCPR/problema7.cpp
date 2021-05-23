#include <bits/stdc++.h>

using namespace std;

struct book
{
	int cod {};
	int an {};
};

bool comp_an(book left, book right)
{
	return left.an > right.an;
}

bool comp_cod(book left, book right)
{
	return left.cod < right.cod;
}

int main()
{
	vector<book> biblioteca;
	set<int> coduri;
	map<int, int> dex;
	int cod, an;

	while (cin >> cod >> an)
	{
		book aux;

		aux.cod = cod;
		aux.an = an;

		dex[an]++;

		coduri.insert(cod);
		biblioteca.push_back(aux);
	}

	sort(biblioteca.begin(), biblioteca.end(), comp_an);

	for (auto i:biblioteca)
	{
		cout << i.an << " ";
	}
	cout << endl;

	for (auto i:coduri)
	{
		cout << i << " ";
	}
	cout << endl;

	for (auto carte: dex)
	{
		cout << carte.first << ": " << carte.second << endl;
	}

	cout << dex.begin()->second << endl;

	for (auto i:biblioteca)
	{
		if (i.an == dex.begin()->first)
		{
			cout << i.cod << " ";
		}
	}

	return 0;
}
