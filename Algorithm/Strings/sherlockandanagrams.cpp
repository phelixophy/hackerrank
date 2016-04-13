nclude <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; ++i){
        string s;
        cin >> s;
        int len = s.length();
        //N sized substring
        int sum = 0;
        for (int j=1; j<=len; ++j){
            int subTotal=0;
            //look thru string
            map<string, int> mps;
            for(int k=0; k<len-j+1; ++k){
                string sub = s.substr(k, j);
                sort(sub.begin(), sub.end());
                //cout << "sub: " << sub << endl;
                if (mps.find(sub)==mps.end()) mps[sub] = 1;
                else mps[sub]+=1;
            }
            for(auto it=mps.begin(); it!=mps.end(); it++){
                subTotal += (it->second * (it->second-1))/2;
                //cout << "key: " << it->first << " value: " << it->second << endl;
            }
            sum += subTotal;
            mps.clear();
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}


