#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//시간초과 난 코드 
// int n, m, arr[500010];
// bool found;

// int main(){

//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int s, e, mid, x, idx, cnt;
//     cin >> n;

//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     sort(arr, arr+n);
//     //-10 -10 2 3 3 6 7 10 10 10

//     cin >> m;

//     for(int i=0; i<m; i++){
//         cin >> x;

//         s = 0, e = n-1;
//         found = false;

//         while(s <= e){
//             mid = (s+e)/2;

//             if(arr[mid] == x){
//                 found = true;
//                 idx = mid;
//                 break;
//             }
//             else if(arr[mid] < x) s = mid+1;
//             else e = mid-1;
//         }
//         cnt = 0;
//         if(found){
//             for(int i=0; i<n; i++){
        
//                 if(arr[i] == x) cnt++;
//             }
//             cout << cnt << '\n';
//         }
//         else cout << 0 << '\n';
//     }
    
//     return 0;
// }

int n, m, arr[500010];
bool found;

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);
    int s, e, mid, x, idx, cnt;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    //-10 -10 2 3 3 6 7 10 10 10

    cin >> m;

    for(int i=0; i<m; i++){
        cin >> x;
        
        cout << upper_bound(arr, arr+n, x) - lower_bound(arr, arr+n, x) << ' ';
    }
    
    return 0;
}

//lower_bound(first, last, key) : 찾으려는 key값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지
//upper_bound(first, last, key) : 찾으려는 key값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는 지 
//주로 오름차순으로 정렬된 자료에서 특정한 숫자가 몇 번 나오는지 탐색하고자 할 때