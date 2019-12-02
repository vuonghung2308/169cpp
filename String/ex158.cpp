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
	int res = 0, i = 0;
	while(i < s.size()) {
		if( res + s[i] - '0' > res*(s[i] - '0') )
			res = res + s[i] - '0';
		else res = res*(s[i] - '0');
		i++;
	}
	return res;
}
