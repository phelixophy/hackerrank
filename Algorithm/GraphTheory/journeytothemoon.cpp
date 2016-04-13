nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}
 
class djs{
    
    public:
        
    int rank[100000];
    int leader[100000];
    
    void INIT(int n){
        for (int i=0; i<n; ++i){
            rank[i]=1;
            leader[i]=i;
        }
    }

    int FIND(int x){
        if(leader[x]!=x) leader[x] = FIND(leader[x]);
        return leader[x];
    }    

    void UNION(int x, int y){
        int xx = FIND(x);
        int yy = FIND(y);
        if (xx==yy) return;
        
        if (rank[xx]>rank[yy]) {
            int temp=xx;
            xx = yy;
            yy = temp;
        }
        rank[yy] += rank[xx];
        leader[xx]=leader[yy];
    }
    
    int pair(
            int n,
            int x
            ){
        return rank[x]*(n-rank[x]);
    }
    void print(int n){
        for (int i=0; i<n; ++i)  cout << i << " has rank of " << rank[i] << " leader is " << leader[i] << endl;
    }
};


int main()
{ 
    djs DJS;    
    int N, I;
    cin >> N >> I;
    vector<vector<int>> pairs(N);
    DJS.INIT(N);    
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
        DJS.UNION(a,b);
    }
    
    //DJS.print(4);
    
    long long result = 0;
    for (int j=0; j<N; ++j){
        if (DJS.FIND(j)!=j) continue;
        result += DJS.pair(N, j);
    }
    
    cout << result/2 << endl;
    return 0;
}


