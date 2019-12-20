#include <iostream>
using namespace std;

int SumMax(int *a, int n);
int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a; cin >> n;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << SumMax(a, n) << endl;
	}
}
int SumMax(int *a, int n) {
	int incl = a[0];
	int excl = 0;
	for(int i = 1; i < n; i++) {
		int new_excl = (incl > excl)?incl:excl;
		incl = excl + a[i];
		excl = new_excl;
	}
	return (incl > excl)?incl:excl;
}
