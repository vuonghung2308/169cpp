#include <iostream>
#include <fstream>

void lietke(short *a, short n);
bool check(long long n);
long long fibonacci(int n);

int main() {
    short n, t, a[100];
    std::fstream input("ex43.in", std::ios::in);
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> n;
        for(short j = 0; j < n; j++)
            input >> a[j];
        lietke(a, n);
    }
}
void lietke(short *a, short n) {
    for(int i = 0; i < n; i++)
        if(check(a[i]))
            std::cout << a[i] << ' ';
    std::cout << std::endl;
}
bool check(long long n) {
    int i = 0;
    while(fibonacci(i) <= n) {
        if(fibonacci(i) == n)
            return true;
        i++;
    }
    return false;
}
long long fibonacci(int n) {
    long long f0 = 0, f1 = 1;
    if(n == 0)
        return f0;
    if(n == 1)
        return f1;
    for(int i = 1; i <= n; i++) {
        long long t = f0;
        f0 = f1;
        f1 = f1 + t;
    }
    return f1;
}