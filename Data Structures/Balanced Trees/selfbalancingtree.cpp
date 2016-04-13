truct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(struct node *N)
{
    if (N == NULL)
        return -1;
    return N->ht;
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return -1;
    return height(N->left) - height(N->right);
}

node * rotateRight(node* x){
    node* a = x->left;
    node* b = a->right;
    
    a->right = x;
    x->left = b;
    
    x->ht = max(height(x->right), height(x->left)) +1;
    a->ht = max(height(a->right), height(a->left)) +1;    
    return a;
}

node * rotateLeft(node* y){
    node* c = y->right;
    node* d = c->left;
    
    c->left = y;
    y->right = d;

    y->ht = max(height(y->right), height(y->left)) +1;   
    c->ht = max(height(c->right), height(c->left)) +1;  
    return c;
}

node * insert(node * root,int val)
{
    if (root==NULL) {
        node * inserted = new node;
        inserted->val = val;
        inserted->right=NULL;
        inserted->left=NULL;
        inserted->ht = 0;
        return inserted;
    }

   if (val < root->val) {
        root->left = insert (root->left, val);     
   }
   else {
        root->right = insert (root->right, val);           
   }
    
   root->ht= max(height(root->right), height(root->left)) + 1;
   
   int balance= getBalance(root);
   
   //left-left
   if (balance > 1 && (val < root->left->val)){
       return rotateRight(root);
   }
   // right-right
   if (balance < -1 && (val > root->right->val)){
       return rotateLeft(root);
   }    
   // left-right
   if (balance > 1 && (val > root->left->val)){
       root->left = rotateLeft(root->left);
       return rotateRight(root);
   }    
   // right-left
   if (balance < -1 && (val < root->right->val)){
       root->right = rotateRight(root->right);
       return rotateLeft(root);
   }       
   
   return root;
    
}


