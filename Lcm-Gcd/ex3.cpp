#include <iostream>
#include <fstream>
#define MAX 1000000007

long long tich(int *a, int na);
int gcd(int a, int b);
int gcda(int *a, int na);
long long pow(long long a, int x);

int main() {
    std::fstream input("ex3.in", std::ios::in);
    int n, a[100], na;
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> na;
        for(int j = 0; j < na; j++)
            input >> a[j];
        std::cout << pow(tich(a, na), gcda(a, na)) << std::endl;
    }

}

long long tich(int *a, int na) {
    long long t = 1;
    for(int i = 0; i < na; i++) {
        t = (long long) t * a[i];
        t = t % MAX;
    }
    return t;
}
int gcd(int a, int b) {
    while(b != 0) {
        int t = a % b;
        a = b; 
        b = t;
    }
    return a;
}
int gcda(int *a, int na) {
    int x = a[0];
    for(int i = 1; i < na; i++)
        x = gcd(x, a[i]);
    return x;
}
long long pow(long long a, int x) {
    long long p = 1;
    for(int i = 1; i <= x; i++) {
        p = p * a;
        p = p % MAX;
    }
    return p;
}