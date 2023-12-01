#include <iostream>
using namespace std;

int n, arr[110];

int main() {

	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 1; i--) {
		while (arr[i-1] >= arr[i]) {
			arr[i-1]--;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}