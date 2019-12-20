#include <iostream>
#include <string>
using namespace std;

string tim(string a) {
	if(a.length() > 9)
		return "-1";
	string res;
	int n = a.size(), temp = 1;
	if(a[0] == 'D') {
		int i = 0;
		while(a[i] == 'D') {
			temp++;
			i++;
		}
	}
	int max = temp;
	res.push_back('0' + temp);
	for(int i = 0; i < n; i++) {
		if(a[i] == 'D') {
			temp = temp - 1;
			res.push_back('0' + temp);
		}
		else if(a[i+1] == 'I' || a[i+1] == '\0') {
			max = max + 1;
			res.push_back('0' + max);
		}
		else {
			int j = i + 1;
			max = max + 1;
			while(a[j] == 'D') {
				j = j + 1;
				max = max + 1;
			}
			res.push_back('0' + max);
			temp = max;
		}
	}
	return res;
}

int main()  
{ 
    int t; cin >> t;
  
    for (int i = 0; i < t; i++) 
    {
    	string input; cin >> input;
        cout << tim(input) << "\n"; 
    } 
    return 0;  
} 
