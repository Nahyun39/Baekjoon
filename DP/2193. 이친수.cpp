#include <iostream>
using namespace std;

int n;
long long dp[100]; //이친수 개수 저장하면 범위를 벗어날 수 있어 long long 

int main(){
    
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    
    return 0;
}