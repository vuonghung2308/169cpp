#include <iostream>
using namespace std;

int MinMove(int *a, int n) {
	int *move = new int[n];
	move[n-1] = 0;
	for(int i = n-2; i >= 0; i--) {
		if(a[i] >= n-i-1)
			move[i] = 1;
		else {
			int min = move[i+1];
			for(int j = i+1; j < n && j <= i+a[i]; j++)
				if(min > move[j])
					min = move[j];
			move[i] = min + 1;
		}
	}
	return move[0];
}

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int *a, n; cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << MinMove(a, n) << endl;
	}
}
