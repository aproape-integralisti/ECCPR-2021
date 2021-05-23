#include <bits/stdc++.h>

using namespace std;

bool biggerThanFive(vector<int> const &val, int value)
{
    int count = 0;
    
    for (auto i: val)
    {
        if(value >= i)
        {
            count++;
        }
        if (count == 6)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
	int nrVal1, nrVal2;
	cin >> nrVal1;

	vector<int> val(nrVal1, 0);
	for (auto &i:val)
	{
		cin >> i;
	}

	cin >> nrVal2;
	val.resize(nrVal1 + nrVal2);

	for (int i = nrVal1; i < nrVal1 + nrVal2; i++)
	{
		cin >> val[i];
	}

	sort(val.begin(), val.end());

	double sumMedie = 0.0;
	int nr = 0;

	for (int i = 0; i < nrVal1 + nrVal2; i++)
	{
	    if (biggerThanFive(val, val[i]))
	    {
	        sumMedie += val[i];
	        nr++;
	    }
	}

	cout << fixed << setprecision(2) << sumMedie / nr;

	return 0;
}
