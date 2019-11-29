#include <iostream>
using namespace std;

int findMax(int *a, int n);
int findMin(int *a, int n);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, m, *a, *b; cin >> n >> m;
		a = new int[n];
		b = new int[m];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		for(int j = 0; j < m; j++)
			cin >> b[j];
		cout << (long long) findMax(a, n)*findMin(b, n) << endl;
	}
}
int findMax(int *a, int n) {
	int max = a[0];
	for(int i = 0; i < n; i++)
		if(max < a[i])
			max = a[i];
	return max;
}
int findMin(int *a, int n) {
	int min = a[0];
	for(int i = 0; i < n; i++)
		if(min > a[i])
			min = a[i];
	return min;
}
