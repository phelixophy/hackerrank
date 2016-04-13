nclude <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        long int N;
        cin >> N;
        long long int Arr[N];
        unordered_map <long long int, long long int> umap;
        for (int j=0; j<N; ++j){
            cin >> Arr[j];
            if(umap.find(Arr[j])==umap.end()) umap[Arr[j]] = 1;
            else ++umap[Arr[j]];
        }
        long long int Sum=0;
        for (auto it=umap.begin(); it!=umap.end(); ++it){
                long long int rep = it->second;
                Sum += rep * (rep-1);
        }
        cout << Sum << endl;
    }
    return 0;
}


