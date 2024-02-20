#include <iostream>
using namespace std;

int T, n;
int zero[45];
int one[45];

int main(){

    cin >> T;

    zero[0] = 1, zero[1] = 0;
    one[0] = 0, one[1] = 1;

    for(int t=0; t<T; t++){
        cin >> n;

        for(int i=2; i<=n; i++){
            zero[i] = zero[i-1] + zero[i-2];
            one[i] = one[i-1] + one[i-2];
        }
        cout << zero[n] << ' ' << one[n] << '\n';
    }

    return 0;
}