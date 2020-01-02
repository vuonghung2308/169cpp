#include <iostream>
#include <string>
using namespace std;
const int MAX_CHAR = 26;

int countSub(string s) {
	int count[MAX_CHAR] = {},
		len = s.length(),
		sum = 0;
	for(int i = 0; i < len; i++)
		count[s[i] - 'a']++;
	for(int i = 0; i < MAX_CHAR; i++)
		sum += (count[i]*(count[i]+1))/2;
	return sum;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s;
		cin >> s;
		cout << countSub(s) << endl;
	}
}
