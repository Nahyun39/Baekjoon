#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100010];

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<int>());

	int max = -1;
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] * (i + 1);
		if (max < arr[i]) max = arr[i];
	}
	cout << max;

	return 0;
}