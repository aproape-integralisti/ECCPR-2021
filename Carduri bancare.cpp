#include <bits/stdc++.h>

using namespace std;

struct Card {
    string numePersoana {};
    string tipCard {};
    string codCard {};
    string dataExpirare {};
    double sold {};
    
    friend istream &operator >> (istream &is, Card &card) {
        is >> card.numePersoana >> card.tipCard >> card.codCard >> card.dataExpirare >> card.sold;
        return is;
    }
};

int main() {
    string comanda;
    cin >> comanda;
    
    if(comanda == "stats") {
        map<string, int> map;
        
        Card card;
        while(cin >> card) {
            map[card.tipCard]++;
        }
        
        cout << map.size() << endl;
        
        for(auto &[tip, numar] : map) {
            cout << tip << "," << numar << endl;
        }
    }
    
    if(comanda == "debt") {
        vector<Card> carduriCuDatorii;
        double datoriiTotale = 0;
        
        Card card;
        while(cin >> card) {
            if(card.sold < 0) {
                datoriiTotale += card.sold;
                carduriCuDatorii.push_back(card);
            }
        }
        
        sort(carduriCuDatorii.begin(), carduriCuDatorii.end(), [](Card const &left, Card const &right) { return left.sold < right.sold; });
        
        cout << fixed << setprecision(2) << datoriiTotale << endl;
        
        for(auto &card : carduriCuDatorii) {
            cout << card.numePersoana << " ";
        }
        
        cout << endl;
    }
    
    if(comanda == "search") {
        string codDeGasit;
        cin >> codDeGasit;
        
        Card card;
        bool found;
        Card ans;
        while(cin >> card) {
            if(card.codCard == codDeGasit) {
                found = true;
                ans = card;
            }
        }
        
        if(found) {
            cout << ans.numePersoana << " " << ans.tipCard << " " << ans.codCard << " " << ans.dataExpirare << " " << fixed << setprecision(2) << ans.sold << endl;
        } else {
            cout << "CARD INVALID" << endl;
        }
    }
    
    if(comanda == "expiration") {
        string an;
        cin >> an;
        
        set<string> mySet;
        
        Card card;
        while(cin >> card) {
            if(card.dataExpirare.substr(card.dataExpirare.size() - 4) == an) {
                mySet.insert(card.dataExpirare);
            }
        }
        
        cout << mySet.size() << endl;
    }
}