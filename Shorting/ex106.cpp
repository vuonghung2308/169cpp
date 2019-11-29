#include <iostream>
using namespace std;

void sapxep(int *a, int n);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, m, *a; cin >> n >> m;
		n = n + m;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		sapxep(a, n);
		for(int j = 0; j < n; j++)
			cout << a[j] << ' ';
		cout << endl;
	}
}
void sapxep(int *a, int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++)
			if(a[i] > a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	}
}

