#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
vector<string> v;

int main(){
  
  string ans1, ans2;
  bool flag1=false, flag2=false;
  
  cin >> n;
  
  for(int i=0; i<n; i++){
    cin >> s;
    v.push_back(s);
  }


  for(int i=0; i<n-1; i++){
    if(v[i] < v[i+1]){
      ans1 = "INCREASING";
      flag1 = true;
    }
    else if(v[i] > v[i+1]){
      ans2 = "DECREASING";
      flag2 = true;
    }
  }
  if(flag1 && !flag2) cout << ans1 << '\n';
  else if(!flag1 && flag2) cout << ans2 << '\n';
  else cout << "NEITHER";
  
  return 0;
}