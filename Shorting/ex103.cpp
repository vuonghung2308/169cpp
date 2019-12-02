//chua toi uu

#include <iostream>
#include <vector>
using namespace std;

void sapxep(vector<long long> a);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		vector<long long> a(n, 0);
		for(int j = 0; j < n; j++)
			cin >> a[j];
		sapxep(a);
	}
}
void sapxep(vector<long long> a) {
	int t[10] = {};
	for(int i = 0; i < a.size(); i++) {
		while(a[i]) {
			if(t[a[i]%10] == 0)
				t[a[i]%10]++;
			a[i] = a[i] / 10;
		}
	}
	for(int i = 0; i < 10; i++)
		if(t[i])
			cout << i << ' ';
	cout << endl;
}
