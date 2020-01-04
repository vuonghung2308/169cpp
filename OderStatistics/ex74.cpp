#include <iostream>
#include <vector>
using namespace std;

void lietke(vector<int> a, int k);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, k; cin >> n >> k;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		lietke(a, k); cout << endl;
	}
	
}
void lietke(vector<int> a, int k) {
	int res[a.size()];
	res[0] = a[0];
	for(int i = 1; i < a.size(); i++)
		res[i] = (res[i-1] < a[i])? a[i]: res[i-1];
	for(int i = k-1; i < a.size(); i++)
		cout << res[i] << ' ';
}
