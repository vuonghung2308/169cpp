#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> a, int low, int high) {
	if(low > high)
		return -1;
	if(low == high)
		return low;
	int mid = (low+high)/2;
	if(a[mid] > a[mid+1] && a[mid] > a[mid-1])
		return mid;
	if(a[mid] < a[mid-1])
		return (mid-1);
	if(a[mid] < a[mid+1])
		return findMax(a, mid+1, high);
	return findMax(a, 0, mid-1);
	
}
int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << a[findMax(a, 0, n-1)] << endl;
	}
	
}
