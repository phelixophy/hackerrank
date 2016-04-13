nclude <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    unordered_map<int, int> umap;
    unordered_map<int, vector<string>> vmap;
    int Arr[N] ;
    string SA[N];
    for(int i=0; i<N; ++i){
        cin >> Arr[i];
        cin >> SA[i];
    }
    for (int j=0; j<N; ++j){
        if(umap.find(Arr[j])==umap.end()) {
            umap[Arr[j]]=1;
        }
        else ++umap[Arr[j]];
        
        if (j<N/2) vmap[Arr[j]].push_back("-");
        else vmap[Arr[j]].push_back(SA[j]);
    }
    int Sum = (umap.find(0)==umap.end())? 0 : umap[0];
    for (int k=1; k<100; ++k){
        if(umap.find(k)==umap.end()) continue;
        else{
            umap[k]+=Sum;
            Sum = umap[k];
        }
    }
    for (int p=0; p<100; ++p){
        if (umap.find(p)==umap.end()) continue;
        for (auto jt=vmap[p].begin(); jt!=vmap[p].end(); ++jt){
            cout << *jt << " ";
        }   
    } 
    cout << endl;
    
    return 0;
}


