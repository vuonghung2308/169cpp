#include <iostream>
using namespace std;

int Find(int *a, int n, int low, int high, int x) {
	if(a[high] <= x)
		return high;
	if(a[low] > x)
		return low;
	
	int mid = (high + low) / 2;
	if(a[mid] <= x && a[mid + 1] > x)
		return mid;
	if(a[mid] < x)
		return Find(a, n, mid + 1, high, x);
	else 
		return Find(a, n, low, mid - 1, x);
}

void lietke(int *a, int n, int x, int k) {
	int left = Find(a, n, 0, n-1, x);
	int right = left + 1;
	if(a[left] == x)
		left--;
	int count = 0;
	while(count < k && right < n && left >= 0) {
		if(a[right] - x < x - a[left])
			cout << a[right++] << ' ';
		else
			cout << a[left--] << ' ';
		count ++;
	}
	while(count < k && left >= 0)
		cout << a[left--] << ' ', count ++;
	while(count < k && right < n)
		cout << a[right++] << ' ', count ++;
}

int main() { 
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a, x, k; cin >> n;
		a = new int [n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cin >> k >> x;
		lietke(a, n, x, k); 
	}
   return 0; 
} 
