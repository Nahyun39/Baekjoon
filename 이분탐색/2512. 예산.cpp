#include <iostream>
#include <algorithm>
using namespace std;

//정해진 총액 이하에서 가능한 최대의 총 예산

int n, m;
int arr[10010];

int main(){
    
    int s, e, mid, ans=0, max=-1;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(max < arr[i]) max = arr[i];
    }
    sort(arr, arr+n);

    cin >> m;

    s = 0, e = max;
    while(s <= e){
        mid = (s+e)/2;

        int sum = 0;
        for(int i=0; i<n; i++){
            if(arr[i] > mid){
                sum += mid;
            }
            else sum += arr[i];
        }
        
        if(sum > m){
            e = mid-1;
        }
        else{
            s = mid+1;
            if(ans < mid) ans = mid;
        }
    }
    cout << ans;

    return 0;
}