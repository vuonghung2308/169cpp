#include <iostream>
#include <fstream>
#include <vector>

#define P 1000000007

std::vector<int> nCk(short n, short k);
long long mod(std::vector<int> a);

int main() {
    short t, n, k;
    std::vector<int> a;
    std::fstream input("ex34.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        input >> n >> k;
        a = nCk(n, k);
        std::cout << mod(a) << std::endl;
        a.clear();
    }
}
std::vector<int> nCk(short n, short k) {
    std::vector<int> a;
    for(int i = 0; i < k; i++)
        a.push_back(n-i);
    for(int i = 2; i <= k; i++) {
        bool check = false;
        for(int j = 0; j < a.size(); j++) {
            if(a[j]%i == 0) {
                a[j] = a[j]/i;
                check = true;
                break;
            }
        }
        if(check == false) {
            int x = i;
            while(x != 1) {
                for(int j = 2; j <= i; j++) {
                    while(x%j == 0) {
                        for(int z = 0; z < a.size(); z++) {
                            if(a[z]%j == 0) {
                                a[z] = a[z]/j;
                                break;
                            }
                        }
                        x = x / j;
                    }
                }
            }
        }
    }
    return a;
}
long long mod(std::vector<int> a) {
    long long t = 1; int i = 0;
    while(i < a.size()) {
        while(t < P && i < a.size()) {
            t = t * a[i];
            i++;
        }
        t = t % P;
    }
    return t;
}