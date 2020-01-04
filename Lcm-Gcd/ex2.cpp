#include <iostream>

long long gcd(long long a, long long b);
long long lcm(long long a, long long b);

int main() {
    long long n, a;
    long long x = 1;
    std::cin >> n;
    for(long long i = 0; i < n; i++) {
        std::cin >> a;
        for(long long j = 1; j <= a; j++)
            x = lcm(x, j);
        std::cout << x << std::endl;
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
long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}
