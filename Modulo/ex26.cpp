#include <iostream>
#include <fstream>

long long pow(int a, int b, int c);

int main() {
    int t, a, b, c;
    std::fstream input("ex26.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> a >> b >> c;
        std::cout << pow(a, b, c) << std::endl;
    }
}
long long pow(int a, int b, int c) {
    long long t = 1;
    for(int i = 1; i <= b; i++) {
        t = t * a;
        t = t % c;
    }
    return t;
}