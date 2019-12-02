#include <iostream>
#include <fstream>

void lietke(short n);
void hienthi(short *a, short n);
void sinh(short *a, short n, bool &ok);
int main() {
    short t, n;
    std::fstream input("ex46.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n;
        lietke(n);
    }
}
void lietke(short n) {
    short a[n]; bool ok = false;
    for(int i = 1; i <= n; i++)
        a[i] = i;
    while(!ok) {
        hienthi(a, n);
        sinh(a, n, ok);
    }
    std::cout << std::endl;
}
void hienthi(short *a, short n) {
    for(short i = 1; i <= n; i++)
        std::cout << a[i];
    std::cout << ' ';
}
void sinh(short *a, short n, bool &ok) {
    short i = n-1;
    while(a[i] > a[i+1])
        i--;
    if(i > 0) {
        short x = n;
        while(a[x] < a[i]) 
            x--;
        short t = a[x]; a[x] = a[i]; a[i] = t;
        short r = n, l = i + 1;
        while(l < r) {
            t = a[r]; a[r] = a[l]; a[l] = t;
            l++; r--;
        }
    }
    else ok = true;
}