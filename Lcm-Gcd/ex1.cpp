#include <iostream>

int gcd(int a, int b);
long long lcm(int a, int b);

int main() {
    int n, a, b;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> a >> b;
        std::cout << lcm(a, b) << ' ' << gcd(a, b) << std::endl;
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
    return (long long) a*b / gcd(a, b);
}
