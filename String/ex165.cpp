#include <iostream>
#include <string>
using namespace std;

int find_character(char x, string s);
bool check(char x, string s, int t);
void xoa(string &s);

int main () {
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++) {
		string s;
		cin >> s;
		xoa(s);
		cout << s << endl;
	}
}
int find_character(char x, string s) {
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == x)
			return i;
	}
	return -1;
}
bool check(char x, string s, int t) {
	for(int i = t+1; i < s.size(); i++)
		if(s[i] == x)
			return true;
	return false;
}
void xoa(string &s) {
	for(int i = 0; i <= s.size(); i++) {
		if(check(s[i], s, i)) {
			char temp = s[i];
			while(find_character(temp, s)!= -1)
				s.erase(s.begin()+find_character(temp, s));
			i--;
		}
	}
}
