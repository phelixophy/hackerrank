nclude <cmath>
#include <cstdio>
#include <stack>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

struct Cord{
    int row;
    int col;
};


int main() {
    
    int N;
    cin >> N;
    for (int i=0; i<N; ++i){
        int M,O,K;
        cin >> M;
        cin >> O;
        char laby[M][O];
        Cord Herm;
        Cord Exit;
        for (int i=0; i<M; ++i){
            for (int j=0; j<O; ++j){
                char Input;
                cin >> Input;
                if (Input=='M') {                    
                    Herm.row=i;
                    Herm.col=j;
                }
                if (Input=='*'){
                    Exit.row=i;
                    Exit.row=j;
                } 
                laby[i][j] = Input;
            }
        }
        
        cin >> K;
        //Input Parsing End
        int visited[M][O];
        int Branch[M][O];
        for (int p=0; p<M; ++p){
            for (int q=0; q<O; ++q){
                if(laby[p][q]=='X'){
                    visited[p][q]=2;
                }
                else visited[p][q]=0;
            }            
        }
        
        //Array with dots
        stack<Cord> dfs;
        int Count=0;
        dfs.push(Herm);
        Cord cur=Herm;
        Branch[Herm.row][Herm.col] = 0;
        while ((!dfs.empty()) && (laby[dfs.top().row][dfs.top().col]!='*')){
            cur = dfs.top();
            dfs.pop();
            visited[cur.row][cur.col] = 1; 
            int Br=0;
            //cout << "Now at: " << cur.row << ", " << cur.col << endl;
            //cout << "Branch: " << Branch[cur.row][cur.col] << endl;
            //Search
            if (cur.row<(M-1) && (visited[cur.row+1][cur.col]==0)) {
                Br++;
                dfs.push({cur.row+1,cur.col});
            }
            if (cur.row>0 && (visited[cur.row-1][cur.col]==0)) {
                Br++;
                dfs.push({cur.row-1,cur.col});                
            }
            if (cur.col<(O-1) && (visited[cur.row][cur.col+1]==0)) {
                Br++;
                dfs.push({cur.row,cur.col+1});                
            }
            if (cur.col>0 && (visited[cur.row][cur.col-1]==0)) {
                Br++;
                dfs.push({cur.row,cur.col-1});                
            }
            
            if (cur.row<(M-1) && (visited[cur.row+1][cur.col]==0)) {
                if (Br>1) Branch[cur.row+1][cur.col] = Branch[cur.row][cur.col] +1;
                else Branch[cur.row+1][cur.col] = Branch[cur.row][cur.col];
            }
            if (cur.row>0 && (visited[cur.row-1][cur.col]==0)) {
                if (Br>1) Branch[cur.row-1][cur.col] = Branch[cur.row][cur.col] +1;
                else Branch[cur.row-1][cur.col] = Branch[cur.row][cur.col];                              
            }
            if (cur.col<(O-1) && (visited[cur.row][cur.col+1]==0)) {
                if (Br>1) Branch[cur.row][cur.col+1] = Branch[cur.row][cur.col] +1;
                else Branch[cur.row][cur.col+1] = Branch[cur.row][cur.col];              
            }
            if (cur.col>0 && (visited[cur.row][cur.col-1]==0)) {
                if (Br>1) Branch[cur.row][cur.col-1] = Branch[cur.row][cur.col] +1;
                else Branch[cur.row][cur.col-1] = Branch[cur.row][cur.col];         
            }              
        }
       
            //cout << "K: " << K << endl;
            //cout << "Count: " << Branch[dfs.top().row][dfs.top().col] << endl;
            if(K==Branch[dfs.top().row][dfs.top().col]) cout << "Impressed" << endl;
            else cout << "Oops!" << endl;
            for (int r=0; r<M; ++r){
                for(int s=0;s<O;++s){
                    visited[r][s]=2;
                }
            }
        
        }
    return 0;
}


