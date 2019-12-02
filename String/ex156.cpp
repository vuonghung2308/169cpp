#include <iostream>
#include <string>
using namespace std;

int tong(string s);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		string s; cin >> s;
		cout << tong(s) << endl;
	}
}
int tong(string s) {
	int res = 0, i = 0;
	while(i < s.size()) {
		int temp = 0;
		while(s[i] <= '9' && s[i] >= '0') {
			temp = temp * 10 + s[i] - '0';
			i++;
		}
		res = res + temp;
		i++;
	}
	return res;
}
