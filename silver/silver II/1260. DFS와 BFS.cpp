#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, s;
vector<int> v[10010];
vector<int> dfs_result;
vector<int> bfs_result;
bool visited_bfs[10010];
bool visited_dfs[10010];

void bfs(int x){
  queue<int> que;
  que.push(x);
  visited_bfs[x] = true;
  
  while(!que.empty()){
    int temp = que.front();
    que.pop();
    bfs_result.push_back(temp);
    
    for(int i=0; i<v[temp].size(); i++){
      if(!visited_bfs[v[temp][i]]){
        que.push(v[temp][i]);
        visited_bfs[v[temp][i]] = true;
      }
    }
  }
}

void dfs(int cur){
  int nxt;
  visited_dfs[cur] = true;
  dfs_result.push_back(cur);
  for(int i=0; i<v[cur].size(); i++){
    nxt = v[cur][i];
    if(visited_dfs[nxt]) continue;
    
    dfs(nxt);
  }
}

int main() {
  
  int a, b;
  cin >> n >> m >> s;
  
  for(int i=0; i<m; i++){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  
  for(int i=1; i<=n; i++){ //낮은 수부터 검색 
    sort(v[i].begin(), v[i].end());
  }
  
  dfs(s);
  bfs(s);
  for(int i=0; i<dfs_result.size(); i++) cout << dfs_result[i] << ' ';
  cout << '\n';
  for(int i=0; i<bfs_result.size(); i++) cout << bfs_result[i] << ' ';

  return 0;
}