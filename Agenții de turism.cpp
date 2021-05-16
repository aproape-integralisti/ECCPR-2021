#include <bits/stdc++.h>

using namespace std;

struct Vacanta {
	bool rezervat {};
	int id {}, pret {};
	string oras {};

	Vacanta() = default;

	Vacanta(int id, int pret, string oras) : id(id), pret(pret), oras(std::move(oras)) {}
};

int main() {
	string input;

	vector<Vacanta> vacante;
	while(cin >> input) {
		if(input == "inregistrare") {
			int id, pret;
			cin >> id >> input >> pret;
			vacante.emplace_back(id, pret, input);
			continue;
		}

		if(input == "rezerva") {
			int id;
			cin >> id;
			bool found = false;
			for(auto &vacanta : vacante) {
				if(!vacanta.rezervat && vacanta.id == id) {
					vacanta.rezervat = true;
					cout << "Felicitari!" << endl;
				    found = true;
				    break;
				}
			}
			if(!found)
			cout << "Eroare!" << endl;
			continue;
		}

		if(input == "afiseaza") {
			cin >> input;
			bool found = false;
			for(auto const &vacanta : vacante) {
				if(!vacanta.rezervat && vacanta.oras == input) {
					cout << vacanta.id << " ";
					found = true;
				}
			}

			if(!found) {
				cout << "Nicio vacanta gasita!";
			}
			
			cout << endl;
		}
	}
	
	set<string> orase;
	for(auto const &vacanta : vacante){
	    if(!vacanta.rezervat)
	        orase.insert(vacanta.oras);
	}
	
	if(orase.empty()) {
	    cout << "Nicio vacanta disponibila!" << endl;
	} else {
    	for(auto const &oras : orase) {
	        cout << oras << " ";
	    }
	    cout << endl;
	}
	
	double average = 0;
	int count = 0;
	for(auto const &vacanta : vacante) {
	    if(!vacanta.rezervat && vacanta.oras == "Paris") {
	        average += vacanta.pret;
	        count++;
	    }
	}
	
	if(count == 0)
	cout << fixed << setprecision(3) << average << endl;
	else
	cout << fixed << setprecision(3) << average / count << endl;
	
	sort(vacante.begin(), vacante.end(), [](Vacanta const&left, Vacanta const&right) { return left.pret < right.pret; });
	
	bool found = false;
	for(auto &vacanta : vacante) {
	    if(!vacanta.rezervat) {
	        cout << vacanta.id << "," << vacanta.oras << "," << vacanta.pret << endl; 
	        vacanta.rezervat = true;
	        found = true;
	        break;
	    }
	}
	if(!found) {
	    cout << fixed << setprecision(3) << 0.0 << endl;
	}
	
	int sum = 0;
	
	for(auto const &vacanta : vacante) {
	    if(vacanta.rezervat && vacanta.oras == "Praga") {
	        sum += vacanta.pret;
	    }
	}
	
	cout << fixed << setprecision(3) << sum + (double)(30 * sum) / 100 << endl;
    return 0;
}