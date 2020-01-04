#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sapxep(vector<int> &x);
void hienthi(vector<int> x);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, k; cin >> k >> n;
		vector<int> x(k*n, 0);
		for(int j = 0; j < k*n; j++)
			cin >> x[j];
		sapxep(x);
		hienthi(x); cout << endl;
	}
}
vector<int> sapxep(vector<int> &x) {
	for(int i = 0; i < x.size()-1; i++) {
		for(int j = i + 1; j < x.size(); j++) {
			if(x[i] > x[j]) {
				int t = x[i];
				x[i] = x[j];
				x[j] = t;
			}
		}
	}
}
void hienthi(vector<int> x) {
	for(int i = 0; i < x.size(); i++)
		cout << x[i] << ' ';
}
