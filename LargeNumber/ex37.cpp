#include <iostream>
#include <fstream>
#include <vector>

bool sosanh(std::vector<int> a, std::vector<int> b);
std::vector<int> chuyendoi(char *c);
void hieu(std::vector<int> a, std::vector<int> b);
void hienthi(std::vector<int> a);

int main(){
    int t; char c1[1000] = {}, c2[1000] = {};
    std::vector<int> a, b;
    std::fstream input("ex37.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> c1 >> c2;
        a = chuyendoi(c1);
        b = chuyendoi(c2);
        hieu(a, b);
        a.clear();
        b.clear();
    }
}
bool sosanh(std::vector<int> a, std::vector<int> b) {
    if(a.size() > b.size())
        return true;
    if(a.size() < b.size())
        return false;
    int i = 0;
    while(a[i] == b[i] && i < a.size()) 
        i++;
    if(a[i] > b[i])
        return true;
    else return false;
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
void hieu(std::vector<int> a, std::vector<int> b) {
    if(sosanh(b, a))
        hieu(b, a);
    else {
        std::vector<int> res;
        res.assign(a.size(), 0);
        int t = 0;
        for(int i = 0; i < a.size(); i++) {
            if((int) b.size()-1-i >= 0)
                t = t + b[b.size()-1-i];
            else
                t = t + 0;
            if(a[a.size()-1-i] - t >= 0) {
                res[res.size()-1-i] = a[a.size()-1-i] - t;
                t = 0;
            }
            else {
                res[a.size()-1-i] = a[a.size()-1-i] - t + 10;
                t = 1;
            }
        }
        hienthi(res);
    }
}
void hienthi(std::vector<int> a) {
    for(std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cout << *it;
    std::cout << std::endl;
}