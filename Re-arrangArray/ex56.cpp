#include <iostream>
#include <fstream>
#include <vector>

void sapxep(std::vector<int> &a);
void hienthi(std::vector<int> a);

int main() {
    short t; int n;
    std::vector<int> a;
    std::fstream input("ex56.in", std::ios::in);
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
    std::vector<int> x;
    int j = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == 0)
            x.push_back(0);
        else if(a[i] == a[i+1]) {
            a[i+1] = 0;
            x.insert(x.begin()+j, a[i]*2);
            j++;
        }
        else {
            x.insert(x.begin()+j, a[i]);
            j++;
        }
    }
    a.clear();
    a = x;
}
void hienthi(std::vector<int> a) {
    for(int i = 0; i < a.size(); i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}