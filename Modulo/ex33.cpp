#include <iostream>
#include <fstream>

int dem(int b, int p);

int main() {
    short t;
    int p, b;
    std::fstream input("ex33.in", std::ios::in);
    input >> t; 
    for(int i = 1; i <= t; i++) {
        input >> b >> p;
        std::cout << dem(b, p) << std::endl;
    }
}
int dem(int b, int p) {
    int d = 0, i = 0;
    while(i*p + 1 <= b) {
        d++; i++;
    }
    i = 1;
    while(i*p - 1 <= b) {
        d++; i++;
    }
    return d;
}