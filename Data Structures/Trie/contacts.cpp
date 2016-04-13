nclude <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

#define ALPH 26
#define INDEX(c) ((int)c - (int)'a')

using namespace std;
class trieNode{
    public:
    trieNode* children[ALPH];
    bool isLeaf;
    int rep;
    
    //Constructor
    trieNode(){
        isLeaf = false;
        rep = 0;
        for (int i = 0; i < ALPH; i++) children[i] = NULL;
    }
    
};

void insert(trieNode* root, const string& a){

    int l = a.length();
    int index;
    trieNode* cur = root;
    
    for (int i=0; i<l; ++i){
        index = INDEX(a[i]);
        if (!cur->children[index]){
            trieNode* make = new trieNode;
            cur->children[index] = make;
            cur->children[index]->rep =1; 
        }
        else ++cur->children[index]->rep;
        cur=cur->children[index];
    }
    cur->isLeaf=true;
};

int find(trieNode* root, const string& a){

    int l = a.length();
    int index;
    trieNode* cur = root;
    int count = 0;    
    
    for (int i=0; i<l; ++i){
        index = INDEX(a[i]);
        if (cur->children[index]){
            if (i==l-1){
                return cur->children[index]->rep;
            }
            cur=cur->children[index];               
        }
        else break;
    }
    return count;
};

int main() {
    int T;
    cin >> T;
    trieNode* root = new trieNode;    
    while (T--){
        
        string a, b;
        cin >> a >> b;
        
        if (a=="add"){
            insert(root, b);
        }
        
        else if(a=="find"){
            cout << find (root, b) << endl;
        }
    }
    return 0;
}


