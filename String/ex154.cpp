#include <iostream>
#include <string>
#include <vector>
using namespace std;

void tong_min(string a, string b);
void tong_max(string a, string b);
void tong(string a, string b);
vector<int> chuyen_doi(string x);

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		string a, b;
		cin >> a >> b;
		tong_min(a, b);
		tong_max(a, b);
	}
}
void tong_min(string a, string b) {
	for(int i = 0; i <= a.size(); i++)
		if(a[i] == '6')
			a[i] = '5';
	for(int i = 0; i <= b.size(); i++)
		if(b[i] == '6')
			b[i] = '5';
	tong(a, b);
	cout << ' ';
}
void tong_max(string a, string b) {
	for(int i = 0; i <= a.size(); i++)
		if(a[i] == '5')
			a[i] = '6';
	for(int i = 0; i <= b.size(); i++)
		if(b[i] == '5')
			b[i] = '6';
	tong(a, b);
	cout << endl;
}
void tong(string a, string b) {
	if(a < b)
		tong(b, a);
	else {
		vector<int> x = chuyen_doi(a);
		vector<int> y = chuyen_doi(b);
		vector<int> res;
		int temp = 0;
		for(int i = 0; i < a.size(); i++) {
			if((int) y.size()-1-i >= 0)
				temp = temp + y[y.size() - i-1];
			if(temp + x[x.size()-1-i] < 10) {
				res.insert(res.begin(), temp + x[x.size()-1-i]);
				temp = 0;
			}
			else {
				res.insert(res.begin(), temp + x[x.size()-1-i]-10);
				temp = 1;
			}
			
		}
		if(temp!=0)
			res.insert(res.begin(), temp);
		for(int i = 0; i < res.size(); i++)
			cout << res[i];
	}
}
vector<int> chuyen_doi(string x) {
	vector<int> res;
	int i = 0;
	while(x[i]!= '\0') {
		res.push_back(x[i] - '0');
		i++;
	}
	return res;
}
