#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void nhap(vector<vector<int> > &x);
void sapxep(vector<vector<int> > &x);
void hienthi(vector<vector<int> > x);
void Swap(int &a, int &b);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		vector<vector<int> > x;
		nhap(x);
		sapxep(x);
		hienthi(x); cout << endl;
	}
}

void nhap(vector<vector<int> > &x) {
	int n, X;
	cin >> n >> X;
	x.assign(2, vector<int> (n, 0));
	for(int i = 0; i < n; i++) {
		cin >> x[0][i];
		x[1][i]= abs(X - x[0][i]);
	}
}
void sapxep(vector<vector<int> > &x) {
	for(int i = 0; i < x[0].size()-1; i++) {
		for(int j = i + 1; j < x[0].size(); j++) {
			if(x[1][i] > x[1][j]) {
				Swap(x[0][i], x[0][j]);
				Swap(x[1][i], x[1][j]);
			}
		}
	}
}
void hienthi(vector<vector<int> > x) {
	for(int i = 0; i < x[0].size(); i++)
		cout << x[0][i] << ' ';
}
void Swap(int &a, int &b) {
	int i = a; a = b; b = i;
}
