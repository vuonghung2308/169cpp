#include <iostream>
#include <cstring>
using namespace std;

int countSubString(char *c) {
	int len = strlen(c),
		i = 0,
		count = 0,
		count_max = 0;
	while(i < len && c[i] == '0')
		i++;
	while(i < len) {
		int num0 = 0,
			num1 = 0;
		while(i < len && c[i] == '1')
			num1++, i++;
		while(i < len && c[i] == '0')
			num0++, i++;
		if(num0 >= 2 && num1 >= 1) {
			num0 /= 2;
			num1 = (num1 < num0)? num1: num0;
			count = num1 + num1*2;
		}
		count_max = (count > count_max)? count: count_max;
	}
	return count_max;
}
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		char a[1000] = {};
		cin >> a;
		cout << countSubString(a) << endl;
	}
}
