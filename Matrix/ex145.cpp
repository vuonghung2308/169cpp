#include <iostream>
using namespace std;

void topRight(int **a, int n, int m ,int &x1, int &x2, int &y1, int &y2, int *b, int &d) {
	for(int i = x1; i <= x2; i++)
		b[d--] = a[y1][i];
	for(int i = y1+1; i <= y2; i++)
		b[d--] = a[i][x2];
	y1++; x2--;
	
}
void bottomLeft(int **a, int n, int m ,int &x1, int &x2, int &y1, int &y2, int *b, int &d) {
	for(int i = x2; i >= x1; i--)
		b[d--] = a[y2][i];
	for(int i = y2-1; i >= y1; i--)
		b[d--] = a[i][x1];
	y2--; x1++;
}
void hienthi(int **a, int n, int m) {
	int x1 = 0, x2 = m-1, y1 = 0, y2 = n-1;
	int b[n*m], d = n*m - 1;
	while (x1 <= x2 && y1 <= y2) {
		topRight(a, n, m, x1, x2, y1, y2, b, d);
		if(x1 <= x2 && y1 <= y2)
			bottomLeft(a, n, m, x1, x2, y1, y2, b, d);
	}
	for(int i = 0; i < n*m; i++)
		cout << b[i] << ' ';
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
		hienthi(a, n, m); cout << endl;
	}
}
