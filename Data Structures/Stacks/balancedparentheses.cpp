nclude <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    stack<char> st;
    int N;
    cin >> N;
    for (int i=0; i<N; ++i){
        bool fail;
        string str;
        cin >> str;
        fail = false;
        if (str.length()%2) {
            fail = true;
        }
        else if (!fail){
            for (int j=0; j<str.length(); ++j){
                if (str[j]=='{' || str[j]=='[' || str[j]=='('){
                    st.push(str[j]);
                }
                else{
                    if (st.empty()) {
                        fail =true;
                        break;
                    }
                    else {
                      if ((st.top()== '(' && str[j]==')') || (st.top()=='[' && str[j]==']') || (st.top()=='{' && str[j]=='}')) {
                        st.pop();
                        continue;
                      }
                      else {
                        fail = true;
                        break;
                      }                              
                    }
                }   
            }
        }
        if (!st.empty()) fail = true;
        while (!st.empty()){
            st.pop();
        }
        str.clear();
        if (fail) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}


