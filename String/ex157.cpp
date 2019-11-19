#include <iostream>
#include <string>
using namespace std;

int max(string s);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		string s; cin >> s;
		cout << max(s) << endl;
	}
}
int max(string s) {
	int res = -1, i = 0;
	while(i < s.size()) {
		int temp = 0;
		while(s[i] <= '9' && s[i] >= '0') {
			temp = temp * 10 + s[i] - '0';
			i++;
		}
		if(res < temp)
			res = temp;
		i++;
	}
	return res;
}
