#include <iostream>
#include <vector>
using namespace std;

int dem(vector<int> a, int k);

int main() {
	int t; cin >> t;
	for(int i =  1; i <= t; i++) {
		int n, k; cin >> n >> k;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++) 
			cin >> a[j];
		cout << dem(a, k) << endl;
	}
}
int dem(vector<int> a, int k) {
	int d = 0;
	for(int i = 0; i < a.size()-1; i++) {
		for(int j = i+1; j < a.size(); j++) {
			if(a[i] - a[j] == k || a[i] - a[j] == -k) {
				d++;
				a.erase(a.begin() + j);
			}
		}
	}
	return d;
}
