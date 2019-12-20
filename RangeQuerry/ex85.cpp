#include <iostream>
using namespace std;

int SumMax(int *arr, int n) {
	int max_so_far = 0;
	int max_ending_here = 0;
	for(int i = 0; i < n; i++) {
		max_ending_here += arr[i];
		max_ending_here = (max_ending_here < 0)?0:max_ending_here;
		max_so_far = (max_so_far < max_ending_here)?max_ending_here:max_so_far;
	}
	return (max_so_far > 0)?max_so_far:-1;
}
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, *arr; cin >> n;
		arr = new int[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		cout << SumMax(arr, n) << endl;
	}
}
