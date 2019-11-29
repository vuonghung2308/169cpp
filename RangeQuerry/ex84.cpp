#include <iostream>
using namespace std;

bool check(int x);
int dem(int l, int r);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int l, r; cin >> l >> r;
		cout << dem(l, r) << endl;
	}
	
}
bool check(int x) {
	if(x < 2)
		return false;
	for(int i = 2; i*i <= x; i++)
		if(x%i == 0)
			return false;
	return true;
}
int dem(int l, int r) {
	int d = 0;
	for(int i = l; i <= r; i++)
		if(check(i) == true)
			d++;
	return d;
}
