#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100010];
int dp[100010];

int main(){

    int sum = 0;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sum = arr[0];

    for(int i=0; i<n; i++){
        dp[i] = max(arr[i] + dp[i-1], arr[i]);
        sum = max(sum, dp[i]);
    }
    cout << sum;

    return 0;
}