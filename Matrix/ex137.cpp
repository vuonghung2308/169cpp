#include <iostream>
#include <vector>
using namespace std;

void hienthi(vector<vector<int> > a);

int main() {
	int t; cin >> t;
	for(int i = 1;i <= t; i++) {
		int n, m; cin >> n >> m;
		vector<vector<int> > a(n, vector<int> (m, 0));
		for(int x = 0; x < n; x++) 
			for(int y = 0; y < m; y++)
				cin >> a[x][y];
		hienthi(a); cout << endl;
	}
}
void hienthi(vector<vector<int> > a) {
	vector<vector<int> > res = a;
	for(int i = 0; i < a.size(); i++) {
			for(int j = 0; j < a[i].size(); j++)
				if(a[i][j] == 1) {
					for(int x = 0; x < a.size(); x++)
						res[x][j] = 1;
					for(int x = 0; x <a[i].size(); x++)
						res[i][x] = 1;	
				}
	}
	for(int i = 0; i < a.size(); i++) {
			for(int j = 0; j < a[i].size(); j++)
				cout << res[i][j] << ' ';
	}
}
