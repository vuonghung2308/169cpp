#include <iostream>
using namespace std;

void hienthi(int *a, int n, int k);

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k, *a; cin >> n >> k;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		hienthi(a, n, k);
	}
}
void hienthi(int *a, int n, int k) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i] < a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(int i = 0; i < k; i++) 
		cout << a[i] << ' ';
	cout << endl;
}
