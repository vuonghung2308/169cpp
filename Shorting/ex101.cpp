#include <iostream>
#include <algorithm>
using namespace std;

int countY(int x, int *y, int ny, int *no_of_y) {
	if(x == 0)
		return 0;
	if(x == 1)
		return no_of_y[0];
	int *idx = upper_bound(y, y+ny, x);
	int ans = (y+ny) - idx;
	ans += (no_of_y[0]+no_of_y[1]);
	if(x == 2)
		ans -= (no_of_y[3]+no_of_y[4]);
	if(x == 3)
		ans += no_of_y[2];
	return ans;
}
int countPairs(int *x, int *y, int nx, int ny) {
	int no_of_y[5] = {};
	for(int i  = 0; i < ny; i++)
		if(y[i] < 5)
			no_of_y[y[i]]++;
	sort(y, y+ny);
	int ans = 0;
	for(int i = 0; i < nx; i++)
		ans += countY(x[i], y, ny, no_of_y);
	return ans;
}
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int *x, *y, nx, ny;
		x = new int[nx];
		y = new int[ny];
		cin >> nx >> ny;
		for(int j = 0; j < nx; j++)
			cin >> x[j];
		for(int j = 0; j < ny; j++)
			cin >> y[j];
		cout << countPairs(x, y, nx, ny) << endl;
	}
		
}
