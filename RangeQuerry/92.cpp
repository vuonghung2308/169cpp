#include <iostream>
#include <vector>
using namespace std;

void sapXep(vector<int> &a);
int timMin(vector<int> a);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		cout << timMin(a) << endl;
	}
}
void sapXep(vector<int> &a) {
	for(int i = 0; i < a.size()-1; i++) {
		for(int j = i+1; j < a.size(); j++) {
			if(a[i] > a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
int timMin(vector<int> a) {
	sapXep(a);
	vector<int> t;
	for(int i = 0; i < a.size()-1; i++)
		t.push_back(a[i+1] - a[i]); 
	int min = t[0];
	for(int i = 1; i < t.size(); i++) 
		if(t[i] < min)
			min = t[i];
	return min;
}
