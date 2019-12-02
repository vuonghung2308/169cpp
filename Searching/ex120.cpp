#include <iostream>
using namespace std;
bool kiemtra(int x);
void tim(int x);
int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int x; cin >> x;
		tim(x);
	}
}
bool kiemtra(int x) {
	if(x < 2)
		return false;
	for(int i = 2; i*i <= x; i++)
		if(x%i == 0)
			return false;
	return true;
}
void tim(int x) {
	bool ok = false;
	for(int i = 2; i <= x; i++) {
		if(kiemtra(i) && kiemtra(x-i)) {
			cout << i << ' ' << x-i << endl;
			ok = true;
			break;
		}
	}
	if(!ok)
		cout << -1 << endl;
}
