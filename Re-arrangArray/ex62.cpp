#include <iostream>
#include <vector>
using namespace std;

int tich_max(vector<int> x);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> x(n, 0);
		for(int i = 0; i < n; i++)
			cin >> x[i];
		cout << tich_max(x) << endl;
	}
}
int tich_max(vector<int> x) {
	vector<int> max;
	int i = 0;
	
	
	while(i < x.size()) {
		bool check = false;
		int temp = 1, temp1 = 1;
		while(i < x.size() && x[i] != 0) {
			if(x[i] == -1) {
				max.push_back(temp);
				max.push_back(temp * (-1));
				check = true;
			}
			if(check)
				temp1 = temp1 * x[i];
			temp = temp * x[i];
			i++;
		}
		max.push_back(temp);
		if(check) {
			max.push_back(temp1);
			max.push_back(temp1 * (-1));
		}
		temp = 1;
		i++;
	}
	
	int temp = max[0];
	for(int i = 1; i < max.size(); i++)
		if(temp < max[i])
			temp = max[i];
	return temp;
}
