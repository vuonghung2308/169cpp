#include <iostream>
#include <fstream>
using namespace std;

int dem(string s);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		fflush(stdin);
		string s; getline(cin, s);
		cout << dem(s) << endl;
	}
}
int dem(string s) {
	int d = 0, i = 0;
	while(i < s.size()) {
		while(s[i] == ' ' && s[i] != '\0')
			i++;
		if(s[i] != '\0')
			d++;
		while(s[i] != ' ' && s[i] != '\0')
			i++;
	}
	return d;
}
