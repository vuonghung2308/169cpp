#include <iostream>
#include <vector>
using namespace std;

int findArea(int *a, int m) {
	int area = 0, areaMax = 0;
	int i = 0;
	vector<int> res;
	while(i < m) {
		if(res.empty() || a[res.back()] <= res[i])
			res.push_back(i++);
		else {
			int top_val = a[res.back()];
			area = i * top_val;
			res.pop_back();
			if(!res.empty())
				area = top_val * (i - res.back() - 1);
			areaMax = (area > areaMax)?area:areaMax;
		}
	}
	while(!res.empty()) {
		int top_val = a[res.back()];
		area = i * top_val;
		res.pop_back();
		if(!res.empty())
			area = top_val * (i - res.back() - 1);
		areaMax = (area>areaMax)?area:areaMax;
	}
	return area;
}
int findRectangle(int **a, int n, int m) {
	int res = findArea(a[0], m);
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < m; j++)
			if(a[i][j]) a[i][j] += a[i-1][j];
		int t = findArea(a[i], m);
		res = (res > t)?res:t;
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int x = 0; x < t; x++) {
		int **a, n, m; cin >> n >> m;
		a = new int* [n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[m];
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		}
		cout << findRectangle(a, n, m);
	}
}
