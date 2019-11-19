#include <iostream>
#include <vector>
using namespace std;

int findmin(vector<int> a, int x, int y);
void Swap(int &x, int &y);
int count(vector<int> x);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> x(n, 0);
		for(int j = 0; j < n; j++)
			cin >> x[j];
		cout << count(x) << endl;
	}
	
}
int findmin(vector<int> a, int x, int y) {
	int xmin = x;
	for(int i = x + 1; i <= y; i++)
		if(a[xmin] > a[i])
			xmin = i;
	return xmin;
}
void Swap(int &x, int &y) {
	int t = x; x = y; y = t;
}
int count(vector<int> x) {
	int d = 0;
	for(int i = 0; i < x.size(); i++) {
		if(findmin(x, i, x.size()-1) != i) {
			Swap(x[i], x[findmin(x, i, x.size()-1)]);
			d++;
		}
	}
	return d;
}
