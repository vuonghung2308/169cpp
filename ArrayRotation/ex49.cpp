#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

long long xoay(std::vector<long long> &a);
long long sum_vector(std::vector<long long> a);

int main() {
    std::vector<long long> a;
    short t; int na;
    std::fstream input("ex49.in", std::ios::in);
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> na;
        for(int i = 0; i < na; i++) {
            long long x;
            input >> x;
            a.push_back(x);
        }
        std::cout << xoay(a) << std::endl;;
        a.clear();
    }
}
long long xoay(std::vector<long long> &a) {
    std::vector<long long> x;
    for(int i = 1; i <= a.size(); i++) {
        long long temp = a.front();
        a.push_back(temp);
        a.erase(a.begin());
        x.push_back(sum_vector(a));
    }
    return (*std::max_element(x.begin(), x.end()));
}
long long sum_vector(std::vector<long long> a) {
    long long sum = 0;
    int i = 0;
    for(std::vector<long long>::iterator it = a.begin(); it != a.end(); it++) {
        sum = sum + *it*i;
        i++;
    }
    return sum;
}