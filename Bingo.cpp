#include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_set<int> mySet;
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n * n; i++) {
        int aux;
        cin >> aux;
        mySet.insert(aux);
    }
    
    for(int i = 0; i < k; i++) {
        int aux;
        cin >> aux;
        
        if(mySet.find(aux) != mySet.end()) {
            mySet.erase(aux);
        }
    }
    
    if(mySet.empty())
        cout << "BINGO!";
    else
        cout << mySet.size();
    return 0;
}