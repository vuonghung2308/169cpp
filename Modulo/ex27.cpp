#include <iostream>
#include <fstream>

int tinh(int a, int m);

int main() {
    int t, a, m;
    std::fstream input("ex27.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> a >> m;
        std::cout << tinh(a, m) << std::endl;
    }
}
int tinh(int a, int m) {
    for(int i = 1; i <= m-1;i ++)
        if(i*a%m == 1)
            return i;
    return -1;
}