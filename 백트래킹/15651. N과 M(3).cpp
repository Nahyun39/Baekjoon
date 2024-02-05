#include <iostream>
using namespace std;

int n, m, arr[50];

void recur(int cur){
	if(cur == n){
		for(int i=0; i<n; i++){
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for(int i=1; i<=m; i++){
		arr[cur] = i;
		recur(cur+1);
	}
}

int main(){

	cin >> n >> m;

	recur(0);

	return 0;
}