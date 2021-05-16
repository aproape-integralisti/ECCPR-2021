#include <bits/stdc++.h>

using namespace std;

struct Echipa{
  string nume{};
  int puncte{};
  int goluriDate{};
  int goluriPrimite{};
};

struct Meci{
    string gazde{}, oaspeti{};
    int golGazde{}, golOaspeti{};
    
   
};

 int getIndex(vector<Echipa> &echipe, string const &nume){
    for(int i = 0; i < echipe.size(); i++){
        if(echipe[i].nume == nume){
            return i;
        }
            
        if(echipe[i].nume == ""){
            echipe[i].nume = nume;
            return i;
        }
    }
        
    return -1;
}
    
int main(){
    int k, n;
    cin >> k >> n;
    vector<Meci> meciuri(n);
    
    for(int i = 0; i < n; i++){
        char line;
        
        cin >> meciuri[i].gazde >> meciuri[i].golGazde >> line >> meciuri[i].golOaspeti >> meciuri[i].oaspeti; 
    }
    
    vector<Echipa> echipe(k);
    
    for(auto &meci : meciuri){
        auto indexGazde = getIndex(echipe, meci.gazde);
        auto indexOaspeti = getIndex(echipe, meci.oaspeti);
        
        echipe[indexGazde].goluriDate += meci.golGazde;
        echipe[indexGazde].goluriPrimite += meci.golOaspeti;
        
        echipe[indexOaspeti].goluriDate += meci.golOaspeti;
        echipe[indexOaspeti].goluriPrimite += meci.golGazde;
        
        if(meci.golGazde > meci.golOaspeti){
            echipe[indexGazde].puncte += 3;
        }
        
        if(meci.golGazde == meci.golOaspeti){
            echipe[indexGazde].puncte += 1;
            echipe[indexOaspeti].puncte += 1;
        }
        
          if(meci.golGazde < meci.golOaspeti){
            echipe[indexOaspeti].puncte += 3;
        }
    }
    
    sort(echipe.begin(), echipe.end(), [](Echipa const &left, Echipa const &right){ return left.puncte > right.puncte; });
    
    for(int i = 0; i < k; i++){
        cout << echipe[i].nume << " " << echipe[i].puncte << " " << echipe[i].goluriDate << " " << echipe[i].goluriPrimite << endl;
    }
}