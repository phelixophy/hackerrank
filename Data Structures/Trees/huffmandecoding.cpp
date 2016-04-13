tructure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    int len = s.length();
    char* str = new char[len+1];
    strcpy (str, s.c_str());
    node* cur = new node;
    cur = root;
    int i=0;
    while(str[i]!='\0'){
        cur = (str[i]=='0')? cur->left : cur->right; 
        if (cur->data!='\0') {
            cout << cur->data;
            cur = root;
        }
        ++i;
    }
}


