// chua toi uu

#include <iostream>
using namespace std;

int findMin(int *a, int n, int x);
int findMax(int *a, int n, int x);
void timDay(int *a, int n);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int *a, n; cin >> n;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		timDay(a, n);
	}
}

int findMin(int *a, int n, int x) {
	int min = a[x];
	for(int i = x+1; i < n; i++)
		if(min > a[i])
			min = a[i];
	return min;
}
int findMax(int *a, int n, int x) {
	int max = a[x];
	for(int i = 0; i < x; i++)
		if(max < a[i])
			max = a[i];
	return max;
}
void timDay(int *a, int n) {
	int i = 0, j = n-1;
	while(findMin(a, n, i) == a[i] && i < n)
		i++;
	while(findMax(a, n, j) == a[j] && j > -1)
		j--;
	if(i == n || j == 0)
		cout << -1 << endl;
	else cout << i << ' ' << j << endl;
}
