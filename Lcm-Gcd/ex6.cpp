#include <iostream>
#include <fstream>

long long gcd(long long a, long long b);
bool check(long long n, long long m);

int main() {
    int n;
    long long a, b;
    std::fstream input("ex6.in", std::ios::in);
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> a >> b;
        if(check(a, b))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

}

long long gcd(long long a, long long b) {
    while(b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}
bool check(long long n, long long m) {
    long long s = (n * n + n) / (2);
    long long s1 = s + m, s2;
    if( s1 % 2 != 0 || m >= s)
        return false;
    s1 = s1 / 2;
    s2 = s1 - m;
    if(gcd(s1, s2) == 1)
        return true;
    return false;
}