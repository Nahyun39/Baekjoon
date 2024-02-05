#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;

int main(){

    int target, current = 1;
    vector<char> v;
    stack<int> st;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> target;

        while(current <= target){
            st.push(current);
            v.push_back('+');
            current++;
        }

        if(st.top() == target){
            st.pop();
            v.push_back('-');
        }
        else{
            cout << "NO" << '\n';
            return 0;
        }
    }

    for(char c : v){
        cout << c << '\n';
    }
    return 0;
}