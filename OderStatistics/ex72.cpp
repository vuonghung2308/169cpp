#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> a);
int findMin(vector<int> a, int x, int y);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		int max = findMax(a);
		int min = findMin(a, 0, max-1);
		if(min == -1)
			cout << -1 << endl;
		else cout << a[max] - a[min] << endl;
	}
}
int findMax(vector<int> a) {
	int max = 0;
	for(int i = 1; i < a.size(); i++)
		if(a[i] > a[max])
			max = i;
	return max;
}
int findMin(vector<int> a, int x, int y) {
	if(y < 0)
		return -1;
	int min = x;
	for(int i = x; i <= y ; i++)
		if(a[i] < a[min])
			min = i;
	return min;
}
