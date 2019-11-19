#include <iostream>
#include <fstream>

long long mod(char *n, long long m);

int main() {
    int t; char n[1001] = {}; long long m;
    std::fstream input("ex30.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n >> m;
        std::cout << mod(n, m) << std::endl;
    }
}
long long mod(char *n, long long m) {
    int a[1000];
    int na = 0, i = 0; long long res = 0;
    while(n[i] == '0')
        i++;
    while(n[i] != '\0') {
        a[na] = n[i] - '0';
        na++; i++;
    }
    i = 0;
    while(i < na) {
        while(res < m && i < na) {
            res = res * 10 + a[i];
            i++;
        }
        res = res % m;
    }
    return res;
}