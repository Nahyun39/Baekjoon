#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1000010]; //연산의 최솟값 
int before[1000010]; //각 숫자를 만들기 직전에 어떤 숫자를 사용했는지 저장 

int main(){

    cin >> n;

    dp[1] = 0;
    before[1] = 0;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        before[i] = i-1;
        
        if(i % 3 == 0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            before[i] = i/3;
        }
        if(i % 2 == 0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
            before[i] = i/2;
        }
    }
    cout << dp[n] << '\n';

    //0이 되기 전까지 이전의 수 찾아서 출력
    while(n != 0){
        cout << n << ' ';
        n = before[n];
    }

    return 0;
}