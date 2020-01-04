#include <iostream>
#include <string>
using namespace std;

long long mod(string s, long long m) {
	int n = s.size();
	long long res = 0;
	for(int i = 0; i < n; i++)
		res = (res*10 + s[i] - '0')%m;
	return res;
}

int main() {
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
    	string s; long long m;
        cin >> s >> m;
        cout << mod(s, m) << std::endl;
    }
}

