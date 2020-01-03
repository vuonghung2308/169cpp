#include <iostream>
#include <string>
using namespace std;

string sum_string(string str1, string str2) {
	if(str1.size() < str2.size())
		swap(str1, str2);
	int n = str2.size(),
		m = str1.size();
	string ans;
	int carry = 0;
	for(int i = 0; i < n; i++) {
		int sum = (str1[m-1-i] - '0'+ str2[n-1-i] - '0' + carry)%10;
		carry = (str1[m-1-i] - '0'+ str2[n-1-i] - '0' + carry)/10;
		ans = char(sum+'0') + ans;
	}
	for(int i = n; i < m; i++) {
		int sum = (str1[m-1-i] - '0' + carry)%10;
		carry = (str1[m-1-i] - '0'+ carry)/10;
		ans = char(sum+'0') + ans;
	}
	if(carry != 0)
		ans = char(carry + '0') + ans;
	return ans;
}
bool checkSum(string str, int begin, int len1, int len2) {
	string str1 = str.substr(begin, len1),
		   str2 = str.substr(begin+len1, len2),
		   str3 = sum_string(str1, str2);
	int len3 = str3.size();
	if(len3 > str.size() - begin - len1 -len2)
		return false;
	if(str3 == str.substr(begin+len1+len2, len3)) {
		if(begin+len1+len2+len3 == str.size())
			return true;
		else return checkSum(str, begin+len1, len2, len3);
	}  
	return false;
}
bool checkSumStr(string s) {
	int n = s.size();
	for(int i = 1; i < n; i++) {
		for(int j = 1; j + i < n; j++)
			if(checkSum(s, 0, i, j))
				return true;
	}
	return false;
}
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		string s; cin >> s;
		string res = (checkSumStr(s) == 1)? "YES": "NO";
		cout << res << endl;;
	}
}
