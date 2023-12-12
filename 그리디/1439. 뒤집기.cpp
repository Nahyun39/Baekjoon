#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {

	int zero=0, one=0;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[i + 1]) {
			if (s[i] == '0') zero++;
			else if (s[i] == '1') one++;
		}
	}
	cout << min(zero, one);
    
	return 0;
}