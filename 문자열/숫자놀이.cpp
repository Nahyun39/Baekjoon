#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int m, n;
string s;
string words[15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<pair<string, int>> ans;

int main() {

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (i >= 10) {
			s = words[i / 10] + ' ' + words[i % 10];
			ans.push_back({ s, i });
		}
		else {
			s = words[i % 10];
			ans.push_back({ s, i });
		}
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i <ans.size(); i++) {
		cout << ans[i].second << " ";
		if (i % 10 == 9) cout << '\n'; //10개씩 출력 
	}
	return 0;
}