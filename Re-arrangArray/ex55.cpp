#include <iostream>
#include <algorithm>
#include <vector>

void sapxep(std::vector<int> a);

int main() {
    short t; int n;
    std::vector<int> a;
    std::cin >> t;
    for(short i = 1; i <= t; i++) {
        std::cin >> n;
        for(int j = 0; j < n; j++) {
            int temp;
            std::cin >> temp;
            a.push_back(temp);
        }
        sapxep(a);
        a.clear();
    }
}
void sapxep(std::vector<int> a) {
    sort(a.begin(), a.begin()+a.size());
    while(!a.empty()) {
            std::cout << a.back() << ' ';
            a.erase(a.end()-1);
            std::cout << a.front() << ' ';
            a.erase(a.begin());
    }
    std::cout << std::endl;
}
