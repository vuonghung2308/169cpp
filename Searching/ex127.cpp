#include <iostream>
using namespace std;

void sapxep(int *a, int n);
void hienthi(int *a, int n, int k);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a, k; cin >> n >> k;
		a = new int[n];
		for(int j = 0; j < n; j++) 
			cin >> a[j];
		hienthi(a, n, k);
	}
}
void sapxep(int *a, int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i] > a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
void hienthi(int *a, int n, int k) {
	sapxep(a, n);
	int i = 0, d = 1;
	while(d < k) {
		while(a[i] == a[i+1])
			i++;
		d++;
		i++;
	}
	while(a[i] == a[i+1]) {
		cout << a[i] << ' ';
		i++;
	}
	cout << a[i] << endl;
}
