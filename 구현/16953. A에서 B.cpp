#include <iostream>
#include <string>
using namespace std;

int a, b;
string s;
bool flag = true;

int main() {

	int cnt = 0;
	cin >> a >> b;

	while (true) {
		if (a > b) {
			flag = false;
			break;
		}
		if (a == b) {
			break;
		}
		if (b % 2 == 0) {
			b /= 2;
		}
		else if (b % 10 == 1) {
			s = to_string(b);
			s.pop_back();
			b = stoi(s);
		}
		else {
			flag = false;
			break;
		}
		cnt++;
	}
	if (flag) cout << cnt + 1;
	else cout << -1;

	return 0;
}