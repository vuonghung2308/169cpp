#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>

void lietke(short n);
void hienthi(short *a, short n);
void sinh(short *a, short n, bool &ok);

int main() {
    short t, n;
    std::fstream input("ex44.in", std::ios::in);
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> n;
        lietke(n);
    }
}
void lietke(short n) {
    short a[n] = {};
    bool ok = false;
    while(!ok) {
        hienthi(a, n);
        sinh(a, n, ok);
    }
    std::cout << std::endl;
}
void hienthi(short *a, short n) {
    for(int i = 0; i < n; i++)
        std::cout << a[i];
    std::cout << ' ';
}
void sinh(short *a, short n, bool &ok) {
    int i = n - 1;
    while(a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if(i >=0 ) 
        a[i] = 1;
    else ok = true;
}