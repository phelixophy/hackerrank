nclude <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
        int A, B;
        cin >> A >> B;
        vector<int> a(A);
        vector<int> b(B);
        for (int i=0; i<A; ++i) cin >> a[i];
        for (int j=0; j<B; ++j) cin >> b[j];
        
        int Arr[A+1][B+1];
        memset(Arr, 0, sizeof(Arr));
        
        //Col
        for(int p=B-1; p>=0; --p){
            //Row
            for (int q=A-1; q>=0; --q){
                if (a[q]==b[p]) Arr[q][p] = 1+Arr[q+1][p+1];
                else Arr[q][p] = max (Arr[q+1][p], Arr[q][p+1]);
            }
        }
        
        int pa, pb;
        pa = pb = 0;
        int lcs = Arr[0][0];
        //cout << "lcs: " << lcs << endl;
        while (lcs){
            if (a[pa]==b[pb]) {
                cout << a[pa];
                --lcs;
                if (lcs) cout << " ";
                else cout << endl;
                ++pa;
                ++pb;
            }
            else if (Arr[pa+1][pb] > Arr[pa][pb+1] ) {
                ++pa;
            }
            else {
                ++pb;
            }
            
        }
    
    return 0;
}


