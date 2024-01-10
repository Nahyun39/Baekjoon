#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1010];
int dp[1010];

int main(){

    int sum = 0;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        dp[i] = 1;

        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){ //자신의 인덱스 수보다 작다면
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        sum = max(dp[i], sum);
    }
    cout << sum;

    return 0;
}