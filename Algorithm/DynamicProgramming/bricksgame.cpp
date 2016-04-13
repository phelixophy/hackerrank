nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; ++t){
        int N;
        cin >> N;
        vector<long long> vec(N);
        vector<long long> sum(N);        
        vector<long long> score(N);        
        for (int i=N-1; i>=0; --i) {
            cin >> vec[i];
        }
        sum[0] = vec[0];
        for (int k=1; k<N; ++k){
            sum[k] = sum [k-1] + vec[k];
        }
        
        score[0]=sum[0];
        score[1]=sum[1];
        score[2]=sum[2];    
        
        for(int j=3; j<N; ++j){
            long long A, B;
            score[j] = sum[j-1] - score[j-1] + vec[j];
            B= max(score[j], sum[j-2] - score[j-2] + vec[j-1] + vec[j]);
            score[j]= max(B, sum[j-3] - score[j-3] + vec[j-2] + vec[j-1] + vec[j]);
        }
        cout << score[N-1] << endl;        
    }

    
    return 0;
}


