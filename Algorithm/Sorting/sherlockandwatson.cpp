nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, K, Q;
    cin >> N;
    cin >> K;
    cin >> Q;
    int Arr[N];
    for (int i=0; i<N; ++i) cin >> Arr[i];
    for (int j=0; j<Q; ++j){
        int index;
        cin >> index;
        if (index-K%N<0) cout << Arr[index-K%N+N] <<endl;
        else cout << Arr[index-K%N] << endl;
    }
    
    return 0;
}


