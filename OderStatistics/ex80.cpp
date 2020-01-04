#include <iostream>
using namespace std;

int findMax(int *arr1, int *arr2, int n, int m) {
	int sum1 = 0, sum2 = 0, result = 0;
	int i = 0, j = 0;
	while(i < n && j < m) {
		if(arr1[i] < arr2[j])
			sum1 += arr1[i++];
		else if(arr2[j] < arr1[i])
			sum2 += arr2[j++];
		else {
			result = (sum1 > sum2)? sum1: sum2;
			while(arr1[i] == arr2[j]) {
				result+= arr1[i++];
				j++;
			}
			sum1 = 0, sum2 = 0;
		}
	}
	while(i < n)
		sum1 +=arr1[i++];
	while(j < m)
		sum2 += arr2[j++];
	result += (sum1 > sum2)? sum1: sum2;
	return result;
}

int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int n, m, *arr1, *arr2;
		cin >> n >> m;
		arr1 = new int[n];
		arr2 = new int[m];
		for(int i = 0; i < n; i++)
			cin >> arr1[i];
		for(int i = 0; i < m; i++)
			cin >> arr2[i];
		cout << findMax(arr1, arr2, n, m) << endl;
	}
}
