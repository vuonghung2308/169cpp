#include <iostream>
using namespace std;

int find(int *a, int n, int k);

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, *a, k; cin >> n >> k;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << find(a, n, k) << endl;
	}
}
int find(int *a, int n, int k) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) 
			if(a[i]-a[j] == k || a[i]-a[j] == -k)
				return 1;
	}
	return -1;
}
