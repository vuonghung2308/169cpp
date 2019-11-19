#include <iostream>
#include <cmath>

bool check(int x);

int main() {
    int n, x;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> x;
        if(check(x) == 1)
            std::cout << 1 << std::endl;
        else std::cout << 0 << std::endl;
    }
}
bool check(int x) {
    int a[100] = {}, na = 0, i = 2;
    while (i <= x) {
        while(x%i == 0) {
            a[na] = i;
            na++;
            x = x / i;
        }
        i++;
    }
    if(na == 3 && a[0] != a[1] && a[1] != a[2] && a[2] != a[0])
        return true;
    else return false;
}
