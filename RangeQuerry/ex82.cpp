#include <iostream>
#include <vector>
using namespace std;

int tinhtong(vector<int> a, int x, int y);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, q; cin >> n >> q;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		for(int j = 1; j <= q; j++) {
			int l, r; cin >> l >> r;
			cout << tinhtong(a, l, r) << ' ';
		}
		cout << endl;
	}
}

int tinhtong(vector<int> a, int x, int y) {
	int t = 0;
	for(int i = x; i <= y; i++)
		t = t + a[i];
	return t;
}
