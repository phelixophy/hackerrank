nclude <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Coord{
    int row;
    int col;
};

int DFS(Coord in,
        int visited[10][10],
        int graph[10][10],
        int Row,
        int Col) {
            //cout << "Now at: " << in.row << ", " << in.col << endl;
            visited[in.row][in.col]=1;
            int Sum =0;
                //Vertical and Horizontal
                for (int i=-1; i<2; ++i){
                    for(int j=-1; j<2; ++j){
                       if(i==0 && j==0) continue;
                       else if (in.row+i <Row && in.row+i >-1 && in.col+j < Col && in.col+j >-1){
                       if(visited[in.row+i][in.col+j]==0 && graph[in.row+i][in.col+j]==1) Sum+=DFS({in.row+i, in.col+j}, visited, graph, Row, Col); 
                       }
                    }
                }
            if(Sum==0) return 1;
            else return Sum+1;
            return 0;
};

int main() {
    int M, N;
    cin >> M;
    cin >> N;
    int graph[10][10];
    int visited[10][10];
    for (int i=0; i<M; ++i){
        for (int j=0; j<N; ++j){
            cin >> graph[i][j];
            visited [i][j]=0;
        } 
    }
    
    int Max = 0;
    for (int m=0; m<M; ++m){
        for (int n=0; n<N; ++n){
            if (graph[m][n]==1 && visited[m][n]==0) {
                Coord in;
                in.row = m;
                in.col = n;
                Max= max(DFS(in, visited, graph, M, N), Max); 
            }
        } 
    }
    
    cout << Max << endl;;
    
    return 0;
}


