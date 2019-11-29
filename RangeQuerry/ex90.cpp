#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> a);
int tinhBuoc(vector<int> a);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << tinhBuoc(a) << endl;
	}
}

int findMin(vector<int> a) {
	int min = a[0];
	for(int i = 1; i < a.size(); i++)
		if(min > a[i])
			a[i] = min;
	return min;
}
int tinhBuoc(vector<int> a) {
	int dem = 0;
	int min = findMin(a), temp = 1;
	while(temp <= min) {
		temp = temp * 2;
		dem = dem + 1;
	}
	temp = temp / 2;
	dem = dem - 1 + min - temp;
	dem = dem + a.size();
	for(int i = 0; i < a.size(); i++)
		dem = dem + a[i] - min;
	return dem;
}
