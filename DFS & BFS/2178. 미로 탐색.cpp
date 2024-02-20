#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int arr[110][110];
int visited[110][110];
int dist[110][110];
queue<pair<int, int>> que;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y){
    que.push({x, y});
    visited[x][y] = true;
    dist[x][y]++; //시작위치 count

    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i]; 

            if(nx < 0 || nx >= n || ny < 0 || ny >=m || visited[nx][ny] || arr[nx][ny] == 0) continue;

            que.push({nx, ny});
            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

int main(){
    
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j] - '0';
        }
    }
    bfs(0, 0);

    cout << dist[n-1][m-1];

    return 0;
}