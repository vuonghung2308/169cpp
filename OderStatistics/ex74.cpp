#include <iostream>
#include <vector>
using namespace std;

void nhap(vector<int> &a, int &k);
void lietke(vector<int> a, int k);
int max(vector<int> a, int k);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		vector<int> a; int k; nhap(a, k);
		lietke(a, k);
		cout << endl;
	}	
}
void nhap(vector<int> &a, int &k) {
	int n;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int t; cin >> t;
		a.push_back(t);		
	}
}
void lietke(vector<int> a, int k) {
	while(a.size() >= k) {
		cout << max(a, k) << ' ';
		a.erase(a.begin());
	}
}
int max(vector<int> a, int k) {
	int m = a[0];
	for(int i = 1; i < k; i++)
		if(m < a[i])
			m = a[i];
	return m;
}
