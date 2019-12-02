#include <iostream>
#include <fstream>

int tinhx(int x, int y);

int main() {
    int t, x, y;
    std::fstream input("ex15.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> x >> y;
        std::cout << tinhx(x, y) << std::endl;
    }
}
int tinhx(int x, int y) {
    int d = 0, temp;
    for(int i = 2; i <= x; i++) {
        temp = i;
        while(temp%y == 0) {
            d = d + 1;
            temp = temp / y;
        }
    }
    return d;
}