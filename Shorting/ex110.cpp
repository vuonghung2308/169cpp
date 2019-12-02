#include <iostream>
#include <vector>
using namespace std;

void sapxep(vector<vector<int> > &a);
void hienthi(vector<vector<int> > a);
void dem(vector<vector<int> > &a);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<vector<int> > a(2, vector<int> (n, 1));
		for(int j = 0; j < n; j++)
			cin >> a[0][j];
		dem(a);
		sapxep(a);
		hienthi(a);
	}
}
void dem(vector<vector<int> > &a) {
	for(int i = 0; i < a[0].size()-1; i++) {
		for(int j = i+1; j < a[0].size(); j++) {
			if(a[0][j] == a[0][i]) {
				a[1][i]++;
				a[0].erase(a[0].begin()+j);
				a[1].erase(a[1].begin()+j);
				j--;
			}
		}
	}
}
void sapxep(vector<vector<int> > &a) {
	for(int i = 0; i < a[0].size()-1; i++) {
		for(int j = i+1; j < a[0].size(); j++) {
			if(a[1][j] > a[1][i] || (a[1][i] == a[1][j] && a[0][i] > a[0][j]) ) {
				int t = a[0][i]; a[0][i] = a[0][j]; a[0][j] = t;
				int T = a[1][i]; a[1][i] = a[1][j]; a[1][j] = T;
			}
		}
	}
}
void hienthi(vector<vector<int> > a) {
	for(int i = 0; i < a[0].size(); i++)
		for(int j = 0; j < a[1][i]; j++)
			cout << a[0][i] << ' ';
	cout << endl;
}
