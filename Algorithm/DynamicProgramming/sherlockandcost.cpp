nclude <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        vector<int> Arr (N);
        for (int i=0; i<N; ++i) cin >> Arr[i];
        int Sum=0;
        vector<int> A (N);
        vector<int> B (N);
        for (int in=0; in<N; ++in) {
            A[in]=0;
            B[in]=0;
        }
        
        for (int j=1; j<N; ++j){
            //j to 1
            A[j] = max (A[j-1], B[j-1] + abs(1-Arr[j-1]));
            //j-1 to 1 vs j-1 to B
            B[j] = max (B[j-1] + abs(Arr[j]-Arr[j-1]), A[j-1] + abs(Arr[j]-1));
        }        
        cout << max(A[N-1], B[N-1]) << endl;
    }
    
    
    return 0;
}


