#include <bits/stdc++.h>

using namespace std;

int check(string &aux, const char &alfa, const char &beta, int M, int N)
{
	aux.front() = toupper(aux.front());
	aux.back() = toupper(aux.back());

	if (aux.front() == alfa && aux.back() == beta)
	{
		if (aux.size() < M)
		{
			return 1;
		}
		if (aux.size() >= M && aux.size() < N)
		{
			return 2;
		}
		if (aux.size() >= N)
		{
			return 3;
		}
	}

	return 0;
}

int main()
{
	char alfa, beta;
	int M, N;

	cin >> alfa >> beta >> M >> N;
	string aux;

	alfa = toupper(alfa);
	beta = toupper(beta);

	vector<int> rasp(4,0);

	while (cin >> aux)
	{
		rasp[check(aux,alfa,beta,M,N)]++;
	}

	cout << rasp[1] << " " << rasp[2] << " " << rasp[3] << endl;
	
	return 0;
}
