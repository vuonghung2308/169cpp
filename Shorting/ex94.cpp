#include <iostream>
#include <fstream>

int max(int a[][2], int na);
int min(int a[][2], int na);
bool check(int a[][2], int na);
void hienthi(int a[][2], int na);

int main() {
    std::fstream input("ex94.in" , std::ios::in);
    int t;
    input >> t;
    for(int i = 1; i <= t; i++) {
        int a[1000][2] = {}, na;
        input >> na;
        for(int j = 0; j < na; j++) {
            input >> a[j][0];
            a[j][1] = 0;
        }
        while(!check(a, na)) {
            if(!check(a, na))
                std::cout << max(a, na) << ' ';
            if(!check(a, na))
                std::cout << min(a, na) << ' ';
        }
        std::cout << std::endl;

    }
}
int max(int a[][2], int na) {
    int i = 0, m;
    while(a[i][1] == 1 && i < na)
        i++;
    m = i;
    for(i = 0; i < na; i++) {
        if(a[m][0] < a[i][0] && a[i][1] == 0) {
            m = i;
        }
    }
    a[m][1] = 1;
    return a[m][0];
}
int min(int a[][2], int na) {
    int i = 0, m;
    while(a[i][1] == 1 && i < na)
        i++;
    m = i;
    for(i = 0; i < na; i++)
        if(a[m][0] > a[i][0] && a[i][1] == 0)
            m = i;
    a[m][1] = 1;
    return a[m][0];
}
bool check(int a[][2], int na) {
    for(int i = 0; i < na; i++)
        if(a[i][1] == 0)
            return false;
    return true;
}
void hienthi(int a[][2], int na) {
    for(int j = 0; j < na; j++)
        std::cout << a[j][0] << ' ';
}