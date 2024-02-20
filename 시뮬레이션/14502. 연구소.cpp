#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans=0;
int arr[15][15], tmp[15][15];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void copy(int tmp[15][15], int arr[15][15]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tmp[i][j] = arr[i][j];
        }
    }
}

void bfs(){
    int after[15][15];
    copy(after, tmp);
    queue<pair<int, int>> que;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(after[i][j] == 2){
                que.push({i, j});
            }
        }
    }

    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(nx < 0 || nx>=n || ny < 0 || ny>=m) continue;

            if(after[nx][ny] == 0){
                after[nx][ny] = 2; //바이러스 퍼짐
                que.push({nx, ny});
            }
        }
    }
    //0인 안전지역 cnt
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(after[i][j] == 0) cnt++;
        }
    }
    ans = max(ans, cnt);
}
//백트래킹 -> 맵 전체를 돌면서 빈칸이 나오면 벽으로 바꾼다음 2개씩 선택하는 조합
void wall(int cur){
    if(cur == 3){
        bfs();
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp[i][j] == 0){
                tmp[i][j] = 1;
                wall(cur+1);
                tmp[i][j] = 0; //재귀가 끝나면 다음 경우를 위해 현재 벽의 없애기
            }
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0){
                copy(tmp, arr);
                tmp[i][j] = 1; //arr[i][j]=0인 위치는 새로운 벽을 세움 
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }
    cout << ans;

    return 0;
}