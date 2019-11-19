#include <iostream>
#include <fstream>

void docfile(std::fstream &input, long long &a, short *b, short &nb);
long long mod(long long a, short *b, short nb);
long long gcd(long long a, long long b);

int main() {
    std::fstream input("ex4.in", std::ios::in);
    long long a, x;
    short b[250] = {}, nb;
    docfile(input, a, b, nb);
    x = mod(a, b, nb);
    std::cout << gcd(x, a);
}

void docfile(std::fstream &input, long long &a, short *b, short &nb) {
    char c[251] = {};
    int i = 0;
    nb = 0;
    input >> a >> c;
    while(c[i] == '0')
        i++;
    while(c[i] != '\0') {
        b[nb] = c[i] - '0';
        nb++; i++;
    }
}
long long mod(long long a, short *b, short nb) {
    long long t = 0;
    short i = 0;
    while(i < nb) {
        while(t < a && i < nb) {
            t = t * 10 + b[i];
            i++;
        }
        t = t % a;
    }
    return t;
}
long long gcd(long long a, long long b) {
    while(b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}
