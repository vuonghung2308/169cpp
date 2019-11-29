#include <iostream> 
using namespace std;

int findMax(int *a, int n);
int findMin(int *a, int n);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a; cin >> n;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << findMax(a, n) - findMin(a, n) + 1 - n << endl;
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
