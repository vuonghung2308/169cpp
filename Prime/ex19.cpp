#include <iostream>

int uocntk(int n, int k);

int main() {
    int t, n, k;
    std::cin >> t;
    for(int i = 1; i <= t; i++) {
        std::cin >> n >> k;
        std::cout << uocntk(n, k) << std::endl; 
    }
}

int uocntk(int n, int k) {
    int d = 0;
    for(int i = 2; i <= n; i++) {
        while(n%i == 0) {
            d++;
            if(d == k)
                return i;
            n = n / i;
        }
    }
    return -1;
}
