#include <iostream>
#include <fstream>
#include <vector>

int xoay(std::vector<int> &a);
bool check(std::vector<int> a);

int main() {
    std::vector<int> a;
    short t; int na;
    std::fstream input("ex48.in", std::ios::in);
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> na;
        for(int i = 0; i < na; i++) {
            int x;
            input >> x;
            a.push_back(x);
        }
        std::cout << xoay(a) << std::endl;;
        a.clear();
    }
}
int xoay(std::vector<int> &a) {
    int d = 0;
    while(!check(a)) {
        int temp = a.front();
        a.push_back(temp);
        a.erase(a.begin());
        d++;
    }
    return d;
}
bool check(std::vector<int> a) {
    for(int i = 0; i < a.size()-1; i++)
        if(a[i] > a[i+1])
            return false;
    return true;
}