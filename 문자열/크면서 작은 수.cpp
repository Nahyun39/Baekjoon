#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  
  string s;
  cin >> s;
  
  bool possible = next_permutation(s.begin(), s.end());
  
  if(possible){
    cout << s << '\n';
  }
  else cout << 0;
  
  return 0;
}