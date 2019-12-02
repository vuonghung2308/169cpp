#include <iostream>
#include <string>
using namespace std;

void dao_chuoi(string &my_string);

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		fflush(stdin);
		string my_string;
		getline(cin, my_string);
		dao_chuoi(my_string);
		cout << my_string << endl;
	}	
}
void dao_chuoi(string &my_string) {
	string res;
	string temp;
	int i = 0;
	while(i < my_string.size()) {
		while (my_string[i] != ' ' && i < my_string.size()) {
			temp.push_back(my_string[i]);
			i++;
		}
		res.insert(res.begin(), temp.begin(), temp.end());
		if(my_string[i]== ' ')
			res.insert(res.begin(), ' ');
		temp.clear();
		i++;
	}
	my_string.clear();
	my_string =  res;
}
