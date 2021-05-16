#include <bits/stdc++.h>

using namespace std;

struct Info {
	int count {}, poz {};
};

int main() {
	int n;
	cin >> n;

	vector<string> cuvinte;
	for (auto i = 0; i < n; i++) {
		string cuvant;
		cin >> cuvant;
		cuvinte.push_back(cuvant);
	}

	char subpunct;
	cin >> subpunct;

	if (subpunct == 'a') {
		for_each(cuvinte.begin(), cuvinte.end(), [](auto &cuv) { sort(cuv.begin(), cuv.end()); });

		sort(cuvinte.begin(), cuvinte.end());

		for (auto const &cuvant : cuvinte) {
			cout << cuvant << endl;
		}
	} else if (subpunct == 'b') {
		int k;
		cin >> k;

		map<string, int> prefixe;
		for (auto const &cuvant : cuvinte) {
			prefixe[cuvant.substr(0, k)]++;
		}

		for (auto const &prefix : prefixe) {
			cout << prefix.first << " " << prefix.second << endl;
		}
	} else if (subpunct == 'c') {
		for_each(cuvinte.begin(), cuvinte.end(), [](auto &cuv) {
			for_each(cuv.begin(), cuv.end(), [](auto &c) { c = c + 13 > 'z' ? c + 13 - 26 : c + 13; });
		});

		for (auto const &cuvant : cuvinte) {
			cout << cuvant << endl;
		}
	} else if (subpunct == 'd') {
		string litere;
		for(auto const &cuvant : cuvinte) {
			for(auto const &c : cuvant) {
				if(litere.find(c) == string::npos) {
					litere += c;
				}
			}
		}

		reverse(litere.begin(), litere.end());

		for(auto const &c : litere) {
			cout << c << " ";
		}
		cout << endl;
	} else if (subpunct == 'e') {
		int size = cuvinte[0].size();

		string ans;
		for (int i = 0; i < size; i++) {
			map<char, Info> frq;

			for (int j = 0; j < cuvinte.size(); j++) {
				if (frq.find(cuvinte[j][i]) != frq.end()) {
					frq[cuvinte[j][i]].poz = j;
				}

				frq[cuvinte[j][i]].count++;
			}

			vector<pair<char, Info>> order(frq.begin(), frq.end());

			sort(order.begin(), order.end(), [](auto const &left, auto const &right) {
				return left.second.count == right.second.count ? left.second.poz < right.second.poz :
					   left.second.count > right.second.count;
			});

			ans += order[0].first;
		}

		cout << ans << endl;
	}

	return 0;
}
