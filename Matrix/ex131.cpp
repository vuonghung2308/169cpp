#include <iostream>
using namespace std;

const int COL[] = {-1, 0, 1, 1, 1, 0, -1, -1, -1};
const int ROW[] = {-1, -1, -1, 0, 1, 1, 1, 0, -1};

bool isSafe(int **a, bool **visited, int n, int m, int row, int col) {
	return (row >= 0 && col >= 0 && row < n && col < m && (a[row][col] && !visited[row][col]));
}
void DFS(int **a, bool **visited, int n, int m, int row, int col) {
	visited[row][col] = 1;
	for(int i = 0; i < 8; i++) {
		if(isSafe(a, visited, n, m, row + ROW[i], col + COL[i]))
			DFS(a, visited, n, m, row + ROW[i], col + COL[i]);
	}
}
int count(int **a, int n, int m) {
	int d = 0;
	bool **visited = {0};
	visited = new bool* [n];
	for(int i = 0; i < n; i++) {
		visited[i] = new bool[m];
		for(int j = 0; j < m; j++)
			visited[i][j] = 0;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] && !visited[i][j]) {
				DFS(a, visited, n, m, i, j);
				d++;
			}
		}
	}
	return d;
}

int main() {
	int t; cin >> t;
	for(int x = 1; x <= t; x++) {
		int n, m, **a;
		cin >> n >> m;
		a = new int* [n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[m];
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		}
		cout << count(a, n, m) << endl;
	}
}
