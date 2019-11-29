#include <iostream>
#include <vector>
using namespace std;

void check(vector<int> a, int x, int y);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		int l, r; cin >> l >> r;
		check(a, l, r);
		cout << endl;
	}
}

void check(vector<int> a, int x, int y) {
	int i = x;
	while(a[i] <= a[i+1] && i <= y)
		i++;
	while(a[i] >= a[i+1] && i <= y)
		i++;
	if(i == y)
		cout << "YES";
	else cout << "NO";
}
