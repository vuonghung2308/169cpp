#include <iostream>
using namespace std;

void sapxep(int *a, int n);
void doicho(int *x, int *y);


int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, *a; cin >> n;
		a = new int[n];
		for(int j = 0; j < n; j++)
			cin >> a[j];
		sapxep(a, n); 
		for(int j = 0; j < n; j++)
			cout << a[j] << ' ';
		cout << endl;	
	}
}

void sapxep(int *a, int n) {
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(a[i] > a[j])
				doicho(&a[i], &a[j]);
}
void doicho(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}
