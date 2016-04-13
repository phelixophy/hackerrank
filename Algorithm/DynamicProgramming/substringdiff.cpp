nclude <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int SubDiff (const string& a, const string& b, int S){
    int Ans=0;
    int Offset=0;
    vector<int> count;
    for (; Offset<a.length(); ++Offset){
        count.clear();
        for (int i=0; i<b.length() && Offset+i < a.length(); ++i){
            if (a[Offset+i]!=b[i]) count.push_back(1);
            else count.push_back(0);
        }
        int Start=0;
        int Count=0;
        for (int k=0; k<count.size(); ++k){
            Count += count[k];
            for (; Count>S; ++Start) Count-= count[Start];
            Ans = max (Ans, k-Start+1);
        }
    }
    return Ans;
};

int main() {
    int T;
    cin >> T;
    while (T--){
       int S;
       cin >> S;
       string a,b;
       cin >> a >> b;
       cout << max(SubDiff(a,b,S), SubDiff(b,a,S)) << endl;
    }
    return 0;
}


