#include <iostream>
using namespace std;

//이항계수
//nCk = (n-1)Ck + (n-1)C(k-1)

int n, k;
long long dp[1010][1010];

int main(){
  
    cin >> n >> k;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(j == 0 || i == j){
                dp[i][j] = 1;
            }
            else{
                //파스칼의 삼각형
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                dp[i][j] %= 10007;
            }
        }
    }
    cout << dp[n][k];

    return 0;
}