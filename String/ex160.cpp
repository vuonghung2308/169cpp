#include <iostream>
#include <string>
using namespace std;

int findLength(string str) {
	int count_c = 0,
		len = str.length(),
		len_min = INT_MAX,
		start = 0;
	bool visited[256] = {false};
	for(int i = 0; i < len; i++)
		if(visited[str[i]] == false)
			count_c++, visited[str[i]] = true;
	int count_cstr[256] = {},
		count = 0;
	for(int i = 0; i < len; i++) {
		count_cstr[str[i]]++;
		if(count_cstr[str[i]] == 1)
			count++;
		if(count == count_c) {
			while(count_cstr[str[start]] > 1) {
				if(count_cstr[str[start]] >1)
					count_cstr[str[start]]--;
				start++;
			}
			int sub_len = i - start + 1;
			len_min = (sub_len < len_min)? sub_len: len_min;
		}
	}
	return len_min;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s;
		fflush(stdin);
		getline(cin, s);
		cout << findLength(s) << endl;
	}
}
