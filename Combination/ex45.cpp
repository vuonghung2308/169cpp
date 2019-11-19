#include <iostream>
#include <fstream>

void lietke(short n, short k);
void hienthi(short *a, short k);
void sinh(short *a, short k, short n, bool &ok);
int main() {
    short t, n, k;
    std::fstream input("ex45.in", std::ios::in);
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> n >> k;
        lietke(n, k);
    }
}
void lietke(short n, short k) {
    short a[n]; bool ok = false;
    for(short i = 1; i <= n; i++)
        a[i] = i;
    while(!ok) {
        hienthi(a, k);
        sinh(a, k, n, ok);
    }
    std::cout << std::endl;
}
void hienthi(short *a, short k) {
    for(short i = 1; i <= k; i++)
        std::cout << a[i];
    std::cout << ' ';
}
void sinh(short *a, short k, short n, bool &ok) {
    short i = k;
    while(a[i] == n-k+i)
        i--;
    if(i > 0) {
        a[i] = a[i] + 1;
        for(short j = i+1; j <= k; j++)
            a[j] = a[i] + j - i;
    }
    else ok = true;
}