nclude <cmath>
#include <cstdio>
#include <deque>
#include <vector>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
static unsigned long long const F=100000000ULL;

void trim (vector<unsigned long long>& In){
    unsigned long long rem=0;
    
    for (unsigned long long& trimmed : In){
        trimmed += rem;
        rem = trimmed/F;
        trimmed %= F;
    }
    if (rem>0) In.push_back(rem); 
    while (In.back()==0){
        In.pop_back();
    }            
    
    return;
};

vector<unsigned long long> add(
                vector<unsigned long long> a,
                vector<unsigned long long> b
    ){
    int sizeA = a.size();
    int sizeB = b.size();
    int large = max(sizeA, sizeB);
    vector<unsigned long long> c (large+1);    
    for (int j=0; j<large+1; ++j) c.at(j) =0;
    
    for(int i=0; i<large; ++i){
        int A, B;
        if(i>=sizeA){
            A=0;
        }
        else A = a[i];
        
        if(i>=sizeB){
            B=0;
        }
        else B = b[i];      
        c[i+1] = (A+B+c[i])/F;        
        c[i] = (A+B+c[i])%F;
    }
    trim(c);
    return c;
};
    
vector<unsigned long long> mult(
                vector<unsigned long long> a,
                vector<unsigned long long> b
    ){
    int sizeA = a.size();
    int sizeB = b.size();
    int size = sizeA + sizeB;
    vector<unsigned long long> c (size);
    
    for (int z=0; z<size; ++z) c.at(z)=0ULL;
    //Col
    for(int i=0; i<sizeB; ++i){
        //Row 
        for (int j=0; j<sizeA; ++j){
            unsigned long long pro = (a.at(j) * b.at(i)) + c.at(i+j);
            c.at(i+j) = pro%F;
            c.at(i+j+1) += pro/F;
        }
    }               
    
    trim(c); 
    return c;
};    

void Is(vector<unsigned long long>& in, int Input){
  if (Input==0) in.push_back(0);
  else {
      while(Input>0){
          in.push_back(Input%10);
          Input = Input/10;
      }          
  }

    return;
};

int main() {
    
    int Zero, One, N;
    cin >> Zero >> One >> N;
    vector<unsigned long long> out [N];    
    
    out[0].push_back(Zero);
    out[1].push_back(One);
    vector<unsigned long long> test;
    test = mult(out[0], out[1]);      
    
    for (int i=2; i<N; ++i){
        vector<unsigned long long> test;
        test = mult(out[i-1], out[i-1]);   
        out[i] = add(test, out[i-2]); 
    }
    
    cout << out[N-1].at(out[N-1].size()-1);
    for (int j=out[N-1].size()-2; j>=0; --j) cout << setfill('0') << setw(8) << out[N-1].at(j);
    cout << endl;
    return 0;
}


