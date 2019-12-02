#include <iostream>
#include <string>
using namespace std;

bool check(string s, int n);

int main() {
	string s;
	int n;
	cin >> s >> n;
	cout << check(s, n);
}
bool check(string s, int n) {
	int t = 26;
	for(int i = 'a'; i <= 'z'; i++) {
		if(s.find((char) i) != -1 || s.find((char) (i - 32)) != -1) {
			if(s.find((char) i) != -1) {
				s.erase(s.begin()+s.find((char) i));
				t = t - 1;
				continue;
			}
			if(s.find((char) i - 32) != -1) {
				s.erase(s.begin()+s.find((char) (i - 32)));
				t = t - 1;
				continue;
			}
		}
	}
	if(s.length() >= t && n >= t)
		return 1;
	else return 0;
}
