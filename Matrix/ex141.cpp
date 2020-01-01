#include <iostream>
using namespace std;

int min(int a, int b, int c) {
	int t = (a < b)?a:b;
	return (c < t)?c:t; 
}
int findSquare(int **a, int n, int m) {
	int s[n][m] = {};
	int res = 1;
	for(int i = 0; i < m; i++)
		s[0][i] = a[0][i];
	for(int i = 1; i < n; i++)
		s[i][0] = a[i][0];
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(a[i][j] != 0)
				s[i][j] = min(s[i-1][j], s[i][j-1], s[i-1][j-1]) + 1;
			else s[i][j] = 0;
			res = (res > s[i][j])?res:s[i][j];
		}
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int **a, n, m; cin >> n >> m;
		a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[m];
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		}
		cout << findSquare(a, n, m) << endl;
	}
}
