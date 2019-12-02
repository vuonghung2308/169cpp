#include <iostream>
#include <fstream>
#include <vector>

int sapxep(std::vector<int> a, int k);
int main() {
    short t; int n, k;
    std::fstream input("ex53.in", std::ios::in);
    std::vector<int> a;
    input >> t;
    for(short i = 1; i <= t; i++) {
        int it = 0;
        input >> n >> k;
        for(int j = 0; j < n; j++) {
            int temp;
            input >> temp;
            a.push_back(temp);
        }
        std::cout << sapxep(a, k) << std::endl;
        a.clear();
    }
}
int sapxep(std::vector<int> a, int k) {
    int i = 0, dem = 0;
    while(a[i] < k)
        i++;
    for(int j = i; j < a.size(); j++)
        if(a[j] <= k)
            dem++;
    return dem;
}