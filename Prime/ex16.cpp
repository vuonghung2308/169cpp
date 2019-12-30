#include <iostream>
using namespace std;

void lietke(int x);

int main() {
    int t, x;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> x;
        lietke(x);
    } 
}
void lietke(int x) {
    int i = 2;
    while(i*i <= x) {
        int d = 0;
        while(x%i == 0) {
            d++; x = x / i;
        }
        if(d != 0)
            std::cout << i << ' ' << d << ' ';
        i++;
    }
    if(x != 1)
       std::cout << x << ' ' << 1;
    std::cout << std::endl;
}
