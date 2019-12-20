#include <iostream>
#include <vector>
using namespace std;

void topRight(vector<vector<int> > a, vector<int> &o, int x1, int x2, int y1, int y2);
void bottonLeft(vector<vector<int> > a, vector<int> &o, int x1, int x2, int y1, int y2);
void hienthi(vector<int> a);
void sapxep(vector<vector<int> > a);

int main() {
	int t; cin >> t;
	for(int x = 1; x <= t; x++) {
		int n, m; cin >> n >> m;
		vector<vector<int> > a(n, vector<int> (m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		sapxep(a);		
	}
}

void topRight(vector<vector<int> > a, vector<int> &o, int x1, int x2, int y1, int y2) {
	for(int i = x1; i <= x2; i++)
		o.insert(o.begin(), a[y1][i]);
	for(int i = y1+1; i <= y2; i++)
		o.insert(o.begin(), a[i][x2]);
}
void bottonLeft(vector<vector<int> > a, vector<int> &o, int x1, int x2, int y1, int y2) {
	for(int i = x2; i >= x1; i--)
		o.insert(o.begin(), a[y2][i]);
	for(int i = y2-1; i >= y1; i--)
		o.insert(o.begin(), a[i][x1]);
}
void hienthi(vector<int> a) {
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << endl;
}
void sapxep(vector<vector<int> > a) {
	int x1 = 0, y1 = 0;
	int x2 = a[0].size()-1;
	int y2 = a.size()-1;
	vector<int> res;
	while(x2-x1 >= 0 && y2-y1 >= 0) {
		topRight(a, res, x1, x2, y1, y2);
		y1++; x2--;
		if(x2-x1 >= 0 && y2-y1 >= 0) {
			bottonLeft(a, res, x1, x2, y1, y2);
			x1++; y2--; 
		}
	}
	hienthi(res);
}
