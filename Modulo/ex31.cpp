#include <iostream>
#include <fstream>
#include <vector>

void docfile(std::vector<int> &a, long long &b, long long &M, std::fstream &input);
long long tinh(std::vector<int> a, long long b, long long M);
long long mod(std::vector<int> a, long long M);
long long abmodM(long long a, long long b, long long M);

int main() {
    short t; long long b, M;
    std::vector<int> a;
    std::fstream input("ex31.in", std::ios::in);
    input >> t;
    for(int i = 1; i <= t; i++) {
        docfile(a, b, M, input);
        std::cout << tinh(a, b, M) << std::endl;
        a.clear();
    }
}
void docfile(std::vector<int> &a, long long &b, long long &M, std::fstream &input) {
    char c[1001] = {}; int i = 0;
    input >> c;
    while(c[i] != '\0') {
        a.insert(a.begin()+i, c[i] - '0');
        i++;
    }
    input >> b >> M;
}
long long tinh(std::vector<int> a, long long b, long long M) {
    long long A = mod(a, M);
    return abmodM(A, b, M);
}
long long mod(std::vector<int> a, long long M) {
    long long t = 0; int i = 0;
    while(i < a.size()) {
        while(t < M && i < a.size()) {
            t = t * 10 + a[i];
            i++;
        }
        t = t % M;
    }
    return t;
}
long long abmodM(long long a, long long b, long long M) {
    long long res = a;
    for(long long j = 1; j < b; j++) {
        long long z = res; int d = -1;
        res = 0;
        while(z) {
            long long t = ((z % 10) * a) % M;
            z = z / 10;
            d++;
            for(int i = 0; i < d; i++)
                t = (t * 10) % M;
            res = res + t;
            res = res % M;
        }
    }
    return res;
}