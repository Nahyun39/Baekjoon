#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[10010];
int dp[10010];

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0] + arr[1]);
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    //두 계단을 오른 경우, 연속된 3개의 계단을 밟지 않기 위한 것 중 큰 값 
    for(int i=3; i<n; i++){
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
    }
    cout << dp[n-1];

    return 0;
}