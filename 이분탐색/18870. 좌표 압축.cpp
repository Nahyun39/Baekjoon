#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v, v_before;

//좌표 압축 : 해당 좌표의 값을 그 값보다 작은 좌표값들의 개수로 대체한다는 의미


int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);
    int x;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
        v_before.push_back(x);
    }
    sort(v.begin(), v.end()); //-10 -9 2 4 4
    v.erase(unique(v.begin(), v.end()), v.end()); //중복제거 

    for(int i=0; i<n; i++){
        cout << lower_bound(v.begin(), v.end(), v_before[i]) - v.begin() << ' ';
    }
    
    return 0;
}

//unique(begin, end): 벡터의 중복 원소를 벡터의 제일 뒷 부분으로 보내고 앞에서부터 원소들을 채운다.
//주로 졍렬된 벡터에서, erase(unique(begin,end), end)와 같이 사용하여 중복을 제거하는데 사용된다.