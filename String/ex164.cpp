#include <iostream>
using namespace std;

int possibleStrings(int n, int r, int g, int b) {
	int fact[n+1];
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
		fact[i] = fact[i-1]*i;
	int sum = 0,
		left = n - (r+g+b);
	for(int i = 0; i <= left; i++) {
		for(int j = 0; j <= left-i; j++) {
			int k = left - i - j;
			sum = sum + fact[n] /
						(fact[i+r]*fact[j+g]*fact[k+b]);
		}
	}
	return sum;
}

int main() {
	int t; cin >> t; 
	for(int i = 0; i < t; i++) {
		int n, r, g, b;
		cin >> n >> r >> g >> b;
		cout << possibleStrings(n, r, g, b) << endl;
	}
}
