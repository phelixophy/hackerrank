nclude <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <climits>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

struct vertex{
  int num;
  long long int val;  
  int visited;
};


int main() {
    int N;
    cin >> N;
    vertex vec [N];
    unordered_map <int, vector<int>> umap;
    int edge[2][N-1];
    long long int Sum =0;
    for (int i=0; i<N; ++i){
        int In;
        cin >> In;
        vec[i].num =i+1;
        vec[i].val = In;
        vec[i].visited = 0;
        Sum += In;
    }

    for (int j=0; j<N-1; ++j){
        int x, y;
        cin >> x;
        cin >> y;
        umap[x].push_back(y);
        umap[y].push_back(x);
        edge[0][j]=x;
        edge[1][j]=y;
    }
    
    stack<vertex> vstA;
    long long int Diff=INT_MAX;
    long long int SumA;
        SumA=0;
        vstA.push(vec[0]);
        
        while(!vstA.empty()){            
        bool pushed = false;
        vertex topA=vstA.top();
        //cout << "Now at: " << topA.num << endl;
        vec[topA.num-1].visited=1;
            for (int p=0; p<umap[topA.num].size(); ++p){
                int chd = umap[topA.num].at(p);
                if (vec[chd-1].visited==0){
                    pushed=true;
                    vstA.push(vec[chd-1]);                    
                } 
            }
           if (!pushed){
            for (int q=0; q<umap[topA.num].size(); ++q){
                if(vec[umap[topA.num].at(q)-1].visited!=2){
                    vec[umap[topA.num].at(q)-1].val += vec[topA.num-1].val;
                    vec[topA.num-1].visited=2;
                }
            }
            Diff = min (Diff, abs(Sum-2*vec[topA.num-1].val));
            vec[topA.num-1].val=0;   
            vstA.pop();     
            }
        }     

    cout << Diff << endl;
    
    return 0;
}


