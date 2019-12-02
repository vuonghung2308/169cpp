#include <fstream>
#include <iostream>
#include <vector>

void hienthi(std::vector<long long> a);
int main() {
    std::vector<long long> a;
    std::fstream input("ex52.in", std::ios::in);
    short t; int n;
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> n;
        int it = 0;
        for(int j = 0; j < n; j++) {
            long long temp;
            input >> temp;
            if(temp == 0)
                a.push_back(0);
            else {
                a.insert(a.begin()+it, temp);
                it++;
            }
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