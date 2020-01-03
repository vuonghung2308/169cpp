#include <iostream>
using namespace std;

int binarySearch(int *a, int low, int high, int key, int direction) {
	if(high < low)
		return -1;
	int mid = (high + low) /2;
	if(a[mid] == key)
		return mid;
	if(direction == 1) {
		if(a[mid] < key)
			return binarySearch(a, mid+1, high, key, 1);
		return binarySearch(a, low, mid-1, key, 1);
	}
	else {
		if(a[mid] > key)
			return binarySearch(a, mid+1, high, key, -1);
		return binarySearch(a, low, mid-1, key, -1);
	}
}
int findPoint(int *a, int low, int high) {
	if(low > high)
		return -1;
	if(low == high)
		return low;
	int mid = (low+high)/2;
	if(a[mid] > a[mid+1])
		return mid;
	if(a[mid] < a[mid-1])
		return mid-1;
	if(a[mid] < a[mid+1])
		return findPoint(a, mid+1, high);
	return findPoint(a, low, mid-1);
}
int findKey(int *a, int n, int key) {
	int point = findPoint(a, 0, n-1);
	if(point == -1 && a[0] < a[1])
		return binarySearch(a, 0, n, key, 1);
	else if(point == -1) return binarySearch(a, 0, n-1, key, -1);
	if(a[point] == key)
		return point;
	int x = binarySearch(a, 0, point-1, key, 1);
	if(x == -1)
		return binarySearch(a, point+1, n-1, key, -1);
	return x;	
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int *a, n, key; cin >> n >> key;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << findKey(a, n, key) << endl;
	}
}
