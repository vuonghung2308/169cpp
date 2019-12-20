#include <iostream>
using namespace std;
int FindLenth(int *a, int *b, int n) {
	int sum1;
	int sum2;
	int i = 0, max = 0;
	while(i < n-1) {
		int j = i+1;
		sum1 = a[i];
		sum2 = b[i];
		do {
			sum1 += a[j];
			sum2 += b[j];
			j++;
		} while(sum1 == sum2 && j < n);
		if(max < j - i)
			max = j - i - 1;
		i++;
	}
	return max;
}

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a, *b; cin >> n;
		a = new int[n];
		b = new int[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++)
			cin >> b[i];
		cout << FindLenth(a, b, n) << endl;
	}
}
