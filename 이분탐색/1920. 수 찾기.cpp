#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[100010];
bool found;

int main(){
  
    ios_base::sync_with_stdio(0);cin.tie(0);
    int s, e, mid, x;
    cin >> n;
  
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
  
    cin >> m;
  
    for(int i=0; i<m; i++){
        cin >> x;
    
        s = 0, e = n-1;
        found = false;
    
        while(s <= e){
            mid = (s + e) / 2;
      
            if(arr[mid] == x){
                found = true;
                break;
            }
            else if(arr[mid] < x) s = mid+1;
            else e = mid-1;
        }
        if(found) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

  return 0;
}