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
    int na = r / a - l / a;
    int nb = r / b - l / b;
    int nab = r /bcnn(a, b) - l / bcnn(a, b);
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
