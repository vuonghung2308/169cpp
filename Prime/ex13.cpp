#include <iostream>
#include <fstream>
#include <cmath>

bool sont(int x);
void ketqua(int x);

int main() {
    std::fstream input("ex13.in", std::ios::in);
    int n, x;
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> x;
        ketqua(x);
    }
}

bool sont(int x) {
    if(x < 2)
        return false;
    for(int i = 2; i <= sqrt(x); i++)
        if(x%i == 0)
            return false;
    return true;
}
void ketqua(int x) {
    int i, j = x, a = 0, b = 0;
    for(i = 2; i <= x; i++) {
        if(sont(i) && sont(x-i)) {
            a = i; b = x - i;
            break;
        }
    }
    if(a + b == x)
        std::cout << a << ' ' << b << std::endl;
    else
        std::cout << -1 << std::endl;
}