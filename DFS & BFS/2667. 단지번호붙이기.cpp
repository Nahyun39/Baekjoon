#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1인 곳이 집, 단지수와 단지에 속하는 집의 수

int n, cnt, sz;
string s[30];
int visited[30][30];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int> ans;

void dfs(int x, int y) {
	visited[x][y] = true;
	sz++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny] or s[nx][ny] == '0') continue;

		dfs(nx, ny);
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '0' or visited[i][j]) continue;

			sz = 0;
			dfs(i, j);
			cnt++;
			ans.push_back(sz);
		}
	}

	cout << cnt << '\n';

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}