#include <iostream>
#include <fstream>

long long tinh(int n, long long k);

int main() {
    int t, n;
    long long k;
    std::fstream input("ex28.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n >> k;
        std::cout << tinh(n, k) << std::endl;
    }
}
long long tinh(int n, long long k) {
    int x = n / k;
    long long y = n % k;
    k = k - 1;
    long long res = (long long) (k*k*x + k*x)/2 + (y*y + y)/2;
    return res;
}