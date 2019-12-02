#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> a);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << a[findMax(a)] << endl;
	}
	
}
int findMax(vector<int> a) {
	int i = 0;
	while(a[i] < a[i+1])
		i++;
	return i;
}
