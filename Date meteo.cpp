#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> temp(N);

	for (int i = 0; i < N; i++)
	{
		cin >> temp[i];
	}

	int cnt = 1;
	int cnt_max = 0;
	int start_poz;

	int nr_poz = 0, nr_neg = 0;

	if (temp[0] < 0)
	{
		nr_neg++;
	}
	else
	{
		nr_poz++;
	}

	for (int i = 1; i < N; i++)
	{
		if (temp[i] < 0)
		{
			nr_neg++;
		}
		else
		{
			nr_poz++;
		}
		if ((temp[i] >= 0 && temp[i - 1] < 0) || (temp[i] < 0 && temp[i - 1] >= 0))
		{
			cnt++;
			if (cnt >= cnt_max)
			{
				cnt_max = cnt;
				start_poz = i - cnt + 1;
			}
		}
		else
		{
			cnt = 1;
		}
	}

	cout << cnt_max << endl;

	if (cnt_max != 0)
	{
		for (int i = start_poz; i < start_poz + cnt_max; i++)
		{
			cout << temp[i] << " ";
		}
		cout << endl;

		cout << "+:" << fixed << setprecision(2) << 100.0 * nr_poz / N << "% ";
		cout << "-:" << fixed << setprecision(2) << 100.0 * nr_neg / N << "% " << endl;
	}
}