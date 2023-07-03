#include <iostream>
#include <string>

using namespace std;

string s;


int main(){
  
  cin >> s;
  
  int cnt=0;
  for(int i=0; i<s.size(); i++){
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
      cnt++;
    }
  }
  cout << cnt;
  
  return 0;
}