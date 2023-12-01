#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[110], brr[110];

int main() {

	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	sort(brr, brr + n);

	for (int i = 0; i < n; i++) {
		cnt += arr[i] * brr[i];
	}

	cout << cnt;

	return 0;
}