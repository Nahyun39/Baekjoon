#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[110];
bool visited[110];
int cnt;

void dfs(int cur){
  int nxt;
  visited[cur] = true;
  cnt++;
  for(int i=0; i<v[cur].size(); i++){
    nxt = v[cur][i];
    if(visited[nxt]) continue;
    
    dfs(nxt);
  }
}

int main() {
  
  int a, b;
  cin >> n;
  cin >> m;
  
  for(int i=0; i<m; i++){
    cin >> a >> b;
    
    v[a].push_back(b);
    v[b].push_back(a);
    
  }
  dfs(1);
  cout << cnt-1;
  
  return 0;
}