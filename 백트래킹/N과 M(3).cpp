#include <iostream>
using namespace std;

//중복순열

int n, m, arr[10];
bool visited[10];

void recur(int cur) {
	if (cur == m) {
	    for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[cur] = i;
		recur(cur + 1);
	}
}

int main() {

	cin >> n >> m; 

	recur(0);

	return 0;
}