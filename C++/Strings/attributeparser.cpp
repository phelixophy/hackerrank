nclude <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

struct Tag{
    string Name;
    Tag* Parent;
    set<Tag*> Children;
    unordered_map<string, string> Attr;
};

string Token(string Input){
  string delim="\"=<>";  
  //cout << "Tokenizer: " << Input << endl;
  int Start = Input.find_first_not_of(delim);
  int End = Input.find_last_not_of(delim);
  return Input.substr(Start, End-Start+1);
};

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();
    Tag* Root = new Tag;
    Tag* Cur=Root;
    
    //Lines
    while(N--){
        string Line, Word;
        getline(cin, Line);
        //cout << "Input: " <<  Line << endl;
        istringstream iss(Line);
        
        //Open
        string Name;
        string Attr;        
        iss >> Word;           
        if (Word.find("/")==string::npos) {
            //Tag Name
            Name = Token(Word);
            cout << Name << endl;                    
            Tag* T = new Tag;
            T->Name = Name;
            T->Parent = Cur;
            Cur->Children.insert(T);
            Cur = T;
            string AttrName, AttrValue;
            //Attribute Name and Values
            while (iss){
                iss >> AttrName;
                iss.ignore(200, '=');
                iss >> AttrValue;
                Cur->Attr[Token(AttrName)]=Token(AttrValue);
                //cout << "Attr " << Token(AttrName) << " " << Token(AttrValue) << endl;
            }
            
        }
        //Close
        else {
            Name = Word.substr(Word.find_first_of("/")+1);                  
            Cur = Cur->Parent;       
            continue;
        }   
    }

    //Queries
    while (Q--){
        string Query;
        getline(cin, Query);
        while (){
            
        }
        
        
        
    }
    return 0;
}


