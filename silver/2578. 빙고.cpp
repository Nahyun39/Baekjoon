#include <iostream>

using namespace std;

int arr[10][10];
int n;
int sum;

//가로, 세로, 대각선(좌.우), 대각선(우, 좌) 빙고인지 check함수 
bool check()
{

  int cnt = 0;
  //가로
  for(int i=0; i<5; i++){
    sum = 0;
    for(int j=0; j<5; j++){
      sum += arr[i][j];
    }
    if(sum == 0) cnt++;
  }
  //세로 
  for(int i=0; i<5; i++){
    sum = 0;
    for(int j=0; j<5; j++){
      sum += arr[j][i];
    }
    if(sum == 0) cnt++;
  }
  //대각선(좌.우)
  sum = 0;
  for(int i=0; i<5; i++) sum += arr[i][i];
  if(sum == 0) cnt++;
  
  //대각선(우.좌)
  sum = 0;
  for(int i=0; i<5; i++) sum += arr[i][4-i];
  if(sum == 0) cnt++;
  
  if(cnt >= 3) return true;
  else return false;
  
}
//사회자가 부른 값이 있으면 그 위치 0으로 초기화 해주는 함수 
void count(int n)
{
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      if(n == arr[i][j]) arr[i][j] = 0; 
    }
  }
}

int main() {
  
  for(int i=0; i<5; i++){ //입력 
    for(int j=0; j<5; j++){
      cin >> arr[i][j];
    }
  }
  
  for(int i=0; i<25; i++){
      cin >> n;
      count(n);
      
      if(check()){
        cout << i+1; //0부터 시작해서 count된 값 +1
        break;
      }
  }

  return 0;
}