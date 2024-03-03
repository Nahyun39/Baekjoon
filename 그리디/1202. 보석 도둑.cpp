#include <iostream>
using namespace std;

int n, k;
int m[1000010], v[1000010];
long long c[100000010];

int main(){

    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> m[i];
    }

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    for(long long i=0; i<k; i++){
        cin >> c[i];
    }
    return 0;
}