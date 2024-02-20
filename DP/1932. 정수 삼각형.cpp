#include <iostream>
#include <algorithm>
using namespace std;

//밑에서 위로 큰 값을 누적해서 마지막에는 제일 위해 최대값 저장

int n;
int dp[550][550] = {0, 0};
int main(){

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> dp[i][j];
        }
    }

    for(int i=n; i>0; i--){
        for(int j=0; j<i; j++){
            int ans = max(dp[i][j], dp[i][j+1]);
            dp[i-1][j] += ans;
        }
    }
    cout << dp[1][1];

    return 0;
}