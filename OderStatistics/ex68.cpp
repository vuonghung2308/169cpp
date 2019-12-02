#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int mink(std::vector<int> a, int k);

int main() {
    std::fstream input("ex68.in", std::ios::in);
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
        std::cout << mink(a, k) << std::endl;
    }
}
int mink(std::vector<int> a, int k) {
    while(k > 1) {
        a.erase(std::min_element(a.begin(), a.end()));
        k--;
    }
    return *(std::min_element(a.begin(), a.end()));
}