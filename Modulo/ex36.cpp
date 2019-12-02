#include <iostream>
#include <fstream>

long long tinhmod(long long a, long long b, long long c);

int main() {
    int t; long long a, b, c;
    std::fstream input("ex36.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> a >> b >> c;
        std::cout << tinhmod(a, b, c) << std::endl;
    }
}
long long tinhmod(long long a, long long b, long long c) {
    long long res = 0, z = b % c;
    int d = -1;
    while(a) {
        long long t = ((a % 10) * z) % c;
        d++;
        a = a / 10;
        for(int i = 0; i < d; i++) {
            t = (t * 10) % c;
        }
        res = res + t;
        res = res % c;
    }
    return res;
}