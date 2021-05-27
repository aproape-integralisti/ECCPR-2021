#include <bits/stdc++.h>

using namespace std;

struct Concurent{
	int scor {};
	int timp {};
};

int main(){
	int n;
	cin >> n;

	vector<Concurent> concurenti(n);
    for(auto &concurent : concurenti){
        cin >> concurent.scor;
    }

	int max;
    stack<Concurent> que;
	for (auto &concurent : concurenti) {
		max = 0;
		while (!que.empty() && que.top().scor <= concurent.scor) {
			if (max < que.top().timp) {
				max = que.top().timp;
			}

			que.pop();
		}

		if (!que.empty()) {
			concurent.timp = max + 1;
		}

		que.push(concurent);
	}

	max = -1;
	for(auto &concurent : concurenti){
		if(max < concurent.timp){
			max = concurent.timp;
		}
	}

	cout << max;
}