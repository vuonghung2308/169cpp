#include <iostream>
using namespace std;

int binarySearch(int *a, int low, int high, int key) {
	if(high < low)
		return -1;
	int mid = (low+high)/2;
	if(a[mid] == key)
		return mid;
	if(a[mid] < key)
		return binarySearch(a, mid+1, high, key);
	return binarySearch(a, 0, mid-1, key);
}
int findPoint(int *a, int low, int high) {
	if(high < low)
		return -1;
	if(high == low)
		return low;
	int mid = (high+low)/2;
	if(a[mid] > a[mid+1])
		return mid;
	if(a[mid] < a[mid-1])
		return mid-1;
	if(a[low] < a[mid])
		return findPoint(a, mid+1, high);
	return findPoint(a, 0, mid-1);
}

int findKey(int *a, int n, int key) {
	int point = findPoint(a, 0, n-1);
	if(point == -1)
		return binarySearch(a, 0, n-1, key);
	if(a[point] == key)
		return point;
	if(a[0] > key)
		return binarySearch(a, point+1, n-1, key);
	return binarySearch(a, 0, point-1, key);
}
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k, *a; cin >> n >> k;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << findKey(a, n, k) << endl;
	}
}
