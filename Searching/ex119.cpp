#include <iostream>
using namespace std;

void dem(int *a, int n, int k);

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k, *a; cin >> n >> k;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		dem(a, n, k);
	}
}
void dem(int *a, int n, int k) {
	int d = 0, i = 0;
	while(a[i] != k && i < n)
		i++;
	while(a[i] == k && i < n) {
		i++;
		d++;
	}
	if(d == 0)
		cout << -1 << endl;
	else cout << d << endl;
}
