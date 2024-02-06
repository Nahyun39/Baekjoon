#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x;

int main(){

    int ans = 0;
    vector<int> crane;
    vector<int> box;
    cin >> n;
    for(int i=0; i<n; i++){ //크레인 무게 20 19
        cin >> x;
        crane.push_back(x);
    }
    sort(crane.rbegin(), crane.rend());

    cin >> m;
    for(int i=0; i<m; i++){ //박스 무게 19 16 16 14 12 5 1
        cin >> x;
        box.push_back(x);
    }
    sort(box.rbegin(), box.rend());

    if(box[0] > crane[0]){
        cout << -1;
        return 0;
    }
    
    while(!box.empty()){
        ans++;
        for(int i=0; i<crane.size(); i++){
            for(int j=0; j<box.size(); j++){
                if(crane[i] >= box[j]){
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }
    cout << ans;

    return 0;
}