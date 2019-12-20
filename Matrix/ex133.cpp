#include <iostream>
#include <vector>
using namespace std;

void hienthi(vector<vector<int> > a);

int main() {
	int t; cin >> t;
	for(int i = 1;i <= t; i++) {
		int n; cin >> n;
		vector<vector<int> > a(n, vector<int> (n, 0));
		for(int x = 0; x < n; x++) 
			for(int y = 0; y < n; y++)
				cin >> a[x][y];
		hienthi(a); cout << endl;
	}
}
void hienthi(vector<vector<int> > a) {
	for(int i = 0; i < a.size(); i++) {
		if(i == 0 || i ==  a.size()-1)
			for(int j = 0; j < a[i].size(); j++)
				cout << a[i][j] << ' ';
		else cout << a[i][0] << ' ' << a[i][a[i].size()-1] << ' ';
	}
}
