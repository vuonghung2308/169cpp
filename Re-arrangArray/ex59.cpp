#include <iostream>
#include <fstream>
#include <vector>

void sapxep(std::vector<int> &a);
void hienthi(std::vector<int> a);

int main() {
    short t; int n;
    std::vector<int> a;
    std::fstream input("ex59.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n;
        a.assign(n, 0);
        for(int j = 0; j < n; j++) {
            int temp;
            input >> temp;
            a.at(j) = temp;
        }
        sapxep(a);
        hienthi(a);
        a.clear();
    }
}
void sapxep(std::vector<int> &a) {
    std::vector<int> x(a.size(), 0);
    for(int i = 0; i < a.size(); i++) {
        if(i == 0) 
            x[i] = a[i] * a[i+1];
        else if(i != a.size()-1)
            x[i] = a[i-1] * a[i+1];
        else
            x[i] = a[i-1] * a[i];

    }
    a.clear();
    a = x;
}
void hienthi(std::vector<int> a) {
    for(int i = 0; i < a.size(); i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}