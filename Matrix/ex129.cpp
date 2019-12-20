#include <iostream>
#include <vector>
using namespace std;

int lietke(vector<vector<int> > a);
bool timkiem(vector<int> a, int x);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<vector<int> > a(n, vector<int>(n, 0));
		for(int j = 0; j < n; j++) 
			for(int o = 0; o < n; o++)
				cin >> a[j][o];
		cout << lietke(a) <<  endl;
	}
}
int lietke(vector<vector<int> > a) {
	int dem = 0;
	for(int i = 0; i < a[0].size(); i++) {
		bool check = true;
		for(int j = 1; j < a.size(); j++) {
			check = timkiem(a[j], a[0][i]);
			if(check == false)
				break;
		}
		if(check == true)
			dem++;
	}
	return dem;
}
bool timkiem(vector<int> a, int x) {
	for(int i = 0; i < a.size(); i++)
		if(a[i] == x)
			return true;
	return false;
}
