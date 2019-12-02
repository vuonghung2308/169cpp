#include <iostream>
#include <vector>
using namespace std;

vector<int> giao(vector<int> x, vector<int> y);
vector<int> hop(vector<int> x, vector<int> y);
void hienthi(vector<int> x);
bool find(vector<int> a, int x);
void Insert(vector<int> &a, int x);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		vector<int> x, y;
		int n, m; cin >> n >> m;
		x.assign(n, 0); y.assign(m, 0);
		for(int i = 0; i < n; i++)
			cin >> x[i];
		for(int i = 0; i < m; i++)
			cin >> y[i];
		hienthi(hop(x, y)); cout <<endl;
		hienthi(giao(x, y)); cout << endl;
	}
}

vector<int> giao(vector<int> x, vector<int> y) {
	vector<int> res;
	for(int i = 0; i < y.size(); i++)
		if(find(x, y[i]))
			res.push_back(y[i]);
	return res;
}
vector<int> hop(vector<int> x, vector<int> y) {
	vector<int> res = x;
	for(int i = 0; i < y.size(); i++)
			Insert(res, y[i]);
	return res;
}
bool find(vector<int> a, int x) {
	for(int i = 0; i < a.size(); i++)
		if(x == a[i])
			return true;
	return false;
}
void Insert(vector<int> &a, int x) {
	if(x > a.back()) {
		a.push_back(x);
	}
	else {
		for(int i = 0; i < a.size()-1; i++) {
			if(a[i] < x && a[i+1] > x) {
				a.insert(a.begin()+i+1, x);
				break;
			}
		}
	}
}
void hienthi(vector<int> x) {
	for(int i = 0; i < x.size(); i++)
		cout << x[i] << ' ';
}
