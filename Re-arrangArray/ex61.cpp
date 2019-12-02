#include <iostream>
#include <vector>
using namespace std;

int bitonic(vector<int> x);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> x(n, 0);
		for(int i = 0; i < n; i++)
			cin >> x[i];
		cout << bitonic(x) << endl;
	}
}

int bitonic(vector<int> x) {
	vector<int> l(x.size(), 1);
	vector<int> r(x.size(), 1);
	
	for(int i = 1; i < x.size(); i++)
		for(int j = 0; j < i; j++)
			if(x[i] > x[j] && l[i] < l[j] + 1)
				l[i] = l[j] + 1;
				
	for(int i = x.size() - 2; i >= 0; i--)
		for(int j = x.size() - 1; j > i; j--)
			if(x[i] > x[j] && r[i] < r[j] + 1)
				r[i] = r[j] + 1;
	
	int max = l[0] + r[0] - 1;
	for(int i = 1; i  < x.size(); i++)
		if(max < l[i] + r[i] - 1)
			max = l[i] + r[i] - 1;
	return max;
}
