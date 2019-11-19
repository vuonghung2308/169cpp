#include <iostream>
#include <string>
using namespace std;

void su_ly(string &my_string);
void sapxep(string &my_string);

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		string my_string;
		cin >> my_string;
		su_ly(my_string);
		cout << my_string << endl;
	}
}

void su_ly(string &my_string) {
	int t = 0;
	for(int i = 0; i < my_string.size(); i++) {
		if(my_string[i] <= '9' && my_string[i] >= '0') {
			t = t + my_string[i] - '0';
			my_string.erase(my_string.begin() + i);
			i--;
		}
	}
	sapxep(my_string);
	int temp = my_string.size();
	while(t!=0) {
		my_string.insert(my_string.begin()+temp, '0'+t%10);
		t = t / 10;
	}
}
void sapxep(string &my_string) {
	for(int i = 0; i < my_string.size()-1; i++) {
		for(int j = i + 1; j < my_string.size(); j++)
			if(my_string[i] > my_string[j]) {
				char temp = my_string[i];
				my_string[i] = my_string[j];
				my_string[j] = temp;
			}
	}
}
