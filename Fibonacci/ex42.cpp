#include <iostream>
#include <cmath>;
using namespace std;

bool check(long long n);
bool isPerfectSquare(long long n);

int main() {
    short t; long long n;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n;
        if(check(n)) 
            std::cout << "YES" << std::endl;
        else std::cout << "NO " << std::endl;
    }
}
bool check(long long n) {
    return isPerfectSquare(5*n*n+4) || isPerfectSquare(5*n*n-4);
}
bool isPerfectSquare(long long n) {
	long long x = (long long) sqrt(n);
	return (x*x == n);
}
