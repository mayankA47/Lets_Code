// } Driver Code Ends
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(Node *p)
{
    if(p==NULL)
    return;
   // Your Code Here
   Node *parent = p;
   if(p->left){
       if(p->right)
       p->left->nextRight = p->right;
       else{
           parent = p->nextRight;
           bool ass = 0;
           while(parent && !ass){
               if(parent->left)
                p->left->nextRight = parent->left,ass=1;
                else if(parent->right)
                 p->left->nextRight = parent->right,ass=1;
                 else
                 parent = parent->nextRight;
           }
       }
   }
   if(p->right){
       parent = p->nextRight;
           bool ass = 0;
           while(parent && !ass){
               if(parent->left)
                p->right->nextRight = parent->left,ass=1;
                else if(parent->right)
                 p->right->nextRight = parent->right,ass=1;
                 else
                 parent = parent->nextRight;
           }
   }
   connect(p->left);
   connect(p->right);
}

