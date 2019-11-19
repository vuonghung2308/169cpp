#include <iostream>
#include <fstream>
#include <vector>

void hienthi(std::vector<int> a);
std::vector<int> tong(std::vector<int> a, std::vector<int> b);
std::vector<int> chuyendoi(char *c);


int main() {
    std::vector<int> a, b;
    char c1[1000] ={}, c2[1000] = {};
    int t;
    std::fstream input("ex38.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> c1 >> c2;
        a = chuyendoi(c1);
        b = chuyendoi(c2);
        hienthi(tong(a, b));
        a.clear();
        b.clear();
    }

}
void hienthi(std::vector<int> a) {
    for(int i = 0; i < a.size(); i++)
        std::cout << a[i];
    std::cout << std::endl;
}
std::vector<int> tong(std::vector<int> a, std::vector<int> b) {
    if(a.size() < b.size())
        return tong(b, a);
    std::vector<int> res;
    int i = 0, t = 0;
    while((int) a.size()-1-i >= 0) {
        if((int) b.size()-1-i >= 0)
            t = t + b[b.size()-1-i];
        if(a[a.size()-1-i] + t < 10) {
            res.insert(res.begin(), a[a.size()-1-i] + t);
            t = 0;
        }
        else {
            res.insert(res.begin(), a[a.size()-1-i] + t - 10);
            t = 1;
        }
        i++;
    }
    if(t != 0)
        res.insert(res.begin(), t);
    return res;
}
std::vector<int> chuyendoi(char *c) {
    int i = 0;
    std::vector<int> a;
    while(c[i] != '\0') {
        a.push_back(c[i] - '0');
        i++;
    }
    return a;
}