#include <iostream>
using namespace std;

void lietke(int *a, int *b, int *c, int na, int nb, int nc) {
	int x = 0, y = 0;
	for(int i = 0; i < na; i++) {
		while(b[x] < a[i] && x < nb)
			x++;
		if(b[x] == a[i]) {
			while(c[y] < a[i] && y < nc)
				y++;
			if(c[y] == a[i])
				cout << c[y] << ' ';
		}
	}
}
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int na, nb, nc, *a, *b, *c;
		cin >> na >> nb >> nc;
		a = new int[na];
		b = new int[nb];
		c = new int[nc];
		for(int j = 0; j < na; j++)
			cin >> a[j];
		for(int j = 0; j < nb; j++)
			cin >> b[j];
		for(int j = 0; j < nc; j++)
			cin >> c[j];
		lietke(a, b, c, na, nb, nc), cout << endl;
	}
}
