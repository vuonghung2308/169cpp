#include <iostream>
#include <fstream>

int uocle(int n);

int main() {
    std::fstream input("ex20.in", std::ios::in);
    int t, n;
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n;
        std::cout << uocle(n) << std::endl; 
    }
}

int uocle(int n) {
    int d = 0;
    for(int i = 1; i <= n; i++)
        if( (i&1) && n%i == 0) {
            d++;
        }
    return d;
}