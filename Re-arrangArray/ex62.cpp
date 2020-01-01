#include <iostream>
using namespace std;

int findSub(int *a, int n) {
	int max_end_here = 1,
		min_end_here = 1,
		max_so_far = 1,
		flag = 0;
	
	for(int i = 0; i < n; i++) {
		if(a[i] > 0) {
			max_end_here *= a[i];
			min_end_here = (1 < a[i]*min_end_here)? 1: a[i]*min_end_here;
			flag = 1;
		}
		else if(a[i] == 0)
			max_end_here = 1, min_end_here = 1;
		else {
			int temp = max_end_here;
			max_end_here = (min_end_here < 0)? min_end_here*a[i]: 1;
			min_end_here = temp * a[i];
		}
		max_so_far = (max_end_here > max_so_far)? max_end_here: max_so_far;			
	}
	if(max_so_far == 1 && flag == 0)
		return 0;
	return max_so_far;
}
int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a; cin >> n;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << findSub(a, n) << endl;
	}
}
