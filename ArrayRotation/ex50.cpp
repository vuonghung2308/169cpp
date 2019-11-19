#include <iostream>
#include <fstream>
#include <vector>

long long find_min(std::vector<long long> a);

int main() {
    short t; int n;
    std::vector<long long>::iterator it;
    std::vector<long long> a;
    std::fstream input("ex50.in", std::ios::in);
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> n;
        for(int j = 0; j < n; j++) {
            long long t;
            input >> t;
            a.push_back(t);
        }
        std::cout << find_min(a) << std::endl;
        a.clear();
    }
}
long long find_min(std::vector<long long> a) {
    int r = a.size()-1, l = 0, t;
    while(r-l != 1) {
        t = (r + l) / 2;
        if(a[t] < a[r])
            r = t;
        else l = t;
    }
    return (a[r]<a[l])?a[r]:a[l];
}