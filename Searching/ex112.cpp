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
		cout << find(a, n, x) << endl;
	}
}

int find(int *a, int n, int x) {
	if(x < a[0] || x > a[n-1])
		return -1;
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			return 1;
	return -1;
}
