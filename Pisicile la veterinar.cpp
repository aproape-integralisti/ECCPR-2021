#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int cats, boxes;

	cin >> cats >> boxes;

	vector<long long int> c_v(cats);
	vector<long long int> b_v(boxes);

	for (int i = 0; i < cats; i++)
	{
		cin >> c_v[i];
	}

	for (int i = 0; i < boxes; i++)
	{
		cin >> b_v[i];
	}

	sort(c_v.begin(), c_v.end());
	sort(b_v.begin(), b_v.end());

	int good = 0;

	for (int i = 0, j = 0; i < boxes && j < cats;)
	{
		if (b_v[i] > c_v[j])
		{
			i++;
			j++;
			good++;
		}
		else if (b_v[i] <= c_v[j])
		{
			i++;
		}
	}

	cout << good;

	return 0;
}
