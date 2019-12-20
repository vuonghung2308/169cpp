#include <iostream>
#include <vector>
using namespace std;

void hienthi(vector<vector<int> > a);

int main() {
	int t; cin >> t; 
	for(int i = 0; i < t; i++) {
		int n, m; cin >> n >> m;
		vector<vector<int> > a(n, vector<int> (m, 0));
		for(int x = 0; x < n; x++)
			for(int y = 0; y < m; y++)
				cin >> a[x][y];
		hienthi(a);
	}
}
void hienthi(vector<vector<int> > a) {
	int n = a.size(), m = a[0].size();
	int b;
	for(int i = 0; i <= n-1; i++) {
		if(i%2 == 0) {
			if(i <= m-1)
				for(int j = i; j >= 0; j--)
					cout << a[j][i-j] << ' ';
			else
				for(int j = 0; j < m; j++)
					cout << a[i-j][j] << ' ';
			b = 0;
		}
		else {
			if(i <= m-1)
				for(int j = 0; j <= i; j++)
					cout << a[j][i-j] << ' ';
			else
				for(int j = m-1; j >= 0; j--)
					cout << a[i-j][j] << ' ';
			b = 1;
		}
	}
	for(int i = 1; i <= m-1; i++) {
		if(i%2 == b) {
			for(int j = i; j < m; j++)
				cout << a[n-1+i-j][j] << ' ';
		}
		else {
			for(int j = m-1; j >= i; j--)
				cout << a[n-1+i-j][j] << ' ';
		}
	}
	cout << endl;
}
