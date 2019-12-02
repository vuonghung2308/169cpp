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
	int c = 0, l = 0;
	for(int i = 0; i < a.size(); i++) {
		if(i%2 == 0)
			c = c + a[i];
		else l = l + a[i];
	}
	if( (c-l)%11 == 0 || (l-c)%11 == 0)
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
