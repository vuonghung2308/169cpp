#include <iostream>
using namespace std;

int findB(int *a, int low, int high) {
	if(high < low)
		return a[0];
	if(high == low)
		return a[low];
	int mid = (low + high) / 2;
	if(mid < high && a[mid] > a[mid+1])
		return a[mid+1];
	if(mid > low && a[mid] < a[mid-1])
		return a[mid];
	if(a[high] > a[mid])
		return findB(a, low, mid-1);
	return findB(a, mid+1, high);
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, x, *a; cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << findB(a, 0, n-1) << endl;
	}
}
