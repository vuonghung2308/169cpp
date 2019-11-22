#include <iostream>
#include <vector>
using namespace std;

void TopLeft(vector<vector<int> > a, int x1, int x2, int y1, int y2);
void BottomRight(vector<vector<int> > a, int x1, int x2, int y1, int y2);
void sapxep(vector<vector<int> > a);

int main() {
	int t; cin >> t;
	for(int o = 1; o <= t; o++) {
		int m, n; cin >> m >> n;
		vector<vector<int> > a(m, vector<int> (n, 0));
		for(int i = 0; i < a.size(); i++)
			for(int j = 0; j < a[i].size(); j++)
				cin >> a[i][j];
		sapxep(a); cout << endl;
	}
}
void TopLeft(vector<vector<int> > a, int x1, int x2, int y1, int y2) {
	for(int i = x1; i <= x2; i++)
		cout << a[y1][i] << ' ';
	for(int i = y1+1; i <= y2; i++) 
		cout << a[i][x2] << ' ';

}
void BottomRight(vector<vector<int> > a, int x1, int x2, int y1, int y2) {
	for(int i = x2; i >= x1; i--)
		cout << a[y2][i] << ' ';
	for(int i = y2-1; i >= y1; i--) 
		cout << a[i][x1] << ' ';
}
void sapxep(vector<vector<int> > a) {
	int x1 = 0, x2 = a[0].size()-1;
	int y1 = 0, y2 = a.size()-1;
	bool check = x2-x1 >= 0 && y2-y1 >=0;
	while(check) {
		if(check)
			TopLeft(a, x1, x2, y1, y2);
		y1++; x2--;
		check = x2-x1 >= 0 && y2-y1 >=0;
		if(check)
			BottomRight(a, x1, x2, y1, y2);
		x1++; y2--;
		check = x2-x1 >= 0 && y2-y1 >=0;
	}
	
}
