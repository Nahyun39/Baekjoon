#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, s;
vector<int> v[10010];
vector<int> BFS;
vector<int> DFS;
int visitedDFS[10010];
int visitedBFS[10010];
queue<int> que;

void dfs(int cur) {
	visitedDFS[cur] = true;
	DFS.push_back(cur);

	for (int i = 0; i < v[cur].size(); i++) {
		if (visitedDFS[v[cur][i]]) continue;

		dfs(v[cur][i]);
	}
}

void bfs(int x) {
	que.push(x);
	visitedBFS[x] = true;

	while (!que.empty()) {
		int cur = que.front();
		BFS.push_back(cur);
		que.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			if (visitedBFS[v[cur][i]]) continue;

			que.push(v[cur][i]);
			visitedBFS[v[cur][i]] = true;
		}
	}
}

int main() {

	int a, b;
	cin >> n >> m >> s;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//정점이 작은 것부터 방문 
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(s);
	bfs(s);

	for (int i = 0; i < DFS.size(); i++) {
		cout << DFS[i] << ' ';
	}
	cout << '\n';

	for (int i = 0; i < BFS.size(); i++) {
		cout << BFS[i] << ' ';
	}

	return 0;
}