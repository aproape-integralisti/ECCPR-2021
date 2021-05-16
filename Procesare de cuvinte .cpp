#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<string> input;
    unordered_map<string, int> wordCount;
    unordered_set<char> litere;
    
    int litereCount = 0;
    int maxLength = 0;
    string maxLengthWord;
	string cuvant;
	while (cin >> cuvant) {
	    if(maxLength < cuvant.size()) {
	        maxLength = cuvant.size();
	        maxLengthWord = cuvant;
	    }
	    
	    for(auto const &c : cuvant) {
	        litereCount++;
	        litere.insert(c);
	    }
	    
	    wordCount[cuvant]++;
		input.push_back(cuvant);
	}

	sort(input.begin(), input.end(), [](auto const &left, auto const &right) { return left < right; });
	
	if(input.size() & 1) {
	    cout << input[input.size() / 2] << endl;
	} else {
		cout << input[input.size() / 2 - 1] << " " << input[input.size() / 2] << endl; 
	}
	
	int maxCount = -1;
	string maxWord;
	for(auto const &word : wordCount) {
	    if(maxCount < word.second) {
	        maxCount = word.second;
	        maxWord = word.first;
	    }
	}
	
	cout << maxWord << endl;
	reverse(maxLengthWord.begin(), maxLengthWord.end());
	cout << maxLengthWord << endl;
	cout << fixed << setprecision(2) << (double) litereCount / litere.size() << endl;
	return 0;
}
