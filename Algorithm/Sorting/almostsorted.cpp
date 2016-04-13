nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    int Arr[N];
    for (int i=0; i<N; ++i){
        cin >> Arr[i];
    }
    vector<int> dec;
    for (int j=0; j<N-1; ++j){
        if (Arr[j] > Arr[j+1]){
                if (dec.size() <=2 || dec.back()==j-1) dec.push_back(j);
                else {
                    cout << "no" << endl;
                    return 0;
                }
            }
    }   
    if (dec.empty()) {
        cout << "yes" << endl;
        return 0;
    }
    else {
        int left = dec.front();
        int right = dec.back()+1;
        int lleft = (left==0)? 0 : Arr[left-1];
        int rright = (right==N-1)? 10000001 : Arr[right+1];
        //cout << "lleft: " << lleft << " rright: " << rright << endl;
        if ((lleft <= Arr[right]) && (rright >= Arr[left])){
            cout << "yes" << endl;
            if (dec.size()<=2) cout << "swap "; 
            else cout << "reverse ";            
            cout << left+1 << " " << right+1 << endl;
        }
        else cout << "no" << endl;
    }
    
    return 0;
}


