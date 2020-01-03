#include <iostream>
#include <string>
using namespace std;

int countSub(string s, int k) {
	int res = 0,
		n = s.length();
	for(int i = 0; i < n; i++) {
		int count[26] = {};
		int diff = 0;
		for(int j = i; j < n ; j++) {
			if(count[s[j] - 'a'] == 0)
				diff++;
			count[s[j] - 'a']++;
			if(diff == k)
				res++;
			if(diff > k)
				break;
		}
	}
	return res;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int k;
		string s;
		cin >> s >> k;
		cout << countSub(s, k) << endl;
	}
}
