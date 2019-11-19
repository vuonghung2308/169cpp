#include <iostream>
#include <fstream>
#include <cmath>

void lietke(int a);

int main() {
    std::fstream input("ex8.in", std::ios::in);
    int n, a; // a phai la kieu long long
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> a;
        lietke(a);
    }
}
void lietke(int a) {
    for(int i = 2; i*i <= a; i++) {
        while(a%i == 0) {
            std::cout << i  << ' ';
            a = a / i;
        }
    }
    if(a != 1)
        std::cout << a;
    std::cout << std::endl;
}