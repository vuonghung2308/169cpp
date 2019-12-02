#include <iostream>
#include <fstream>
#include <vector>

void hienthi(std::vector<int> a);
std::vector<int> tich(std::vector<int> a, std::vector<int> b);
std::vector<int> chuyendoi(char *c);


int main() {
    std::vector<int> a, b;
    char c1[1000] ={}, c2[1000] = {};
    int t;
    std::fstream input("ex39.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> c1 >> c2;
        a = chuyendoi(c1);
        b = chuyendoi(c2);
        hienthi(tich(a, b));
        a.clear();
        b.clear();
    }

}
void hienthi(std::vector<int> a) {
    for(int i = 0; i < a.size(); i++)
        std::cout << a[i];
    std::cout << std::endl;
}
std::vector<int> tich(std::vector<int> a, std::vector<int> b) {
    if(a.size() < b.size())
        return tich(b, a);


    std::vector<int> res(a.size(), 0);
    int na = (int) a.size() - 1, nb = (int) b.size() - 1;
    for(int i = nb; i >= 0 ; i--) {
        int nres = (int) res.size() - 1;
        int t = 0;
        for(int j = na; j >= 0; j--) {
            t = t + b[i] * a[j];
            if(nres-nb+i-na+j >= 0) {
                t = t + res[nres-nb+i-na+j];
                res[nres-nb+i-na+j] = t % 10;
                t = t / 10;
            }
            else {
                res.insert(res.begin(), t % 10);
                t = t / 10;
            }
        }
        if(t != 0)
            res.insert(res.begin(), t);
    }


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