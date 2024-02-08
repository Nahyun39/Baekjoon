#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans[100010];

//오래 걸리는 나무 먼저 심기 

int main(){

    int x;
    vector<int> v;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.rbegin(), v.rend()); // 4 3 3 2

    for(int i=0; i<n; i++){
        ans[i] = (i+1) + v[i]; // 모묙 구입한 첫날이 1일이여서 i+1
    }
    sort(ans, ans+n);

    cout << ans[n-1] + 1;

    return 0;
}