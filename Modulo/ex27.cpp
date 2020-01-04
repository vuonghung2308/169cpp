#include <iostream>
using namespace std;

int tinh(int a, int m);

int main() {
    int t, a, m;
    std::cin >> t;
    for(int i = 1; i <= t; i++) {
        std::cin >> a >> m;
        std::cout << tinh(a, m) << std::endl;
    }
}
int tinh(int a, int m) {
    for(int i = 1; i < a;i ++) {
    	int x = (i*m +1) / a;
    	if((i*m +1) % a == 0 && x > 0)
    		return x;
	}
    return -1;
}
