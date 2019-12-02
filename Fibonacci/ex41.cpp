#include <iostream>
#include <fstream>

#define MAX 10000000007

long long fibonacci(int n);

int main() {
    short t; int n;
    std::fstream input("ex41.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n;
        std::cout << fibonacci(n)%MAX << std::endl;
    }
}
long long fibonacci(int n) {
    long long an = 0, an1 = 1;
    if(n == 0)
        return an;
    if(n == 1)
        return an1;
    for(int i = 2; i <= n; i++) {
        long long t = an;
        an = an1;
        an1 = an1 + t; 
    }
    return an1;
}