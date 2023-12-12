#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
vector<pair<int, int>> v[10010];
int visited[10010];

void bfs(int x, int y) {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> que;
	visited[x] = true;
	que.push(make_pair(x, 0));

	while (!que.empty()) {
		int cur = que.front().first;
		int d = que.front().second;
		que.pop();
		//현재노드가 마지막 노드(y)라면 
		if (cur == y) cout << d << '\n';

		for (int i = 0; i < v[cur].size(); i++) {
			int nx = v[cur][i].first;
			int ny = v[cur][i].second;

			if (visited[nx]) continue;

			que.push(make_pair(nx, ny + d));
			visited[nx] = true;
		}
	}
}


int main() {

	int x, y, d, a, b;
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> d;
		v[x].push_back(make_pair(y, d));
		v[y].push_back(make_pair(x, d));
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		bfs(a, b);
	}

	return 0;
}