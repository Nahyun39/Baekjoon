#include <iostream>
using namespace std;

int n;
char arr[110][110];
int visited[110][110];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

//적록색약은 R과 G의 차이를 같은 것으로 봄 

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny] or arr[nx][ny] != arr[x][y]) continue;

		dfs(nx, ny);
	}
}

int main() {

	int cnt1 = 0, cnt2 = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	//적록색약이 아닌 경우 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;

			dfs(i, j);
			cnt1++;
		}
	}
	//방문처리 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
	//적록색약인 경우(R과 G를 같은 수로 처리)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	//적록색약인 경우 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;

			dfs(i, j);
			cnt2++;
		}
	}
	//출력
	cout << cnt1 << ' ' << cnt2;

	return 0;
}