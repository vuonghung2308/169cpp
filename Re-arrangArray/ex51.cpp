#include <iostream>
#include <vector>
#include <fstream>

void hienthi(std::vector<long long> a);

int main() {
    short t; int n;
    std::fstream input("ex51.in", std::ios::in);
    std::vector<long long> a;
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> n;
        a.assign(n, -1);
        for(int j = 0; j < n; j++) {
            long long temp;
            input >> temp;
            if(temp < n && temp >= 0)
                a.at(temp) = temp;
        }
        hienthi(a);
        a.clear();
    }
}
void hienthi(std::vector<long long> a) {
    for(int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
}