#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, s;
vector<int> v[10010];
vector<int> DFS;
vector<int> BFS;
int visitedDFS[100010];
int visitedBFS[100010];
queue<int> que;

void dfs(int cur){
	visitedDFS[cur] = true;
	DFS.push_back(cur);

	for(int i=0; i<v[cur].size(); i++){
		int nxt = v[cur][i];

		if(visitedDFS[nxt]) continue;

		dfs(nxt);
	}
}

void bfs(int cur){
	que.push(cur);
	visitedBFS[cur] = true;
	BFS.push_back(cur);

	while(!que.empty()){
		int cur = que.front();
		que.pop();

		for(int i=0; i<v[cur].size(); i++){
			int nxt = v[cur][i];

			if(visitedBFS[nxt]) continue;

			que.push(nxt);
			visitedBFS[nxt] = true;
		}
	}
}

int main(){

	int a, b;
	cin >> n >> m >> s;

	for(int i=0; i<m; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//정점이 작은 것부터 방문
	for(int i=1; i<=n; i++){
		sort(v[i].begin(), v[i].end());
	}

	dfs(s);
	bfs(s);

	for(int i=0; i<DFS.size(); i++){
		cout << DFS[i] << ' ';
	}
	cout << '\n';

	for(int i=0; i<BFS.size(); i++){
		cout << BFS[i] << ' ';
	}

	return 0;
}