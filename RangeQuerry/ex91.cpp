#include <iostream>
#include <vector>
using namespace std;

int dem(vector<int> a);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> a(n, 0);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << dem(a) << endl;
	}
}

int dem(vector<int> a) {
	int n = a.size(), dem = 0;
	for(int i = 0; i <= n/2; i++) {
		while(a[i] != a[n-1-i]) {
			if(a[i] < a[n-1-i]) {
				a[i] = a[i] + a[i+1];
				a.erase(a.begin()+i+1);
				dem = dem + 1;
				n = n - 1;
			}
			else {
				a[n-i-2] = a[n-i-2] + a[n-i-1];
				a.erase(a.begin()+n-i-1);
				dem = dem + 1;
				n = n - 1;
			}
		}
	}
	return dem;
}
