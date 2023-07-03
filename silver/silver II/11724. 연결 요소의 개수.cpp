#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
vector<int> v[1010];
bool visited[1010];

void dfs(int cur){
  int nxt;
  visited[cur] = true;
  for(int i=0; i<v[cur].size(); i++){
    nxt = v[cur][i];
    if(visited[nxt]) continue;
    
    dfs(nxt);
  }
}

int main(){

  int a, b;
  cin >> n >> m;
  
  for(int i=0; i<m; i++){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  cnt = 0;
  for(int i=1; i<=n; i++){
    if(visited[i]) continue; 
      dfs(i);//방문하지 않았으면 dfs탐색 
      cnt++; //연결요소 개수 증가
  }
  cout << cnt;
  return 0;
}