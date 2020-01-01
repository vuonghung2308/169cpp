#include <iostream>
using namespace std;

int findSumM(int *a, int n) {
	int sum = 0, max_sum = INT_MIN;
	for(int i = 0; i < n; i++) {
		sum = sum + a[i];
		if(sum < 0)
			sum = 0;
		else
			max_sum = (sum > max_sum)? sum: max_sum;
	}
	return max_sum;
}
int findSquare(int **a, int n, int m) {
	int sum = 0, sum_max = INT_MIN;
	int left, right;
	for(left = 0; left < m; left++) {
		int temp[n] = {};
		for(right = left; right < m; right++) {
			for(int i = 0; i < n; i++)
				temp[i] = temp[i] + a[i][right];
			sum = findSumM(temp, n);
			sum_max = (sum > sum_max)? sum: sum_max; 
		}
	}
	return sum_max;
}
int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int **a, n, m;
		cin >> n >> m;
		a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[m];
			for(int j = 0; j < m; j++) 
				cin >> a[i][j];
		}
		cout << findSquare(a, n, m) << endl;
	}
}
