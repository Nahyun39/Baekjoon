#include <iostream>
using namespace std;

//순열

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
		if (visited[i]) continue;

		visited[i] = true;
		arr[cur] = i;
		recur(cur + 1);
		visited[i] = false;
	}
}

int main() {

	cin >> n >> m; 

	recur(0);

	return 0;
}