#include <iostream>
#include <deque>
#include <string>
using namespace std;

int n, k;
string s;

int main(){

    deque<char> dq;

    cin >> n >> k;
    cin >> s;

    for(int i=0; i<s.size(); i++){
        while(!dq.empty() && k && dq.back() < s[i]){
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }

    for(int i=0; i<dq.size()-k; i++){ //k를 감소하는 갯수가 무조건 0까지 줄지 않음, 예외가 존재
        cout << dq[i];
    }
    cout << '\n';

    return 0;
}