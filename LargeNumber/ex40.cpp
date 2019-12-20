#include <iostream>
#include <vector>
using namespace std;

bool sosanh(vector<int> x, vector<int> y);
vector<int> nhan(vector<int> a, int x);
void tru(vector<int> &a, vector<int> b);
vector<int> chia(vector<int> a, vector<int> b);
vector<int> chuyendoi(char *x);
void hienthi(vector<int> a);

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		char x[1000], y[1000];
		cin >> x >> y;
		vector<int> a = chuyendoi(x);
		vector<int> b = chuyendoi(y);
		a = chia(a, b);
		hienthi(a);
		cout << endl;
	}
}
bool sosanh(vector<int> x, vector<int> y) {
	if(x.size() > y.size())
		return true;
	if(x.size() < y.size())
		return false;
	int i = 0;
	while(x[i] == y[i] && i < x.size())
		i++;
	if(i == x.size())
		return true;
	if(x[i] >= y[i])
		return true;
	return false;
}
vector<int> nhan(vector<int> a, int x) {
	vector<int> res;
	int t = 0;
	for(int i = a.size()-1; i >= 0; i--) {
		t = t + x * a[i];
		res.insert(res.begin(), t % 10);
		t = t / 10;
	}
	if(t != 0)
		res.insert(res.begin(), t);
	return res;
}
void tru(vector<int> &a, vector<int> b) {
	int i = 0, na = a.size(), nb = b.size();
	int t = 0;
	while(i < na) {
		if((int) nb-i-1 >= 0)
			t = t + b[nb-1-i];
		if(t > a[na-1-i]) {
			a[na-1-i] = a[na-1-i] + 10 - t;
			t = 1;
		}
		else {
			a[na-1-i] = a[na-1-i] - t;
			t = 0;
		}
		i++;
	}
	i = 0;
	while(a[i] == 0 && i < a.size()) {
		a.erase(a.begin());
	}
}
vector<int> chia(vector<int> a, vector<int> b) {
	int i = b.size();
	vector<int> temp, temp2;
	vector<int> res;
	while(!sosanh(temp, b)) {
		temp.push_back(a[0]);
		a.erase(a.begin()); 
	}
	temp2 = temp;
	while(sosanh(temp2, b)) {
		int d;
		if(temp.size() > b.size())
			d = 9;
		else d = temp[0] / b[0];
		while(!sosanh(temp, nhan(b, d)))
			d--;
		tru(temp, nhan(b, d));
		res.push_back(d);
		if(!a.empty()) {
			temp.push_back(a[0]);
			a.erase(a.begin());
		}
		temp2 = temp;
		if(!a.empty())
			temp2.insert(temp2.end(), a.begin(), a.end());
	}
	return res;
}
vector<int> chuyendoi(char *x) {
	int i = 0;
	vector<int> res;
	while(x[i] != '\0') {
		res.push_back(x[i] - '0');
		i++;
	}
	return res;
}
void hienthi(vector<int> a) {
	for(int i = 0; i < a.size(); i++)
		cout << a[i];
}
