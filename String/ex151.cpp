#include <iostream>
#include <vector>
using namespace std;

bool kiemtra(vector<int> a);
vector<int> chuyendoi(char *x);

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		char x[1001];
		vector<int> a;
		cin >> x;
		a = chuyendoi(x);
		if(kiemtra(a))
			cout << 1 << endl;
		else cout << 0 << endl;
	}
}
bool kiemtra(vector<int> a) {
	int t = 0, i = 0;
	while(i < a.size()) {
		while(i < a.size() && t < 5) {
			t = t * 2 + a[i];
			i++;
		}
		t = t % 5;
	}
	if(t == 0)
		return true;
	else return false;
}
vector<int> chuyendoi(char *x) {
	vector<int> res;
	int i = 0;
	while(x[i] != '\0') {
		res.push_back(x[i] - '0');
		i++;
	}
	return res;
}
