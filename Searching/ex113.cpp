#include <iostream>
using namespace std;

void find(int *a, int n);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a; cin >> n;
		a = new int[n-1];
		for(int j = 0; j < n-1; j++)
			cin >> a[j];
		find(a, n-1);
	}
}

void find(int *a, int n) {
	for(int i = 0; i < n-1; i++) {
		if(a[i+1]-a[i] > 1) {
			for(int j = 1; j < a[i+1]-a[i]; j++)
				cout << a[i] + j << ' ';
		}
	}
	cout << endl;
}
