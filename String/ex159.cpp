#include <iostream>
#include <string>
using namespace std;

string findSubStr(string str, string pat) {
	int start = 0,
		start_index = -1,
		count = 0,
		len_min = INT_MAX,
		len1 = str.length(),
		len2 = pat.length(),
		count_str[256] = {},
		count_pat[256] = {};
	for(int i = 0; i < len2; i++)
		count_pat[pat[i]]++;
	for(int i = 0; i < len1; i++) {
		count_str[str[i]]++;
		if(count_pat[str[i]] != 0 && count_str[str[i]] <= count_pat[str[i]])
			count++;
		if(count == len2) {
			while(count_str[str[start]] > count_pat[str[start]] || count_str[str[start]] == 0) {
				if(count_str[str[start]] > count_pat[str[start]])
					count_str[str[start]]--;
				start++;
			}
			
			int sub_len = i - start + 1;
			if(sub_len < len_min) {
				start_index = start;
				len_min = sub_len;
			} 
		}
	}
	return (start_index == -1)? "-1": str.substr(start_index, len_min);
}
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s1, s2;
		fflush(stdin);
		getline(cin, s1);
		getline(cin, s2);
		cout << findSubStr(s1, s2) << endl;
	}
}

