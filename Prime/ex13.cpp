#include <iostream>
#include <cmath>

bool sont(int x);
void ketqua(int x);

int main() {
    int n, x;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> x;
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
    for(i = 2; i+i <= x; i++) {
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
