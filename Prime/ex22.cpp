#include <iostream>
#include <fstream>
#include <cmath>

bool sont(int x);
int sontmin(int x);
void lietke(int x);

int main() {
    std::fstream input("ex22.in", std::ios::in);
    int n, x;
    input >> n;
    for(int i = 0; i < n; i++) {
        input >> x;
        lietke(x);
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
int sontmin(int x) {
    if(x == 1)
        return 1;
    if(x%2 == 0)
        return 2;
    if(sont(x) == true)
        return x;
    for(int i = 3; i <= sqrt(x); i++) {
        if(x%i == 0) {
            return i;
            break;
        }
    }
    return -1;
}
void lietke(int x) {
    for(int i = 1; i <= x; i++)
        std::cout << sontmin(i) << ' ';
    std::cout << std::endl;
}