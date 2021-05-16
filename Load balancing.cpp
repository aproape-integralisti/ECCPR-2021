#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> k >> n;

	int i = 0;
	vector<vector<int>> myVector(k);
	while(i < n) {
		for(int j = 0; j < k; j++) {
			if(i == n)
				break;
			i++;

			int aux;
			cin >> aux;
			myVector[j].push_back(aux);
		}
	}

	for(auto const &el : myVector) {
		for(auto const &e : el) {
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}