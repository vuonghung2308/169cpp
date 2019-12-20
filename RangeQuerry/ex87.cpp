#include <iostream>
using namespace std;

int findMax(int *a, int n) {
	int *res = new int[n];
	res[0] = a[0];
	int max = res[0];
	for(int i = 1; i < n; i++) {
		int m = a[i];
		for(int j = 0; j < i; j++) {
			if(a[i] == a[j]) {
				m = res[j];
				break;
			}
			else if(a[j] < a[i] && m < res[j] + a[i])
				m = res[j] + a[i];
		}
		res[i] = m;
		max = (max < res[i])?res[i]:max;
	}
	return max;
}

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int *a, n; cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << findMax(a, n) << endl;
	}
}
