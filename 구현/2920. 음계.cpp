#include <iostream>
#include <string>
using namespace std;

int arr[15];
bool flag1 = true, flag2 = true;

int main() {

	string s;

	for (int i = 1; i <= 8; i++) {
		cin >> arr[i];
	}

	if (arr[1] == 1) {
		for (int i = 2; i <= 8; i++) {
			if (arr[i] != i) {
				flag1 = false;
			}
		}
		if (flag1) s = "ascending";
		else s = "mixed";
	}
	else if (arr[1] == 8) {
		for (int i = 2; i <= 8; i++) {
			if (arr[i] != 9 - i) {
				flag2 = false;
			}
		}
		if (flag2) s = "descending";
		else s = "mixed";
	}
	else {
		s = "mixed";
		cout << s;
		return 0;
	}

	cout << s;

	return 0;
}