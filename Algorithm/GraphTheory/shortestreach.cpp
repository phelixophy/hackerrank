nclude <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Dijk {
    public:
        Dijk(){}
        Dijk(int x, int y) {
            node = x;
            dist = y;
        }
        int node;
        int dist;
};

class mycomp
{
public:
  bool operator() (const Dijk& lhs, const Dijk& rhs) const
  {
    return (lhs.dist>rhs.dist);
  }
};

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; ++i){
        unordered_map<int, vector<int>> umap, smap;
        int M, O;
        cin >> M;
        cin >> O;
        for (int j=0; j<O; ++j){
            int P,Q;
            cin >> P;
            cin >> Q;
            (umap[P]).push_back(Q); 
            (umap[Q]).push_back(P); 
        }
        
        int S;
        cin >> S;  
        Dijk darray[M];
        for (int i=1; i<=M; ++i){
            if (i==S) {
                darray[i-1].node = i;
                darray[i-1].dist = 0;
            }
            else {
                darray[i-1].node = i;
                darray[i-1].dist = INT_MAX;
            }
        }
        
        priority_queue <Dijk, vector<Dijk>, mycomp> pq;
        pq.push(darray[S-1]);
        int upd = 0;
        while(!pq.empty()){
            Dijk temp = pq.top();
            //cout << "temp: " << temp.node << " dist: " << temp.dist <<endl;
            pq.pop();
            for (auto it=umap[temp.node].begin(); it!=umap[temp.node].end(); ++it){
                upd = temp.dist + 6;
                if (upd < darray[(*it)-1].dist) {
                    darray[(*it)-1].dist = upd;
                    pq.push(darray[(*it)-1]);
                }
            }
        }
        
        for (int j=1; j<=M; ++j){
            if (j!=S){
                if(darray[j-1].dist==INT_MAX) cout<< -1;
                else cout << darray[j-1].dist;
                cout << " ";
            }
        }
        umap.clear();
    cout << endl;
    }
    return 0;
}


