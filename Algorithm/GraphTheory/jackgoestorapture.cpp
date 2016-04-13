nclude <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct subset{
    int parent;
    int rank;
};

struct Edge{
    int Start;
    int End;
    int Cost;
};

class mycomp
{
public:
  bool operator() (const Edge& lhs, const Edge& rhs) const
  {
        return (lhs.Cost > rhs.Cost);
  }
};
 
int Find (  subset subSet[50000],
            int u
         ){
    if(u!=subSet[subSet[u].parent].parent) {
        subSet[u].parent = Find (subSet, subSet[u].parent);
    }
    return subSet[u].parent;
};

void Union ( subset subSet[50000],
             int u,
             int v
            ){  
    
    int uu = Find(subSet, u);
    int vv = Find(subSet, v);
    
    if (uu==vv) return;  
    
    
    if (subSet[uu].rank<subSet[vv].rank){
        subSet[uu].parent = subSet[vv].parent;
    }
    else if (subSet[uu].rank>subSet[vv].rank){
        subSet[vv].parent = subSet[uu].parent;
    }
    else {
        subSet[vv].parent = subSet[uu].parent;        
        ++subSet[uu].rank;
    }
};


int main() {
    int N;
    long long E;
    cin >> N >> E;
    subset subSet [50000];
    priority_queue<Edge, vector<Edge>, mycomp> UV;
    
    for (long long j=0; j<E; ++j){
        int Start, End, Cost;
        cin >> Start >> End >> Cost;
        UV.push({Start,End,Cost});
        //UV.push_back({Start, End, Cost});
    }
    
    //sort (UV.begin(), UV.end(), mycomp());
    
    for (int i=0; i<N; ++i){
        subSet[i].parent = i;
        subSet[i].rank = 0;
    }
    
    long long Fare=0;
    long long Index=0;
    bool found = false;
    
    while (Index<N-1 && !UV.empty()){
        Edge cur= UV.top();
        long long A=Find(subSet, cur.Start-1);
        long long B=Find(subSet, cur.End-1);
        UV.pop();        
        if (A!=B){
            //++Index;
            Union(subSet, A, B);

            if (Find(subSet,0)==Find(subSet,N-1)) {
                found = true;
                Fare = cur.Cost;
                break;
            }

        }
    }
    
    if (found) cout << Fare << endl;
    else cout << "NO PATH EXISTS" << endl;
    
    return 0;
}


