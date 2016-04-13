nclude <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

class Suffix{
    public:
    int index;
    long int Sum;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Tests;
    cin >> Tests;
    for (int i=0; i<Tests; i++){
        int Size; 
        long int Input;
        cin >> Size;
        cin >> Input;
        long int Sum=0;
        long int Array[Size];
        set<long int> Sums;        
        vector<Suffix> Stree;
        set<long int> Sumset={};
        for (int j=0; j<Size; ++j){
            cin>>Array[j];
            Sum += Array[j];
            Suffix In;
            In.index = j;
            In.Sum = Sum%Input;
            Stree.push_back(In);
        }
        Sums.insert(Stree.at(0).Sum);
        long int Max=Stree.at(0).Sum;
        for (int k=1; k<Size; ++k){
            long int Mod = Stree.at(k).Sum;
                if (Stree.at(k).Sum < *Sums.rbegin()) {
                long int UB = *Sums.upper_bound(Stree.at(k).Sum);
                Mod = (Stree.at(k).Sum - UB + Input);                
                }
                Max = max(Max, Mod);
                Sums.insert(Stree.at(k).Sum);
                if(Max==Input-1) break;
        }
        cout << Max << endl;
    }
    return 0;
}


