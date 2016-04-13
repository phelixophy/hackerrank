nclude <cmath>
#include <cstdio>
#include <sstream>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, Op;
    stack<int> Ops;
    stack<vector<char>> Hist;
    vector<char> Note, vec;
    cin >> N;
    for (int i=0; i<N; ++i){
        char Input;
        cin >> Op;
        string line;
        if (Op==1){
            getline(cin, line);
            istringstream iss(line);
            while(iss>>Input){
            if (Input=='\n' || Input==' ') continue;
            vec.push_back(Input);
            }     
        }

        if (Op==1){
            for (int j=0; j<vec.size(); ++j){
                //cout << "J: " << j << " Input: " << vec.at(j) << endl;
                Note.push_back(vec.at(j));
            }
            Ops.push(Op);
            Hist.push(vec);
        }
        if (Op==2){
            int Til;
            cin >> Til;
            vector<char> del;           
            for (int k=0; k<Til; ++k){
                del.push_back(Note.back());
                Note.pop_back();
            }
            Hist.push(del);            
            Ops.push(Op);
            del.clear();
        }
        if (Op==3){
            int At;
            cin >> At;
            //cout << "get: " << At << endl;
            cout << Note.at(At-1) << endl;
        }      
        if (Op==4){
            if (Ops.top()==1){
                for (int p=0; p<Hist.top().size(); ++p){
                    //cout << "Undo: " << Note.back() << endl;
                    Note.pop_back();                    
                }
            }
            if (Ops.top()==2){
               for (auto it=Hist.top().rbegin(); it!=Hist.top().rend(); ++it){
                    //cout << "Redo: " << *it << endl;
                    Note.push_back(*it);
                }
            }
            Hist.pop();
            Ops.pop();
        }
        vec.clear();
    }
    
    return 0;
}


