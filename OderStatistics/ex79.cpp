#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int findMin(vector<int> a);
bool find(vector<int> a, int x);
int tim(vector<int> a);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			a[j] = n-j;
		cout << tim(a) << endl;
	}
}
int findMin(vector<int> a) {
	int min = 0;
	while(a[min] < 0)
		min++;
	for(int i = 1; i < a.size(); i++)
		if(a[min] > a[i] && a[i] >= 0)
			min = i;
	return min;
}
bool find(vector<int> a, int x) {
	for(int i = 0; i  < a.size(); i++)
		if(a[i] == x)
			return true;
	return false;
}
int tim(vector<int> a) {
	int min = findMin(a);
	while(find(a, min+1))
		min++;
	return min+1;
}
