#include <iostream>
using namespace std;

int findLenth(int *a, int n, int x) {
	int min = -1;
	for(int i = 0; i < n; i++) {
		int t = 0, j = i;
		while(t <= x && j < n)
			t += a[j++];
		if(min == -1 && t > x)
			min = j - i;
		if(t > x && min > j-i)
			min = j - i;
	}
	return min;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, x, *a; cin >> n >> x;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << findLenth(a, n, x) << endl;
	}
}
