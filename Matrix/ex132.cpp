#include <iostream>
using namespace std;

int counter(int **a, int n) {
	int sumRow[n] = {0};
	int sumCol[n] = {0};
	int max = 0, count = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			sumRow[i] = sumRow[i] + a[i][j];
			sumCol[j] = sumCol[j] + a[i][j];
		}
		max = (max > sumRow[i])?max:sumRow[i];
	}
	for(int i = 0; i < n; i++) 
		max = (max > sumCol[i])?max:sumCol[i];
	for(int i = 0, j = 0; i < n && j < n;) {
		int diff = 0;
		diff = (sumRow[i] < sumCol[j])?(max-sumRow[i]):(max-sumCol[j]);
		count = count + diff;
		sumRow[i] = sumRow[i] + diff;
		sumCol[j] = sumCol[j] + diff;
		if(sumRow[i] == max)
			i++;
		if(sumCol[j] == max)
			j++;
	}
	return count;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int **a, n;
		cin >> n;
		a = new int*[n];
		for(int x = 0; x < n; x++) {
			a[x] = new int[n];
			for(int y = 0; y < n; y++)
				cin >> a[x][y];
		}
		cout << counter(a, n) << endl;
	} 
}
