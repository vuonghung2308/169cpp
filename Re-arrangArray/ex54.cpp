#include <iostream>
#include <fstream>
#include <vector>

void sapxep(std::vector<int> &a);
void hienthi(std::vector<int> a);

int main() {
    short t; int n;
    std::vector<int> a;
    std::fstream input("ex54.in", std::ios::in);
    input >> t;
    for(short i = 1; i <= t; i++) {
        input >> n;
        for(int j = 0; j < n; j++) {
            int temp;
            input >> temp;
            a.push_back(temp);
        }
        sapxep(a);
        hienthi(a);
        a.clear();
    }
}
void sapxep(std::vector<int> &a) {
    for(int i = 0; i < a.size()-1; i++) {
        if((i+1)%2 == 0 && a[i] < a[i+1]) {
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
        if((i+1)%2 == 1 && a[i] > a[i+1]) {
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
}
void hienthi(std::vector<int> a) {
    for(int i = 0; i < a.size(); i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}