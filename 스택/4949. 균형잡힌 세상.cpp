#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;

int main(){

    while(true){
        stack<char> st;
        getline(cin, s);
        bool flag = true;

        if(s == ".") break;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' or s[i] == '['){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(!st.empty() and st.top() == '('){
                    st.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(s[i] == ']'){
                if(!st.empty() and st.top() == '['){
                    st.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(st.empty() && flag) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}