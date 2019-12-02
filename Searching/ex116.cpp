#include <iostream>
#include <cmath>
using namespace std;

int tim(int *a, int n);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a; cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << tim(a, n) << endl;	
	}
}
int tim(int *a, int n) {
	int res = a[n-2] + a[n-1];
	for(int i = 0; i < n-2; i++)
		for(int j = i+1; j < n; j++)
			if(abs(a[i]+a[j]) < abs(res))
				res = a[i]+a[j];
	return res;
}
