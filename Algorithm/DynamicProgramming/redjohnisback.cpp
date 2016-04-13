nclude <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long fac (int N){
    unsigned long long fact=1;
    if (N==0) return fact;
      for (int f=N; f>0; --f){
            fact *= f;
       } 
    return fact;
}



int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        int N;
        cin >> N;
        unsigned long long M=0;
        long long Seq[N+1];
        Seq[0]=1;
        Seq[1]=1;
        Seq[2]=1;
        Seq[3]=1;
        
        for (int j=4; j<=N; ++j){
            Seq[j]=Seq[j-1]+Seq[j-4];
        }
        M = Seq[N];
        bool prime [M+1];
        memset(prime, true, sizeof(prime));            
        for (int q=2; q<M; ++q){
            if (prime[q]==true){
                for(int p=2*q; p<=M; p=p+q){
                    prime[p]=false;
                }
            }
        }
        int count=0;
        for (int c=2; c<=M; ++c){
            if (prime[c]) count++;
        }
        cout << count << endl;
    }
    
    
    return 0;
}


