#include <iostream>
#include <vector>
using namespace std;

vector<int> chuyendoi(char *c);
vector<int> sapxep(vector<int> x);
void hienthi(vector<int> x);

int main() {
	int t; cin >> t;
	for(int i = 1;i <= t; i++) {
		char c[1001] = {}; cin >> c;
		vector<int> x = chuyendoi(c);
		hienthi(sapxep(x));
	}
}
vector<int> chuyendoi(char *c) {
	vector<int> res(10, 0);
	int i = 0;
	while(c[i] != '\0') {
		res[c[i] - '0']++;
		i++;
	}
	return res;
}
vector<int> sapxep(vector<int> x) {
	vector<int> res; int max = -1;
	for(int i = 1; i <= 9; i++) {
		if(x[i]%2 == 0 && x[i] != 0) {
			for(int j = 1; j <= x[i]/2; j++) {
				res.insert(res.begin(), i);
				res.insert(res.end(), i);
			}
		}
	}
	if(res.empty()) {
		int i = 9;
		while(x[i]%2 == 0 && i > 0)
			i--;
		max = i;
		for(int i = 1; i <= 9; i++)
			if(x[i] > x[max] && x[i]%2 == 1)
				max = i;
	}
	else {
		int i = 9;
		while(x[i]%2 == 0 && i > 0)
			i--;
		max = i;
		for(int i = 0; i <= 9; i++)
			if(x[i] > x[max] && x[i]%2 == 1)
				max = i;
	}
	vector<int> temp(x[max], max);
	res.insert(res.begin()+res.size()/2, temp.begin(), temp.end());
	return res;
}
void hienthi(vector<int> x) {
	for(vector<int>::iterator it = x.begin(); it < x.end(); it++)
		cout << *it;
	cout << endl;
}
