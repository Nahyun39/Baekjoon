#include <iostream>
using namespace std;

int T, n;
long long int dp[110]; //n에 100을 넣으면 888855064897이라는 값이 나오기 때문에 long long 사용

int main(){

    cin >> T;

    for(int t=0; t<T; t++){
        cin >> n;

        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;

        for(int i=4; i<=n; i++){
            dp[i] = dp[i-2] + dp[i-3];
        }

        cout << dp[n] << '\n';
    }
    
    return 0;
}