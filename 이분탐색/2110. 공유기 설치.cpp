#include <iostream>
#include <algorithm>
using namespace std;

long long int n, c;
int arr[200010];

int main(){

    int s, e, mid, ans=0;
    cin >> n >> c;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    s = 1, e = arr[n-1] - arr[0];
    while(s <= e){
        mid = (s+e)/2;

        int cnt=1; //첫번째 집은 설치하고 시작 
        int prev = arr[0];
        
        for(int i=1; i<n; i++){
            if(arr[i] - prev >= mid){
                cnt++;
                prev = arr[i];
            }
        }
        
        if(cnt >= c){
            s = mid+1;
            if(ans < mid) ans = mid;
        }
        else e = mid-1;
    }
    cout << ans;
    
    return 0;
}