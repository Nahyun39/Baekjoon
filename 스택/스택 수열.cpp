#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;

int main(){

    vector<char> v;
    stack<int> st;
    cin >> n;

    int target, current = 1;

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

    for(char op : v){
        cout << op << '\n';
    }

    return 0;
}

