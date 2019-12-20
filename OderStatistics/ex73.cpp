#include <iostream>
using namespace std;

int tim(int *a, int n);

int main() {
	int n, *a; cin >> n;
	a = new int [n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << tim(a, n);	
}
int tim(int *a, int n) {
	int *LMin = new int[n];
	int *RMax = new int[n];
	LMin[0] = a[0]; RMax[n-1] = a[n-1];
	for(int i = 1; i < n; i++)
		LMin[i] = (a[i] < LMin[i-1])?a[i]:LMin[i-1];
	for(int i = n-2; i >= 0; i--)
		RMax[i] = (a[i] > RMax[i+1])?a[i]:RMax[i+1];
	int i = 0, j = 0;
	int res = -1;
	while(i < n && j < n) {
		if(LMin[i] < RMax[j]) {
			res = (res < j-i)?j-i:res;
			j++;
		}
		else i++;
	}
	return res;
}
