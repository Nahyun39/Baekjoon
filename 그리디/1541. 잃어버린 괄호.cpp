#include <iostream>
#include <string>
using namespace std;

//식을 최소로 만들기 위해서는 '-'의 문자들을 모두 '-'로 바꿔주기

string s;

int main() {

	int min = 0;
	string str = "";
	bool flag = false;
	cin >> s;

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' or s[i] == '-' or i == s.size()) {
			if (flag) {
				min -= stoi(str);
				str = "";
			}
			else if (flag == false) {
				min += stoi(str);
				str = "";
			}
		}
		else {
			str += s[i];
		}
		
		if (s[i] == '-') {
			flag = true;
		}
	}
	cout << min;

	return 0;
}