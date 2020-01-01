#include <iostream>
#include <cstring>
using namespace std;

bool check(char *str, int len) {
	int n = 'z'-'a'+1;
	int count[n] = {};
	for(int i = 0; i < len; i++)
		count[n-1-('z'-str[i])]++;
	int s = count[0];
	for(int i = 1; i < n; i++)
		s = (s > count[i])? (s-count[i]): (count[i]-2);
	if(s >= 2)
		return false;
	return true;
}
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		char c[1000] = {};
		cin >> c;
		int len = strlen(c);
		cout << check(c, len) << endl;
	}
}
