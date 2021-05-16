#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	map<string, int> animaleCount;
	map<string, vector<pair<string, int>>> animaleNume;
	for(int i = 0; i < n; i++) {
		string nume, specie;
		int varsta;
		cin >> nume >> specie >> varsta;

		animaleNume[specie].emplace_back(nume, varsta);
		animaleCount[specie]++;
	}

	string command;
	cin >> command;

	if(command == "count") {
		for (auto &animal : animaleNume) {
			sort(animal.second.begin(), animal.second.end(), [](auto const &left, auto const &right) {
				return left.second == right.second ? left.first < right.first : left.second < right.second;
			});
		}

		for (auto const &animal : animaleCount) {
			cout << animal.first << " (" << animal.second << "): ";
			for (auto const &e : animaleNume[animal.first]) {
				cout << e.first << " ";
			}
			cout << endl;
		}
	} else if (command == "endangered") {
		int varstaMinima;
		cin >> varstaMinima;

		for (auto &animal : animaleNume) {
			sort(animal.second.begin(), animal.second.end(), [](auto const &left, auto const &right) {
				return left.second == right.second ? left.first < right.first : left.second > right.second;
			});
		}

		vector<pair<string, int>> ordonare;
		for(auto const &animal : animaleCount) {
			if(animal.second == 1) {
				for(auto const &e : animaleNume[animal.first]) {
					if(e.second >= varstaMinima) {
						ordonare.emplace_back(e.first, e.second);
					}
				}
			}
		}

		sort(ordonare.begin(), ordonare.end(), [](auto const &left, auto const &right) {
			return left.second == right.second ? left.first < right.first : left.second > right.second;
		});

		for(auto const &e : ordonare) {
			cout << e.first << " ";
		}
		cout << endl;
	} else if(command == "search") {
		string animalCautat;
		cin >> animalCautat;

		if(animaleNume.find(animalCautat) != animaleNume.end()) {
			sort(animaleNume[animalCautat].begin(), animaleNume[animalCautat].end(), [](auto const &left, auto const &right) {
				return left.first < right.first;
			});

			for(auto const &animal : animaleNume[animalCautat]) {
				cout << animal.first << " - " << animal.second << endl;
			}
		} else {
			cout << "No match found" << endl;
		}
	} else if (command == "show") {
		vector<pair<string, string>> show;

		for(auto &animal : animaleNume) {
			sort(animal.second.begin(), animal.second.end(), [](auto const &left, auto const &right) {
				return left.second == right.second ? left.first < right.first : left.second < right.second;
			});

			show.emplace_back(animal.second[0].first, animal.first);
		}

		sort(show.begin(), show.end(), [](auto const &left, auto const &right) {
			return left.first < right.first;
		});

		for(auto const &e : show) {
			cout << e.first << " (" << e.second << ")" << endl;
		}
	}
	return 0;
}