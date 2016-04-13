nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
            
int main() {
    int a, n, size;
    long long int subProfit;
    long long int Profit;
    cin >> a;
    for (int i=0; i<a; ++i){
        vector<long long int> price;
        cin >> n;
        for (int j=0; j<n; ++j){
        int k;
        cin >> k;
        price.push_back(k);
        }
        
        Profit=0;        
        subProfit = 0;
        long long int maxPrice = price.at(price.size()-1);
            for(int q=price.size()-1; q >= 0; --q){
                if (price.at(q) > maxPrice) {
                    maxPrice = price.at(q);
                    subProfit = 0;
                }
                else subProfit = maxPrice - price.at(q);
                                //cout << "buy: " << price.at(q) << "sell: " << maxPrice << "\n";
                Profit += subProfit;
            }
        cout << Profit << "\n";
        price.clear();
    }
    return 0;
}


