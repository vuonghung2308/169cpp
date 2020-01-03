#include <iostream>
using namespace std;

void printArr(int **a, int n, int m) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
	cout << endl;
}
void changeArr(int **a, int n, int m) {
	int row[n] = {};
	int col[m] = {};
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i][j] == 1)
				row[i] = 1, col[j] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(row[i] || col[j])
				a[i][j] = 1;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int **a, n, m;
		cin >> n >> m;
		a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[m];
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		}
		changeArr(a, n, m);
		printArr(a, n, m);
	}
}
