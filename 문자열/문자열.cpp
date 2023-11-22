#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a, b;

//a문자열을 오른쪽으로 한칸씩 옮기면서 차이가 최소인 경우 구하기
//굳이 앞뒤에 문자를 넣어줄 필요가 없음

int main() {

	int cnt, ans = 100000000;
	cin >> a >> b;

	int sz = b.size() - a.size();

	cnt = 0;
	if (sz == 0) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) cnt++;
		}
		ans = cnt;
	}
	else if(sz > 0){
		for (int i = 0; i <= sz; i++) {
			cnt = 0;
			for (int j = 0; j < a.size(); j++) {
				if (a[j] != b[i + j]) cnt++;
			}
			if(ans > cnt) ans = cnt;
		}
	}
	cout << ans;

	return 0;
}