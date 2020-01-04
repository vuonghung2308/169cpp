#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<vector<int> > a) {
	int min = 0;
	for(int i = 0; i < a.size(); i++)
		min = (a[i][0] < a[min][0])? i: min;
	return min;
} 
int findMinK(vector<vector<int> > a, int k) {
	vector<vector<int> > visited(a.size(), vector<int> (a[0].size(), 0));
	vector<vector<int> > temp(1, vector<int> (3, 0));
	vector<int> res;
	temp[0][0] = a[0][0];
	visited[0][0] = 1;
	while(res.size() < k) {
		int x = findMin(temp);
		vector<int> temp1(3, 0);
		res.push_back(temp[x][0]);
		int i = temp[x][1];
		int j = temp[x][2];
		temp.erase(temp.begin()+x);
		if(i+1 < a.size() && visited[i+1][j] == 0) {
			visited[i+1][j] = 1;
			temp1[0] = a[i+1][j];
			temp1[1] = i+1;
			temp1[2] = j;
			temp.push_back(temp1);
		}
		if(j+1 < a[0].size() && visited[i][j+1] == 0) {
			visited[i][j+1] = 1;
			temp1[0] = a[i][j+1];
			temp1[1] = i;
			temp1[2] = j+1;
			temp.push_back(temp1);
		}
	}
	return res[k-1];
}
int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, k; cin >> n >> k;
		int d = 0;
		vector<vector<int> > a(n, vector<int> (n, 0));
		for(int x = 0; x < n; x++)
			for(int y = 0; y < n; y++)
				cin >> a[x][y];
		cout << findMinK(a, k) << endl;
	}
}
