#include <bits/stdc++.h>

using namespace std;
struct Squad{
  string nume;
  string rol;
};
struct Soldat{
	string nume;
	int varsta;
};

struct Soldat_spy{
  string nume;
  string rol;
  int cod;
};

bool comparator(Soldat_spy const &a, int const &b){
    return a.cod < b;
}
int main(){
	string instruction;
	cin >> instruction;

	if(instruction == "recruit"){
		string nume;
		vector <string> detasamente;
		while(cin >> nume){
			detasamente.push_back(nume);
		}

		int nr_detasamente = detasamente.size() / 5;

		for(int i = 0; i < nr_detasamente; i++){
			vector<string> d;

			for(int j = 0; j < 5; j++){
				d.push_back(detasamente[i * 5 + j]);
				cout << d[j] << " ";
			}
			cout << endl;
		}
	}

	if(instruction == "sort"){
		string nume;
		int varsta;
		vector <Soldat> v;
		while(cin >> nume >> varsta){
			Soldat s;
			s.nume = nume;
			s.varsta = varsta;
			v.push_back(s);
		}
		
		int n = v.size() / 5;
		
		for(int i = 0; i < n ; i++){
		   	vector<Soldat> d;

			for(int j = 0; j < 5; j++){
				d.push_back(v[i * 5 + j]);
			}
			
			sort(d.begin(), d.end(), [](Soldat const &a, Soldat const &b){
			    if(a.varsta == b.varsta){
			        return a.nume < b.nume;
			    } else {
			        return a.varsta > b.varsta;
			    }
			});
			
			for(int j = 0; j < d.size(); j++){
			    cout << d[j].nume << " ";
			}
			cout << endl;
		}
		
	}
	
	if(instruction == "spy_detect"){
	    int n;
	    cin >> n;
	    vector<Soldat_spy> v(n);
	    ///sortare dupa cod -> cautare binara
	    for(int i = 0;i < n;i++){
	        cin >> v[i].nume >> v[i].rol >> v[i].cod;
	    }
	    
	    sort(v.begin(), v.end(), [](Soldat_spy &a, Soldat_spy &b){
	        return a.cod < b.cod;
	    });
	    
	    int x;
	  
	    while(cin >> x){
			int i = n;
			int left = 0, right = n -1;
			
			while(left <= right){
				int middle = (left + right) / 2;
				
				if(v[middle].cod == x){
				    i = middle;
				}
				
				if(comparator(v[middle], x)){
				    left = middle + 1;
				} else {
				    right = middle - 1;
				}
			}
		
			if(i == n){
				cout << "Spy detected!" << endl;
			}else{
				cout << v[i].nume << " " << v[i].rol << endl;
			}
		}
	}
	
	if (instruction == "form_squad") {
	    int ok = false;
		vector<Squad> v;
		string aux;
	///	int x = 12;

		while (cin >> aux) {
			Squad tmp;
			tmp.nume = aux;
			cin >> aux;
			tmp.rol = aux;

			v.push_back(tmp);
		}
		
	///	int squads_count = v.size() / 5;

		while (v.size() >= 5) {
			int medic = 0, pilot = 0, marine = 0;
			vector<Squad> s;

			for (int i = 0; i < v.size(); i++) {

				if (v[i].rol == "medic" && medic == 0) {
					medic++;
					s.push_back(v[i]);
					v.erase(v.begin() + i);
					i--;
				} else if (v[i].rol == "pilot" && pilot == 0) {
					pilot++;
					s.push_back(v[i]);
					v.erase(v.begin() + i);
					i--;
				} else if (v[i].rol == "marine" && marine < 3) {
					marine++;
					s.push_back(v[i]);
					v.erase(v.begin() + i);
					i--;
				}

				if(medic && pilot && marine == 3){
					break;
				}
			}
			
			if (s.size() == 5) {
			    ok = true;
				for (int i = 0; i < s.size(); i++) {
					if (s[i].rol == "medic") {
						cout << s[i].nume << " ";
						s.erase(s.begin() + i);
						break;
					}
				}

				for (int i = 0; i < s.size(); i++) {
					if (s[i].rol == "pilot") {
						cout << s[i].nume << " ";
						s.erase(s.begin() + i);
						break;
					}
				}

				for (int i = 0; i < s.size(); i++) {
					cout << s[i].nume << " ";
				}

				cout << endl;
			}
		}
		
		if(!ok){
		    cout << "No squad formed yet\n";
		}
	}

	
	
	return 0;
}
