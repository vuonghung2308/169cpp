#include <iostream>
#include <fstream>

long long find(int X, int Y, int Z, short N);
int gcd(int a, int b);
long long lcm(int a, int b);
long long pow(short x);

int main() {
    std::fstream input("ex7.in", std::ios::in);
    short n, N;
    int X, Y, Z;
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> X >> Y >> Z >> N;
        std::cout << find(X, Y, Z, N) << std::endl;
    }
}

long long find(int X, int Y, int Z, short N) {
    long long x = lcm(X, Y);
    long long n = pow(N-1);
    x = lcm(x, Z);
    if(x > pow(N) - 1)
        return -1;
    else {
        long long t = ( (n-1) / x) + 1;
        return t * x;
    }
}
int gcd(int a, int b) {
    while(b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
long long lcm(int a, int b) {
    return (long long) a*b /gcd(a, b);
}
long long pow(short x) {
    long long t = 1;
    for(int i = 0; i < x; i++)
        t = t * 10;
    return t;
}