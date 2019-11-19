#include <iostream>
#include <cmath>
#include <fstream>

bool sont(int x);
int dem(int l, int r);

int main() {
    std::fstream input("ex24.in", std::ios::in);
    int t;
    long long x, y;
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> x >> y;
        int l = sqrt(x), r = sqrt(y);
        std::cout << dem(l, r) << std::endl; 
    }
}

bool sont(int x) {
    if(x < 2)
        return false;
    for(int i = 2; i*i <= x; i++)
        if(x%i == 0)
            return false;
    return true;
}
int dem(int l, int r) {
    int d = 0;
    for(int i = l ; i <= r; i++)
        if( sont(i) )
            d++;
    return d;
}