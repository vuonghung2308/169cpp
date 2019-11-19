#include <iostream>
#include <fstream>
#define MAX 1000

int dem(int n, int *a);
int max(int n, int *a);

int main() {
    short t;
    int n, a[MAX];
    std::fstream input("ex32.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n;
        for(int j = 0; j < n; j++)
            input >> a[j];
        std::cout << dem(n, a) << std::endl;
    }
}
int dem(int n, int *a) {
    int d = 0;
    bool check = false;
    for(int i = 1; i <= max(n, a); i++) {
        int t = a[0] % i;
        for(int j = 1; j < n; j++) {
            if(a[j]%i == t)
                check = true;
            else {
                check = false;
                break;
            }
        }
        if(check) {
            d++;
            check = false;
        }
            
    }
    return d;
}
int max(int n, int *a) {
    int m = a[0];
    for(int i = 1; i < n; i++) {
        if(m < a[i])
            m = a[i];
    }
    return m;
}