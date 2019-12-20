#include<iostream>
using namespace std;

int FindLongest(int *a, int n) {
	int *temp = new int[n], lenth_max = 1;
	for(int i = 0; i < n; i++)
		temp[i] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++)
			if(a[j] < a[i] && temp[i] <= temp[j])
				temp[i] = temp[j] + 1;
		if(temp[i] > lenth_max)
			lenth_max = temp[i];
	}
	return lenth_max;
}

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a; cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << FindLongest(a, n) << endl;
	}
}
