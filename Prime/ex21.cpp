#include <iostream>
#include <fstream>

bool sont(int x);
void lietke(int n);

int main() {
    std::fstream input("ex21.in", std::ios::in);
    int t, n;
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n;
        lietke(n); 
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
void lietke(int n) {
    for(int i = 2; i*i <= n; i++)
        if( sont(i) )
            std::cout << i*i << ' ';
    std::cout << std::endl;
}