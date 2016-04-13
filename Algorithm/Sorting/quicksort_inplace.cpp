nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(
                vector<int> &arr,
                int low,
                int high
                ){
    if(high<=low) return;
    //cout << "low: " << low << " high: " << high << endl;
    int pivot = arr.at(high);
    int i = low;
    int j = low;
    int temp;
    while (j<high){
        //cout << "i: " << i << " j: " << j << " cur: " << arr.at(j) << endl;
        if(arr.at(j)<=pivot) {
            temp = arr.at(i);
            arr.at(i) = arr.at(j);
            arr.at(j) = temp;
            ++i;            
        }
        ++j;
    }
            temp = arr.at(i);
            arr.at(i) = pivot;
            arr.at(high) = temp;
    for (int k=0; k<arr.size(); k++){
        cout << arr.at(k) << " ";
    }
    cout << endl;
    quick_sort(arr, low, i-1);
    quick_sort(arr, i+1, high);
    return;
};


int main() {
    int N;
    vector<int> arr;
    cin >> N;
    for (int i=0; i<N; ++i){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    quick_sort(arr, 0, N-1);
    
    return 0;
}

