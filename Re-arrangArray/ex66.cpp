#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> tach(char *c);
void doicho(std::vector<int> a);

int main() {
    std::vector<int> a;
    short t;
    std::fstream input("ex66.in", std::ios::in);
    input >> t;
    for(short i = 1; i <= t; i++) {
        char *c;
        input >> c;
        a = tach(c);
        doicho(a);
        a.clear();
    }
}
std::vector<int> tach(char *c) {
    std::vector<int> x;
    int i = 0;
    while(c[i]!='\0') {
        x.push_back(c[i] - '0');
        i++;
    }
    return x;
}
void doicho(std::vector<int> a) {
    std::vector<int> x = a;
    bool check= false;
    for(int i = a.size()-1; i > 0; i--) {
        for(int j = i-1; j >= 0; j--) {
            if(a[i] < a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
                check = true;
                break;
            }
        }
        if(check == true)
            break;
    }
    if(check == true) {
        for(int i = 0; i < a.size(); i++)
            std::cout << a[i];
        std::cout << std::endl;
    }
    else std::cout << -1 << std::endl;
}