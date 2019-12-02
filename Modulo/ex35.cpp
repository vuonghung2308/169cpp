#include <iostream>
#include <fstream>
#include <vector>

#define P 1000000007
long long tinh(std::vector<int> a, int x);
long long mod(int a, int x, int m);

int main() {
    int t, x, n;
    std::vector<int> a;
    std::fstream input("ex35.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n >> x;
        a.assign(n, 0);
        for(int i = 0; i < n; i++)
            input >> a[i];
        std::cout << tinh(a, x) << std::endl;
    }
}
long long tinh(std::vector<int> a, int x) {
    long long res = 0;
    for(int i = 0; i < a.size(); i++) {
        res = res + mod(a[i], x, a.size()-i-1);
        res = (long long) res % P;
    }
    return res;
}
long long mod(int a, int x, int m) {
    long long res = a % P;
    for(int i = 1; i <= m; i++) {
        res = (long long) res * x;
        res = (long long) res % P;
    }
    return res;
}