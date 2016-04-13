nclude <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    for (int k=0; k<N; ++k){
    string s;
    cin >> s;
        bool found = false;
        int i=0;
        int p,q;
        for (; i<s.length()-1; ++i){
               int history = INT_MAX;
               for (int j = i+1; j<s.length(); ++j) {
                   if (s[i]<s[j] && s[j]<history){
                       history=min(history, (int) s[j]);
                       //cout << "i: " << s[i]  << " j: " << s[j] << endl;
                       p=i;
                       q=j;
                       found = true;
                   }
               }
        }        
        //cout << "p is " << p << endl;
        //cout << "q is " << q << endl;
        if (found) {
            char temp=s[p];
            s[p] = s[q];
            s[q] = temp;            
            string s1, s2;
            s1 = s.substr(0, p+1);
            s2 = s.substr(p+1, s.length()-p-1);
            sort(s2.begin(), s2.end());
            cout << s1+s2 << endl;
        }
        else cout << "no answer" << endl;
        
    }
    return 0;
}


