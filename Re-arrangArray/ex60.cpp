#include <iostream>
#include <string>
#include <vector>
using namespace std;

string chuyendoi(string c);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		string c; cin >> c;
		cout << chuyendoi(c) << endl;
	}
}
string chuyendoi(string c) {
	string res;
	vector<bool> check(10, true);
	int i = 0, begin = 1;
	if(c[0] == 'I') {
		res.push_back('1');
		check[1] = false;
	}
	else {
		while(c[i] == 'D' && c[i] != '\0') {
			begin++; i++;
		}
		for(int j = begin; j >= 1; j--) {
			res.push_back('0'+ j);
			check[j] = false;
		}
	}
	for(; i < c.size(); i++) {
		if(c[i] == 'D') 
			begin = begin - 1;
		else if(c[i] == 'I' && c[i+1] == 'D') {
			int t = i;
			while(c[t+1] == 'D')
				t++;
			t = t - i;
			begin = begin + t + 1;
			
		}
		else {
			begin = begin + 1;
			while(check[begin] == false && begin <= 9)
				begin = begin + 1;
		}
		res.push_back('0'+begin);
		check[begin] = false;
	}
	return res;
}
