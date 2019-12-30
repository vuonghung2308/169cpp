#include <iostream>
#include <cmath>
using namespace std;
bool sont(int x);
int dem(int n);

int main() {
    int t;
    long long n;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n;
        int x = sqrt(n);
        std::cout << dem(x) << std::endl;
    }
}

bool sont(int x) {
    if(x < 2)
        return false;
    for(long long i = 2; i*i <= x; i++)
        if(x%i == 0)
            return false;
    return true;
}
int dem(int n) {
    int d = 0;
    for(int i = 1; i <= n; i++)
        if(sont(i))
            d++;
    return d;
}
