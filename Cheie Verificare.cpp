#include <bits/stdc++.h>

using namespace std;

int main() {
	int P;
	cin >> P;
	string input;
	getline(cin, input, '\n');
	getline(cin, input, '\n');

	int sum = 0;
	int aux;
	int carry = 0;
	int lenght = input.length();

	for(int i = lenght - 1; i >= 0; i--){
		aux = (input[i] - '0') * P + carry;

		if(aux >= 10){
			carry = aux / 10;
		} else {
			carry = 0;
		}
		
		sum += aux % 10;
	}
	sum += carry;

	while(sum / 10 != 0){
		aux = sum;
		sum = 0;
		while(aux){
			sum += aux % 10;
			aux /= 10;
		}
	}

	cout << sum;
	return 0;
}
