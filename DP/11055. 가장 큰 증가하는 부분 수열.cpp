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
        dp[i] = arr[i];

        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], arr[i] + dp[j]);
            }
        }
        sum = max(dp[i], sum);
    }
    cout << sum;
    
    return 0;
}