// #include <iostream>
// using namespace std;

// int n;

// //재귀 -> 시간초과 

// int fibo(int n){
//     if(n==0) return 0;
//     else if(n==1) return 1;
    
//     return fibo(n-1) + fibo(n-2);
// }

// int main(){

//     cin >> n;

//     cout << fibo(n);

//     return 0;
// }

#include <iostream>
using namespace std;

int n, dp[1000000];

int main(){
  
  cin >> n;
  
  dp[0] = 0, dp[1] = 1;
  for(int i=2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  
  cout << dp[n];
  
  return 0;
}