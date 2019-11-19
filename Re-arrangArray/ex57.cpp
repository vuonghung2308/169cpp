#include <iostream>
#include <vector>
using namespace std;

int chon(int x, int y);
void sapxep(vector<int> &x);
void hienthi(vector<int> x);
void doi(int &x, int &y);

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		vector<int> x(n, 0);
		for(int j = 0; j < n; j++)
			cin >> x[j];
		sapxep(x);
		hienthi(x);
	}
}

int chon(int x, int y) {
	long long a = x, b = y;
	vector<int> a1, a2;
	while(x!=0) {
		a1.insert(a1.begin(), x%10);
		x = x / 10;
	}
	while(y!=0) {
		a2.insert(a2.begin(), y%10);
		y = y / 10;
	}
	for(int i = 0; i < a2.size(); i++)
		a = a * 10 + a2[i];
	for(int i = 0; i < a1.size(); i++)
		b = b * 10 + a1[i];
	if(a >= b)
		return 1;
	else return 2;
}
void sapxep(vector<int> &x) {
	for(int i = 0; i < x.size()-1; i++)
		for(int j = i + 1; j < x.size(); j++)
			if(chon(x[i], x[j]) == 2)
				doi(x[i], x[j]);
}
void hienthi(vector<int> x) {
	for(int i = 0; i < x.size(); i++)
		cout << x[i];
	cout << endl;
}
void doi(int &x, int &y) {
	int t = x; x = y; y = t;
}
