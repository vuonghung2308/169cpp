#include <iostream>
#include <fstream>

bool check(long long n);
long long fibonacci(int n);

int main() {
    short t; long long n;
    std::fstream input("ex42.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n;
        if(check(n)) 
            std::cout << "YES" << std::endl;
        else std::cout << "NO " << std::endl;
    }
}
bool check(long long n) {
    int i = 0;
    while(fibonacci(i) <= n) {
        if(fibonacci(i) == n)
            return true;
        i++;
    }
    return false;
}
long long fibonacci(int n) {
    long long f0 = 0, f1 = 1;
    if(n == 0)
        return f0;
    if(n == 1)
        return f1;
    for(int i = 1; i <= n; i++) {
        long long t = f0;
        f0 = f1;
        f1 = f1 + t;
    }
    return f1;
}