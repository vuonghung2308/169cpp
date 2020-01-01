#include <iostream>
using namespace std;

int findSize(char **a, int n) {
	int ver[n][n], hor[n][n];
	int max = 0;
	hor[0][0] = ver[0][0] = (a[0][0] == 'X');
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 'O')
				ver[i][j] = hor[i][j] = 0;
			else {
				ver[i][j] = (i == 0)? 1: ver[i-1][j] + 1;
				hor[i][j] = (j == 0)? 1: hor[i][j-1] + 1;
			}
		}
	}
	for(int i = n-1; i >= 1; i--) {
		for(int j = n-1; j >= 1; j--) {
			int min = (hor[i][j] < ver[i][j])? hor[i][j]: ver[i][j];
			while(min > max) {
				if(ver[i][j-min+1] >= min && hor[i-min+1][j] >= min)
					max = min;
				min--;
			}
		}
	}
	return max;
}
int main() {
	int t; cin >> t; 
	for(int x = 0; x < t; x++) {
		char **a;
		int n; cin >> n;
		a = new char*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new char[n];
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		cout << findSize(a, n) << endl;
	}
}
