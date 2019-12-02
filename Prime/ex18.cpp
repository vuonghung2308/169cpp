#include <iostream>

bool check(long long x);

int main() {
    long long t, n;
    std::cin >> t;
    for(long long i = 1; i <= t; i++) {
        std::cin >> n;
        if(check(n))
            std::cout << 1 << std::endl;
        else std::cout << 0 << std::endl;
    }
}
bool check(long long x) {
    long long t = 0;
    for(long long i = 1; i <= x/2; i++)
        if(x%i == 0)
            t = t + i;
    if(t ==  x)
        return true;
    else return false;
}
