#include <iostream>
using namespace std;

//조합 
int n, m;
int arr[50];

void recur(int cur, int start){
	if(cur == m){
		for(int i=0; i<m; i++){
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for(int i=start; i<=n; i++){
		arr[cur] = i;
		recur(cur+1, i+1);
	}
}

int main(){

	cin >> n >> m;

	recur(0, 1);

	return 0;
}