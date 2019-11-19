#include <iostream>
#include <fstream>

bool sont(int x);
bool tong(int x);
int tach(int x);

int main() {
    int t, x;
    std::fstream input("ex17.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> x;
        if(!sont(x) && tong(x))
            std::cout << "YES\n";
        else std::cout << "NO\n"; 
    }
}
bool sont(int x) {
    if(x < 2)
        return false;
    for(int i = 2; i*i <= x; i++)
        if(x%i == 0)
            return false;
    return true;
}
bool tong(int x) {
    int a[100], na = 0;
    int t = 0, y = x;
    while(x != 1) {
        for(int i = 2; i <= x; i++) {
            while(sont(i) && x%i == 0) {
                a[na] = i;
                x = x / i;
                na++;
            }
        }
    }
    for(int i = 0; i < na; i++)
        t = t + tach(a[i]);
    if(t ==  tach(y))
        return true;
    else return false;
}
int tach(int x) {
    int t = 0;
    while(x) {
        t = t + x%10;
        x = x /10;
    }
    return t;
}