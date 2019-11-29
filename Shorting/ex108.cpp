#include <iostream>
#include <cmath>
using namespace std;

int dem(int *a, int n, int k);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a, k; cin >> n >> k;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << dem(a, n, k) << endl;
	}
}
int dem(int *a, int n, int k) {
	int d = 0;
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++)
			if(abs(a[i] - a[j]) < k)
				d++;
	}
	return d;
}
