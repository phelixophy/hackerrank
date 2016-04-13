nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    cin >> M;
    vector<int>* mvec = new vector<int>;
    for (int i=0; i<M; ++i){
        int K;
        cin >> K;
        mvec->push_back(K);
    }
    sort(mvec->begin(), mvec->end());
    long long int table [N+1][M];
    for (int i=0; i<M; ++i){
        table[0][i] = 1;
    }
    long long int x, y;
    for (int j=1; j<N+1; ++j){
        for (int k=0; k<M; ++k){
            //including mvec->at(M)
            x = (j>=mvec->at(k))? table[j-(mvec->at(k))][k] : 0;
            //otherwise
            y = (k>0)? table[j][k-1] : 0;
            table[j][k] = x + y;
            //cout << "j: " << j << " k: " << mvec->at(k) << endl;
            //cout << "x: " << x << " y: " << y << endl;
        }
    }
    cout << table[N][M-1] << endl;
    return 0;
}


