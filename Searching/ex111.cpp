#include <iostream>
using namespace std;

int find(int *a, int n, int x);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a, x; cin >> n >> x;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << find(a, n, x)+1 << endl;
	}
}

int find(int *a, int n, int x) {
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			return i;
	return -2;
}
