nclude <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    for (int i= 0; i<n ; ++i){
        string a;
        string b;
        cin >> a;
        cin >> b;
        set<char> aset;
        bool found = false;
        for (int j=0; j< a.length(); ++j){
            aset.insert(a[j]);
        }
        for (int k=0; k< b.length(); ++k){
            if (aset.find(b[k]) != aset.end()) {
                found = true;
            }
        }
            if (found) cout << "YES" << "\n";
            else cout << "NO" << "\n";
    }
    return 0;
}

