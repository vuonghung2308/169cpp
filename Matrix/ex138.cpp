#include <iostream>
using namespace std;

int dem(int **a, int n, int m);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, m; cin >> n >> m;
		int **a = new int*[n];
		for(int x = 0; x < n; x++) {
			a[x] = new int[m];
			for(int y = 0; y < m; y++) 
				cin >> a[x][y];
		}
		cout << dem(a, n, m) << endl;
	}
}
int dem(int **a, int n, int m) {
	int d = 0;
	for(int i = 0; i < m; i++) {
		bool check = true;
		for(int j = 0; j < n; j++) {
			if(a[j][i] == 0) {
				check = false;
				break;
			}
		}
		if(check == true)
			d++;
	}
	return d*n;
}
