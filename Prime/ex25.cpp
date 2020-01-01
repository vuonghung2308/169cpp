#include <iostream>
#include <cmath>
using namespace std;

int dem(int l, int r, int a, int b);
int ucln(int a, int b);
int bcnn(int a, int b);

int main() {
    int t, x, y, a, b;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> x >> y >> a >> b;
        std::cout << dem(x, y, a, b) << std::endl; 
    }
}

int dem(int l, int r, int a, int b) {
    int na = r / a;
    int na_ = (l-1) / a;
    na = na - na_;
    int nb = r / b;
    int nb_ = (l-1) / b;
    nb = nb - nb_;
    int nab = r /bcnn(a, b);
    int nab_ = (l-1) / bcnn(a, b);
    return na + nb - nab;
}
int ucln(int a, int b) {
    while(b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int bcnn(int a, int b) {
    return a*b / ucln(a, b);
}
