#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

//결과를 저장하는 result, 화살표 입력시 필요한 tmp스택 정의
//'<' -> result의 top문자를 tmp에 push하고 result에서 pop
//'>' -> tmp의 top문자를 result에 push하고 tmp에서 pop
//백스페이스는 result에서 pop
//이외는 result에 push
//반복문 탈출했을 때 남은 tmp의 문자들을 전부 result에 push
//거꾸로 출력하기 LIFO이여서

int n;
string s;

int main(){
    
    cin >> n;

    for(int t=0; t<n; t++){
        stack<char> result;
        stack<char> tmp;  //화살표 입력 시 필요한 스택 
        cin >> s;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '<'){
                if(!result.empty()){
                    tmp.push(result.top());
                    result.pop();
                }
            }
            else if(s[i] == '>'){
                if(!tmp.empty()){
                    result.push(tmp.top());
                    tmp.pop();
                }
            }
            else if(s[i] == '-'){
                if(!result.empty()){
                    result.pop();
                }
            }
            else{
                result.push(s[i]);
            }
        }
        while(!tmp.empty()){
            result.push(tmp.top());
            tmp.pop();
        }
        string ans;

        while(!result.empty()){
            ans += result.top(); //스택은 LIFO여서 거꾸로 넣어짐
            result.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    return 0;
}