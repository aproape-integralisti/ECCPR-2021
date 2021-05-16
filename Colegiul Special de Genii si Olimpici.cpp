#include <bits/stdc++.h>

using namespace std;

bool search (vector<string> const &V, string const &olimpiada) {
    for(auto const &e : V)
        if(e == olimpiada)
            return true;
    
    return false;
}

int main() {
	string comanda;
	cin >> comanda;
	
	if(comanda == "register") {
		vector<array<string, 3>> catalog;
		
		string s1;
		while(cin >> s1) {
		    string s2, s3;
		    cin >> s2 >> s3;
			array<string, 3> pagina;
			pagina[0] = s1;
			pagina[1] = s2;
			pagina[2] = s3;
			catalog.push_back(pagina);
		}
		
	    for(int j = catalog.size() - 1; j >= 0; j--) {
			for(int i = 0; i < 3; i++) {
				if(!catalog[j][i].empty()) {
					cout << catalog[j][i] << " ";
				}
			}
			
			cout << endl;
		}
	}
	
  	if(comanda == "filter") {
		unordered_map<string, double> elevi;

		string nume;
		double medie;
		double medieMaxima = -1;
		while(cin >> nume >> medie) {
			if(medieMaxima < medie) {
				medieMaxima = medie;
			}

			elevi.insert({nume, medie});
		}

		vector<pair<string, double>> olimpici;
		for(auto &elev : elevi) {
			if(elev.second >= medieMaxima / 2) {
				olimpici.emplace_back(elev.first, elev.second);
			}
		}

		sort(olimpici.begin(), olimpici.end(), [](auto &left, auto &right) {
			return left.second == right.second ? left.first < right.first : left.second < right.second;
		});

		for(auto &elev : olimpici) {
			cout << elev.first << endl;
		}
	}
	
	if(comanda == "find_best") {
		unordered_map<string, vector<string>> numeVsOlimpiada;
		unordered_map<string, int> olimpiadaVsCount;
		unordered_map<string, int> numeVsCount;

		string nume, olimpiada;
		while(cin >> nume >> olimpiada) {
			numeVsOlimpiada[nume].push_back(olimpiada);
			olimpiadaVsCount[olimpiada]++;
			numeVsCount[nume]++;
		}

		int maxCount = -1;
		string maxOlimpiada;
		for(auto &olimpiada : olimpiadaVsCount) {
			if(maxCount < olimpiada.second) {
				maxCount = olimpiada.second;
				maxOlimpiada = olimpiada.first;
			}
		}

		cout << maxOlimpiada << endl;

		string maxNume;
		maxCount = -1;
		for(auto &nume : numeVsCount) {
			if(maxCount < nume.second) {
				maxCount = nume.second;
				maxNume = nume.first;
			}
		}

		cout << maxNume << endl;

		if(search(numeVsOlimpiada[maxNume], maxOlimpiada)) {
			cout << "Bingo!" << endl;
		} else {
			cout << "Not Bingo!" << endl;
		}
	}
	
    if(comanda == "get_report") {
		int eleviPromovati = 0;
		int totalElevi = 0;
		string nume;
		while(cin >> nume) {
			int media = 0;
			bool picat = false;
			for(int i = 0; i < 3; i++) {
				int nota;
				cin >> nota;
				if(nota < 5)
					picat = true;
				media += nota;
			}

			totalElevi++;
			if(media >= 18 && !picat)
				eleviPromovati++;
		}

		cout << fixed << setprecision(2) << (double) eleviPromovati * 100 / totalElevi << endl; 
	}
	return 0;
}