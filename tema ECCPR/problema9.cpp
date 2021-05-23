#include <bits/stdc++.h>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	vector<vector<int>> matrix(M, vector<int>(N, 0));

	for (auto &row:matrix)
	{
		for (auto &col:row)
		{
			cin >> col;
		}
	}

	string cerinta;
	cin >> cerinta;

	if (cerinta == "a")
	{
		map<int, int> aparitii;

		for (auto &row:matrix)
		{
			for (auto &col:row)
			{
				aparitii[col]++;
			}
		}

		for (auto &i:aparitii)
		{
			cout << i.first << ": " << i.second << endl;
		}
	}
	if (cerinta == "b")
	{
		map<int, int> aparitii;

		for (auto &row:matrix)
		{
			for (auto &col:row)
			{
				aparitii[col]++;
			}
		}

		for (auto &i:aparitii)
		{
			if (i.second == 1)
			{
				cout << i.first << " ";
			}
		}
	}
	if (cerinta == "c")
	{
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (matrix[i][j] == 1)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		for (int i = M - 1; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (matrix[i][j] == 1)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		for (int j = 0; j < 1; j++)
		{
			for (int i = 0; i < M; i++)
			{
				if (matrix[i][j] == 1)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		for (int j = N - 1; j < N; j++)
		{
			for (int i = 0; i < M; i++)
			{
				if (matrix[i][j] == 1)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		cout << "NU";
	}
	if (cerinta == "d")
	{
		pair<int, int> intrare {};
		bool found = false;
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (matrix[i][j] == 1)
				{
					intrare.first = i;
					intrare.second = j;
					found = true;
				}
			}
		}
		for (int i = M - 1; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (matrix[i][j] == 1)
				{
					intrare.first = i;
					intrare.second = j;
					found = true;
				}
			}
		}
		for (int j = 0; j < 1; j++)
		{
			for (int i = 0; i < M; i++)
			{
				if (matrix[i][j] == 1)
				{
					intrare.first = i;
					intrare.second = j;
					found = true;
				}
			}
		}
		for (int j = N - 1; j < N; j++)
		{
			for (int i = 0; i < M; i++)
			{
				if (matrix[i][j] == 1)
				{
					intrare.first = i;
					intrare.second = j;
					found = true;
				}
			}
		}
		if (!found)
		{
			cout << "NU";
		}
		pair<int, int> curentPos = intrare;
		while (true)
		{
			int currentVal = matrix[curentPos.first][curentPos.second];
			int i = curentPos.first;
			int j = curentPos.second;

			if (i + 1 < M
				&& matrix[i + 1][j] == currentVal + 1)
			{
				curentPos.first = i + 1;
				curentPos.second = j;
			}
			else if (i - 1 >= 0
					 && matrix[i - 1][j] == currentVal + 1)
			{
				curentPos.first = i - 1;
				curentPos.second = j;
			}
			else if (j + 1 < N
					 && matrix[i][j + 1] == currentVal + 1)
			{
				curentPos.first = i;
				curentPos.second = j + 1;
			}
			else if (j - 1 >= 0
					 && matrix[i][j - 1] == currentVal + 1)
			{
				curentPos.first = i;
				curentPos.second = j - 1;
			}
			else
			{
				if (i == 0 || i == M - 1 || j == 0 || j == N - 1)
				{
					cout << i << " " << j;
					return 0;
				}
				else
				{
					cout << "NU";
					return 0;
				}
			}
		}
	}
	if (cerinta == "e")
	{
		vector<pair<int, int>> drum;
		pair<int, int> intrare {};
		bool found = false;
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (matrix[i][j] == 1)
				{
					intrare.first = i;
					intrare.second = j;
					found = true;
				}
			}
		}
		for (int i = M - 1; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (matrix[i][j] == 1)
				{
					intrare.first = i;
					intrare.second = j;
					found = true;
				}
			}
		}
		for (int j = 0; j < 1; j++)
		{
			for (int i = 0; i < M; i++)
			{
				if (matrix[i][j] == 1)
				{
					intrare.first = i;
					intrare.second = j;
					found = true;
				}
			}
		}
		for (int j = N - 1; j < N; j++)
		{
			for (int i = 0; i < M; i++)
			{
				if (matrix[i][j] == 1)
				{
					intrare.first = i;
					intrare.second = j;
					found = true;
				}
			}
		}
		if (!found)
		{
			cout << "NU";
		}
		pair<int, int> curentPos = intrare;
		while (true)
		{
			drum.push_back(curentPos);
			int currentVal = matrix[curentPos.first][curentPos.second];
			int i = curentPos.first;
			int j = curentPos.second;

			if (i + 1 < M
				&& matrix[i + 1][j] == currentVal + 1)
			{
				curentPos.first = i + 1;
				curentPos.second = j;
			}
			else if (i - 1 >= 0
					 && matrix[i - 1][j] == currentVal + 1)
			{
				curentPos.first = i - 1;
				curentPos.second = j;
			}
			else if (j + 1 < N
					 && matrix[i][j + 1] == currentVal + 1)
			{
				curentPos.first = i;
				curentPos.second = j + 1;
			}
			else if (j - 1 >= 0
					 && matrix[i][j - 1] == currentVal + 1)
			{
				curentPos.first = i;
				curentPos.second = j - 1;
			}
			else
			{
				if (i == 0 || i == M - 1 || j == 0 || j == N - 1)
				{
					break;
				}
				else
				{
					cout << "NU";
					return 0;
				}
			}
		}
		reverse(drum.begin(), drum.end());

		for (auto & i : drum)
		{
			cout << i.first << " " << i.second << endl;
		}
	}
	return 0;
}
