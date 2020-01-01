#include <iostream>
#include <cstring>
using namespace std;

int findSub(char *a, int len) {
	int sum[len] = {}, dp[len][3] = {};
	int dig = 0, curr = 0;
	dp[0][0] = 1;
	for(int i = 1; i <= len; i++) {
		dig = a[i-1] - '0';
		curr += dig;
		curr %= 3;
		sum[i] = curr;
		dp[i][0] = dp[i-1][0];
		dp[i][1] = dp[i-1][1];
		dp[i][2] = dp[i-1][2];
		dp[i][curr] += 1;
	}
	int ans = 0, value, dpre1, dpre2;
	for(int i = 1; i <= len; i++) {
		dig = a[i-1] - '0';
		if(dig == 8)
			ans++;
		if(i-2 >= 0) {
			dpre1 = a[i-2] -'0';
			value = dpre1*10 + dig;
			ans += (value%8 == 0 && value%3 != 0)? 1: 0;
		}
		if(i-3 >= 0) {
			dpre2 = a[i-3] - '0';
			dpre1 = a[i-2] - '0';
			value = dpre2*100 + dpre1*10 + dig;
			if(value % 8 != 0)
				continue;
			ans += (i-2);
			ans -= (dp[i-3][sum[i]]);
		}
	}
	return ans;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		char c[1000] = {};
		cin >> c;
		int length = strlen(c);
		cout << findSub(c, length) << endl;
	}
}
