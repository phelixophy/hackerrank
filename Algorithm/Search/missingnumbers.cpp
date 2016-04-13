nclude <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int A, B;
    map<int,int> mapa; 
    cin >> A;
    for (int i=0; i<A; ++i){
        int n;
        cin >> n;
        if (mapa.find(n)==mapa.end()) mapa[n] = 1;
        else ++mapa[n];
    }
    cin >> B;
    for (int i=0; i<B; ++i){
        int m;
        cin >> m;
        if (mapa.find(m)==mapa.end()) mapa[m] = 1;
        else --mapa[m];
    }

    for (auto it = mapa.begin(); it != mapa.end(); ++it){
        if (it->second != 0) cout << it->first << " ";
    }
    
    return 0;
}


