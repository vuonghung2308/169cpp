#include <iostream>
#include <fstream>
#include <cmath>

bool sont(int a);
void lietke(int a);

int main() {
    std::fstream input("ex10.in", std::ios::in);
    int n, a;
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> a;
        lietke(a);
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
void lietke(int a) {
    for(int i = 0; i <= a; i++)
        if(sont(i))
            std::cout << i << ' ';
    std::cout << std::endl;
}