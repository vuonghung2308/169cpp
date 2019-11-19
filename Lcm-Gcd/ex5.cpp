//thuc hien phep chia lay du abc-abc cho abc-abc-abc-abc-abc
#include <iostream>
#include <fstream>

long long gcd(long long a, long long b);

int main() {
    std::fstream input("ex5.in", std::ios::in);
    int n;
    long long x, y;
    char a[18] = {};
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> a >> x >> y;
        for(long long j = 0; j < gcd(x, y); j++)
            std::cout << a;
        std::cout << std::endl;
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