#include <iostream>
#include <vector>
using namespace std;

void xoay(std::vector<int> &a, int n);
void hienthi(std::vector<int> a);

int main() {
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
    	std::vector<int> a;
		int n, na;
        cin >> na >> n;
        for(int i = 0; i < na; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        xoay(a, n);
        hienthi(a);
    }
}
void xoay(std::vector<int> &a, int n) {
    for(int i = 1; i <= n; i++) {
        int temp = a.front();
        a.push_back(temp);
        a.erase(a.begin());
    }
}
void hienthi(std::vector<int> a) {
    for(std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
}
