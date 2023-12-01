#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1010];

int main() {

	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n); 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cnt += arr[j];
		}
	}
	cout << cnt;

	return 0;
}