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
	for(int i = 0; i <= a.size() - k; i++) {
		int max = a[i];
		for(int j = i; j < i + k; j++)
			if(max < a[j])
				max = a[j];
		cout << max << ' ';
	}
}
