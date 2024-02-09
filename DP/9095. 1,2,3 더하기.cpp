#include <iostream>
using namespace std;

int T, x;
int dp[10000];

int main(){

    cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int t=0; t<T; t++){
        cin >> x;

        for(int i=4; i<=x; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[x] << '\n';
    }
    
    return 0;
}