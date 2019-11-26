#include <iostream>
#include <vector>
using namespace std;

void lietke(vector<int> a);
int find(vector<int> a, int x);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<int> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		lietke(a);
	}
	
}
void lietke(vector<int> a) {
	
	for(int i = 0; i < a.size(); i++)
		if(find(a, a[i]) == a[i])
			cout << '_' << ' ';
		else 
			cout << find(a, a[i]) << ' ';
	cout << endl;
}
int find(vector<int> a, int x) {
	int i = 0, min;
	while(a[i] <= x && i < a.size())
		i++;
	if(i == a.size())
		return x;
	min = a[i];
	for(int i = 0; i < a.size(); i++)
		if(min > a[i] && a[i] > x)
			min = a[i];
	return min;
}
