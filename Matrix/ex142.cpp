#include <iostream>
using namespace std;

void replace_O(char **a, int x, int y, int n, int m, char preC, char newC) {
	if(x < n && x >=0 && y < m && y >=0 && a[x][y] == preC) {
		a[x][y] = newC;
		replace_O(a, x+1, y, n, m, '-', 'O');
		replace_O(a, x-1, y, n, m, '-', 'O');
		replace_O(a, x, y-1, n, m, '-', 'O');
		replace_O(a, x, y+1, x, m, '-', 'O');
	}
}

void display(char **a, int n, int m) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i][j] == 'O')
				a[i][j] = '-';
	
	for(int i = 0; i < n; i++){
		if(a[i][0] == '-')
			replace_O(a, i, 0, n, m, '-', 'O');
		if(a[i][m-1] == '-')
			replace_O(a, i, m-1, n, m, '-', 'O');
	}
	for(int i = 0; i < m; i++){
		if(a[0][i] == '-')
			replace_O(a, 0, i, n, m, '-', 'O');
		if(a[n-1][i] == '-')
			replace_O(a, n-1, i, n, m, '-', 'O');
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '-')
				a[i][j] = 'X';
			cout << a[i][j] << ' ';
		}
	}
	cout << endl;
	
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		char **a;
		int n, m; cin >> n >> m;
		a = new char*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new char[m];
			for(int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		display(a, n, m);
	}
}
