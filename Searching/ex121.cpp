#include <iostream>
using namespace std;

int binarySearchU(int *a, int x, int r, int l) {
	while(l <= r) {
		int mid = (r+l) / 2;
		if(a[mid] == x)
			return mid;
		else if(a[mid] > x)
			r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}
int binarySearchD(int *a, int x, int r, int l) {
	while(l <= r) {
		int mid = (r+l) / 2;
		if(a[mid] == x)
			return mid;
		else if(a[mid] > x)
			l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int findB(int *a, int n, int x) {
	int i = 0;
	while(a[i] < a[i+1] && i < n)
		i++;
	if(a[i] < x)
		return -1;
	int res = binarySearchU(a, x, i, 0);
	if(res != -1)
		return res;
	res = binarySearchD(a, x, n-1, i);
	if(res != -1)
		return res;
	return -1;	
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, x, *a; cin >> n >> x;
		a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << findB(a, n, x) << endl;
	}
}
