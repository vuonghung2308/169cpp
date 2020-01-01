#include <iostream>
using namespace std;
#include <cmath>

bool sont(int x);
int sontmin(int x);
void lietke(int x);

int main() {
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        lietke(x);
    }
}

int sontmin(int x) {
    if(x == 1)
        return 1;
    for(int i = 2; i <= sqrt(x); i++)
        if(x%i == 0)
            return i;
    return x;
}
void lietke(int x) {
    for(int i = 1; i <= x; i++)
        std::cout << sontmin(i) << ' ';
    std::cout << std::endl;
}
