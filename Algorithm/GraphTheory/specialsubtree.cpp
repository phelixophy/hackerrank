nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <algorithm>
using namespace std;

int minKey(int Size, int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < Size; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}

int main() {
    int N;
    cin >> N;
    int E;
    cin >> E;
    int umap[N][N];
    int adj[N][N];
    bool mstSet [N] = {false};
    memset(umap, 0, N*N);
    memset(adj, 0, N*N);    
    for (int i=0; i<E; ++i){
        int A, B, Cost;
        cin >> A;
        cin >> B;
        cin >> Cost;
        umap[A-1][B-1]=Cost;
        adj[A-1][B-1]= 1;
        umap[B-1][A-1]=Cost;       
        adj[B-1][A-1]= 1;        
    }
    int Start, Sum;
    cin >> Start;
    Sum =0;
   int key [N];
   int parent [N];
    for (int q=0; q<N; ++q) {
        key[q] = INT_MAX;            
    }
    parent[Start-1] = -1;
    key[Start-1] = 0;
    
    int Parent = Start;
    for (int i=0; i<N-1; ++i){
        int u = minKey(N, key, mstSet);
        mstSet[u]=true;
        int v, vadd;
        int minCost = INT_MAX;
        for (v=0; v<N; ++v){
            if (adj[u][v]==0) continue;
            if (mstSet[v]==false && (umap[u][v] < key[v])){
                //cout << "u: " << u+1 << " v: " << v+1 << " Cost: "<< umap[u][v] << endl;
                //cout << "adj: " << adj[u][v] << endl;
                key[v] = umap[u][v];
                parent[v] = u;
            }
        }
    }    
    for (int x=0; x<N; ++x){
        if (parent[x]>=0) Sum+= umap[x][parent[x]];
    }
    
    cout << Sum;
    return 0;
}


