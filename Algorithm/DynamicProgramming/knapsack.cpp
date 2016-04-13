nclude <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    
    while(T--){
        int N, E;
        cin >> N >> E;
        set<int> Set;
        for (int i=0; i<N; ++i){
            int temp;
            cin >> temp;
            Set.insert(temp);
        }
        int Ar [2001];
        memset(Ar, 0, sizeof(Ar));
        int Max=0;
        for (int k=1; k<=E; ++k){
            
            for (int l=1; l<=k; ++l){
                if (Set.find(l)!=Set.end()){
                    if (l+Ar[k-l]<=k) Ar[k] = max(l + Ar[k-l] , Ar[k]);
                    //cout << "k: " << k << " " << Ar[k] << endl;
                }
            }
        }
        cout << Ar[E] << endl;
    }
    
    
    return 0;
}


