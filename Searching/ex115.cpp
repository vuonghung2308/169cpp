#include <iostream>
using namespace std;

void soNhoThuHai(int *a, int n);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a; cin >> n;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		soNhoThuHai(a, n);
	}
}
void soNhoThuHai(int *a, int n) {
	int m1 = a[0], m2;
	for(int i = 1; i < n; i++)
		if(a[i] < m1)
			m1 = a[i];
	int t = 0;
	while(a[t] == m1 && t < n)
		t++;
	if(t != n) {
		m2 = a[t];
		for(int i = 0; i < n; i++)
			if(a[i] < m2 && a[i] != m1)
				m2 = a[i];
		cout << m1 << ' ' << m2 << endl;
	}
	else cout << -1 << endl;
}
