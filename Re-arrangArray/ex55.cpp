#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

void sapxep(std::vector<int> a);

int main() {
    short t; int n;
    std::vector<int> a;
    std::fstream input("ex55.in", std::ios::in);
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> n;
        for(int j = 0; j < n; j++) {
            int temp;
            input >> temp;
            a.push_back(temp);
        }
        sapxep(a);
        a.clear();
    }
}
void sapxep(std::vector<int> a) {
    std::vector<int> x;
    while(!a.empty()) {
            std::cout << *std::max_element(a.begin(), a.end()) << ' ';
            a.erase(std::max_element(a.begin(), a.end()));
            std::cout << *std::min_element(a.begin(), a.end()) << ' ';
            a.erase(std::min_element(a.begin(), a.end()));
    }
    std::cout << std::endl;
}