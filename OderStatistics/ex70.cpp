#include <iostream>
#include <vector>
using namespace std;

int timMin(vector<vector<int> > a);
int timMinK(vector<vector<int> > a, int k);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, k; cin >> n >> k;
		int d = 0;
		vector<vector<int> > a(2*n, vector<int> (n, 0));
		for(int x = 0; x < n; x++)
			for(int y = 0; y < n; y++)
				cin >> a[x][y];
		cout << timMinK(a, k) << endl;
	}
}

int timMin(vector<vector<int> > a) {
	int min = 0;
	for(int i = 1; i < a.size(); i++)
		if(a[i][0] < a[min][0])
			min = i;
	return min;
			
}
int timMinK(vector<vector<int> > a, int k) {
	vector<vector<int> > temp(1, vector<int> (3, 0));
	vector<int> res;
	temp[0][0] = a[0][0];
	int n = a.size()/2;
	a[0+n][0] = 1;
	while(res.size() < k) {
		int x = timMin(temp), i, j;
		vector<int> temp1(3, 0);
		res.push_back(temp[x][0]);
		i = temp[x][1];
		j = temp[x][2];
		temp.erase(temp.begin()+x);
		if(i+1 < a.size() && a[n+i+1][j] == 0){
			a[n+i+1][j] = 1;
			temp1[0] = a[i+1][j]; temp1[1] = i+1; temp1[2] = j;
			temp.push_back(temp1);
		}
		if(j+1 < a[0].size() && a[n+i][j+1] == 0) {
			a[n+i][j+1] = 1;
			temp1[0] = a[i][j+1]; temp1[1] = i; temp1[2] = j+1;
			temp.push_back(temp1);
		}
	}
	return res[k-1];
}
