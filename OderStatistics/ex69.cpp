#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::fstream input("ex69.in", std::ios::in);
    int t;
    input >> t;
    for(int i = 1; i <= t; i++) {
        std::vector<int> a;
        int temp, k, n;
        input >> n >> k;
        for(int j = 0; j < n; j++) {
            input >> temp;
            a.push_back(temp);
        }
        std::cout << *std::max_element(a.begin(), a.end()) << std::endl;
    }
}