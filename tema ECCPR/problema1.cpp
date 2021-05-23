#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nrAruncari;
    cin >> nrAruncari;
    
    vector<int> aruncari(7, 0);
    
    for (int i = 0; i < nrAruncari; i++)
    {
        int aux;
        cin >> aux;
        
        aruncari[aux]++;
    }
    
    int minim = INT_MAX, maxim = INT_MIN;
    
    for (int i = 1; i < 7; i++)
    {
        if (aruncari[i] > maxim)
        {
            maxim = aruncari[i];
        }
        if (aruncari[i] < minim)
        {
            minim = aruncari[i];
        }
    }
    
    if (double(maxim - minim) > double(10 * nrAruncari / 100))
    {
        cout << "1"; 
    }
    else
    {
        cout << "0";
    }
}