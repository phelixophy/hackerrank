nclude <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int N;
    bool visited;
    bool processed;
    int Childs; //includes itself
    vector<int> children;
};

int main() {
    int N, M;
    cin >> N;
    cin >> M;
    Node tree[N];
    
    for (int i=0; i<M; ++i){
        int A, B;
        cin >> A;
        cin >> B;
        //cout << A << " " << B << endl;
        tree[A-1].N = A-1;
        tree[A-1].visited = false;        
        tree[A-1].processed = false;          
        tree[A-1].Childs = 1;       
        
        tree[B-1].N = B-1;
        tree[B-1].visited = false;        
        tree[B-1].processed = false;          
        tree[B-1].Childs = 1;      
        
        tree[B-1].children.push_back(A-1);
        
        
    }
    //cout << tree[7].children.at(0) << endl;
    int Cut=0;
    stack<Node> st;
    st.push(tree[0]);
    int depth=0;
    while(!st.empty()){
        Node cur = st.top();
        
        if (tree[cur.N].visited){
            for (int q=0; q<tree[cur.N].children.size(); ++q){
                tree[cur.N].Childs+= tree[tree[cur.N].children.at(q)].Childs;
                if(tree[tree[cur.N].children.at(q)].Childs%2==0) ++Cut;
            }
            tree[cur.N].processed=true;
            st.pop();
            //cout << cur.N << " has " <<  tree[cur.N].Childs << endl;
        }
        
        tree[cur.N].visited=true;         
        for (int k=0; k<tree[cur.N].children.size(); ++k){
            int ichild = tree[cur.N].children.at(k);
            if (!tree[ichild].visited) {
                //cout << "pushed " << ichild << endl;
                st.push(tree[ichild]);
            }
        }
    }
    cout << Cut << endl;
    return 0;
}


