#include <iostream>
#include <vector>
using namespace std;

int tim(vector<int> a, int k);
void hienthi(vector<int> a, int x, int y);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, k; cin >> n >> k;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		hienthi(a, tim(a, k), tim(a, k)+k); cout << endl;
	}
}
int tim(vector<int> a, int k) {
	vector<int> x;
	for(int i = 0; i <= a.size()-k; i++) {
		int t = 0;
		for(int j = i; j < i+k; j++)
			t = t + a[j];
		x.push_back(t);
	}
	int max = 0;
	for(int i = 1; i < x.size(); i++)
		if(x[max] < x[i])
			max = i;
	return max;
}
void hienthi(vector<int> a, int x, int y) {
	for(int i = x; i < y; i++)
		cout << a[i] << ' ';
}
