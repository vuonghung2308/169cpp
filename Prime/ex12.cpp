#include <iostream>
#include <fstream>
#include <cmath>

bool sont(int x);
void lietke(int x, int y);

int main() {
    std::fstream input("ex12.in", std::ios::in);
    int n, x, y;
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> x >> y;
        lietke(x, y);
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
void lietke(int x, int y) {
    for(int i = x; i <= y; i++)
        if(sont(i))
            std::cout << i << ' ';
    std::cout << std::endl;
}