#include <iostream>
using namespace std;

int n, k;
int arr[15];

int main() {

	int cnt = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		cnt += k / arr[i]; //해당 돈으로 거슬러 줄 수 있는 동전 세기
		k %= arr[i];
	}
	cout << cnt << '\n';

	return 0;
}