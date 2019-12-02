#include <iostream>
#include <fstream>
#include <vector>

void xoay(std::vector<int> &a, int n);
void hienthi(std::vector<int> a);

int main() {
    std::vector<int> a;
    short t; int n, na;
    std::fstream input("ex47.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> na >> n;
        for(int i = 0; i < na; i++) {
            int x;
            input >> x;
            a.push_back(x);
        }
        xoay(a, n);
        hienthi(a);
        a.clear();
    }
}
void xoay(std::vector<int> &a, int n) {
    for(int i = 1; i <= n; i++) {
        int temp = a.front();
        a.push_back(temp);
        a.erase(a.begin());
    }
}
void hienthi(std::vector<int> a) {
    for(std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
}