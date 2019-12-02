#include <iostream>
using namespace std;

int find(int *a, int n);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int *a, n; cin >> n;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << find(a, n) << endl;
	}
}

int find(int *a, int n) {
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++) 
			if(a[i] == a[j])
				return a[i];
}
