#include <iostream>
#include <vector>
using namespace std;

void xoay(vector<vector<int> > &a, int x);
void xoaymang(vector<vector<int> > &a);

int main() {
	int t; cin >> t;
	for(int o = 1; o <= t; o++) {
		int m, n; cin >> m >> n;
		vector<vector<int> > a(m, vector<int> (n, 0));
		for(int i = 0; i < a.size(); i++)
			for(int j = 0; j < a[i].size(); j++)
				cin >> a[i][j];
		xoaymang(a); cout << endl;
	}
}

void xoay(vector<vector<int> > &a, int x) {
	int n = a.size(), m = a[0].size();
	int temp1 = a[x][m-1-x];
	int temp2 = a[n-1-x][m-1-x];
	
	for(int i = m-1-x; i >= x+1; i--)
		a[x][i] = a[x][i-1];
	
	for(int i = n-1-x; i >=  x+2; i--)
		a[i][m-1-x] = a[i-1][m-1-x];
		
	a[x+1][m-1-x] = temp1;
	temp1 = a[n-1-x][x];
	
	for(int i = x; i <= m-2-x; i++)
		a[n-1-x][i] = a[n-1-x][i+1];
		
	a[n-1-x][m-x-2] = temp2;
	
	for(int i = x; i <= n-2-x; i++)
		a[i][x] = a[i+1][x];

	a[n-x-2][x] = temp1;
}
void xoaymang(vector<vector<int> > &a) {
	int i = 0;
	while(i < a.size()/2 && i < a[0].size()/2) {
		xoay(a, i);
		i++;
	}
	for(int i = 0; i < a.size(); i++)
			for(int j = 0; j < a[i].size(); j++)
				cout << a[i][j] << ' ';
}
