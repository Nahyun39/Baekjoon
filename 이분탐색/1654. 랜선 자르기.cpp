#include <iostream>
#include <algorithm>
using namespace std;

int n, k, arr[10010];

int main(){

    long long int s, e, mid, max=-1, ans=0;
    cin >> k >> n;

    for(int i=0; i<k; i++){
        cin >> arr[i];
        if(max < arr[i]) max = arr[i];
    }
    sort(arr, arr+n);

    s = 1, e = max;

    while(s <= e){
        mid = (s+e)/2;

        int cnt = 0; //만들 수 있는 랜선의 갯수  
        for(int i=0; i<k; i++){
            cnt += arr[i] / mid;
        }
        if(cnt >= n){
            s = mid+1;
            if(ans < mid) ans = mid; //n개를 만들 수 있는 랜선의 최대 길이 
        }
        else{
            e = mid-1;
        }
    }
    cout << ans;

    return 0;
}