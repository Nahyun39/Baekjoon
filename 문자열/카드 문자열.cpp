#include <iostream>
#include <deque>
using namespace std;

//앞뒤로 문자를 넣어주기 위해서 vector 대신 deque을 사용하면 편리함 

int T, n;
char v[1010];

int main(){
  
  cin >> T;
  
  for(int t=0; t<T; t++){
    deque<char> dq;
    cin >> n;
    
    for(int i=0; i<n; i++){
      cin >> v[i];
    }
    
    for(int i=0; i<n; i++){
      if(i == 0){
        dq.push_back(v[0]);
      }
      else if(v[i] <= dq.front()){
        dq.push_front(v[i]);
      }
      else{
        dq.push_back(v[i]);
      }
    }
    
    for(int i=0; i<dq.size(); i++){
      cout << dq[i];
    }
    cout << '\n';
  }
  return 0;
}