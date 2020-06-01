/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode *c,*n,*p;
    p = n = NULL;
    c = A;
    if(A && A->left)
        n = A->left;
    else if(A && A->right)
        n = A->right;
    while(c){
        TreeLinkNode *cc = c;
        while(p && c){
            if(!n && c->left)
                n = c->left;
            if(!n && c->right)
                n = c->right;
           if(p->left && c!=p->left)
            c->next = p->left,c = c->next;
            
            if(!n && c->left)
                n = c->left;
            if(!n && c->right)
                n = c->right;
            if(p->right && c!=p->right)
            c->next = p->right,c = c->next;
            p = p->next;
        }
            p = cc;
            c = n;
            n = NULL;
    }
    
}
