#include <iostream>
using namespace std;

void topRight(int **a, int n, int m ,int &x1, int &x2, int &y1, int &y2, int *b, int &d) {
	for(int i = x1; i <= x2; i++)
		b[d++] = a[y1][i];
	for(int i = y1+1; i <= y2; i++)
		b[d++] = a[i][x2];
	y1++; x2--;
	
}
void bottomLeft(int **a, int n, int m ,int &x1, int &x2, int &y1, int &y2, int *b, int &d) {
	for(int i = x2; i >= x1; i--)
		b[d++] = a[y2][i];
	for(int i = y2-1; i >= y1; i--)
		b[d++] = a[i][x1];
	y2--; x1++;
}
int findP(int **a, int n, int m, int k) {
	int x1 = 0, x2 = m-1, y1 = 0, y2 = n-1;
	int b[n*m], d = 0;
	while (x1 <= x2 && y1 <= y2) {
		topRight(a, n, m, x1, x2, y1, y2, b, d);
		if(x1 <= x2 && y1 <= y2)
			bottomLeft(a, n, m, x1, x2, y1, y2, b, d);
	}
	return b[k-1];
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int **a, n, m, k;
		cin >> n >> m >> k;
		a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[m];
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		}
		cout << findP(a, n, m, k) << endl;
	}
}
