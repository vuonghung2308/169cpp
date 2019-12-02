#include <iostream>
#include <fstream>
#include <cmath>

bool sont(int a);
void uocntmax(int a);

int main() {
    std::fstream input("ex9.in", std::ios::in);
    int n, a;
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> a;
        uocntmax(a);
    }
}

bool sont(int a) {
    if(a < 2)
        return false;
    for(int i = 2; i <= sqrt(a); i++)
        if(a % i == 0)
            return false;
    return true;
}
void uocntmax(int a) {
    int i = sqrt(a);
    if(sont(a))
        std::cout << a;
    else {
        while(i >= 1) {
            if(sont(i) == true && a % i == 0) {
                std::cout << i << ' ';
                break;
            }
            i--;
        }
    }
    std::cout << std::endl;
}