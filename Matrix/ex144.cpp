#include <iostream>
using namespace std;

void numberWay(int **a, int n, int m, int x, int y, int s, int k, int &count) {
	s = s + a[x][y];
	if(x == n-1 && y == m-1 && s == k)
		count++;
	if(x < n - 1 && s < k)
		numberWay(a, n, m, x+1, y, s, k, count);
	if(y < m - 1 && s < k)
		numberWay(a, n, m, x, y+1, s, k, count);
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int **a, n, k, count = 0, s = 0;
		int d = 0;
		cin >> n >> k;
		a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[n];
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		numberWay(a, n, n, 0, 0, s, k, count);
		cout << count << endl;
	}
}
