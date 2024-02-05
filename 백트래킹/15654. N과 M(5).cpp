#include <iostream>
#include <algorithm>
using namespace std;

//순열 

int n, m, arr[50];
bool visited[50];

void recur(int cur){
    if(cur == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for(int i=0; i<n; i++){
        if(visited[arr[i]]) continue;

        visited[arr[i]] = true;
        arr[cur] = arr[i];
        recur(cur+1);
        visited[arr[i]] = false;
    }

    
}

int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n); // 1 7 8 9 

    recur(0);

    return 0;
}