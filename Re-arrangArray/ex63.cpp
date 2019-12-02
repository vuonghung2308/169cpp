#include <iostream>
#include <vector>
using namespace std;

int timkiem(vector<int> o, int a, int x, int y);
void sapxep(vector<int> &x, vector<int> y);
void hienthi(vector<int> x);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, m; cin >> n >> m;
		vector<int> x(n, 0);
		vector<int> y(m, 0);
		for(int j = 0; j < n; j++)
			cin >> x[j];
		for(int j = 0; j < m; j++)
			cin >> y[j];
		sapxep(x, y);
		hienthi(x);
	}
	
	
}

int timkiem(vector<int> o, int a, int x, int y) {
	for(int i = x; i <= y; i++)
		if(o[i] == a)
			return i;
	return -1;
}
void sapxep(vector<int> &x, vector<int> y) {
	int d = 0;
	for(int i = 0; i < y.size(); i++) {
		while(timkiem(x, y[i], d, x.size()-1) != -1) {
			x.erase(x.begin()+ timkiem(x, y[i], d, x.size()-1));
			x.insert(x.begin() + d, y[i]);
			d++;
		}
	}
	for(int i = d; i < x.size()-1; i++)
		for(int j = i + 1; j < x.size(); j++)
			if(x[i] > x[j]) {
				int t = x[i];
				x[i] = x[j];
				x[j] = t;
			}
}
void hienthi(vector<int> x) {
	for(vector<int>::iterator it = x.begin(); it < x.end(); it++)
		cout << *it << ' ';
}
