#include <iostream>
#include <vector>
#include <string>
using namespace std;

void hienthi(string mystring) {
	vector<string> worlds;
	int i = 0, n = mystring.size();
	while(i < n) {
		while(i < n && mystring[i] == ' ')
			i++;
		string temp;
		while(i < n && (mystring[i] != ' ' && mystring[i] != '\0'))
			temp.push_back(mystring[i++]);
		worlds.push_back(temp);
	}
	for(int i = 0; i < worlds.size()-1; i++)
		cout << worlds[i] << ' ';
	cout << worlds[worlds.size()-1] << endl;
}

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		string mystring;
		fflush(stdin);
		getline(cin, mystring);
		hienthi(mystring);
	}
}
