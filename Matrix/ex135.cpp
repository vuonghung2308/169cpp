#include <iostream>
using namespace std;

void print(int n) {
	int m = 8*n*n;
	int coil1[m], coil2[m];
	int curr = coil1[0] = m + 2*n;
	
	int index = 1, step = 2, nflg = 1;
	while(index < m) {
		for(int i = 0; i < step; i++) {
			curr = coil1[index++] = curr - nflg*4*n;
			if(index >= m)
				break;
		}
		if(index >= m)
			break;
		for(int i = 0; i < step; i++) {
			curr = coil1[index++] = curr + nflg;
			if(index >= m)
				break;
		}
		step = step + 2;
		nflg = -nflg;
	}
	for(int i = 0; i < m; i++)
		coil2[i] = 16*n*n + 1 - coil1[i];
	for(int i = 0; i < m; i++)
		cout << coil1[i] << ' ';
	cout << endl;
	for(int i = 0; i < m; i++)
		cout << coil2[i] << ' ';
	cout << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		print(n);
	}
}
