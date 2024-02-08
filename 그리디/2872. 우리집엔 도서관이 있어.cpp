#include <iostream>
using namespace std;

//가장 큰 수에서부터 위로 올라가며 가장 긴 증가수열을 찾아서 n에서 빼주면 된다. 

int n, arr[300010];

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int cnt = n;
    for(int i=n-1; i>=0; i--){
        if(arr[i] == cnt){
            cnt--;
        }
    }
    cout << cnt;

    return 0;
}