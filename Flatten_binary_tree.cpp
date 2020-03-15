/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     pair<TreeNode*,TreeNode*> help(TreeNode* root){
         // to maintain the results of children and current node
         pair<TreeNode*,TreeNode*> p,l,r;
         // check whether call is made to children
         bool cl,cr;
         cl=cr=0;
         p.first=p.second=NULL;
         if(root==NULL)
             return p;
         p.first=root;
         p.second=root;
         if(root->left)
        l = help(root->left),cl=1;
        if(root->right)
            r = help(root->right),cr=1;
         if(cl)
         {
             root->right = l.first;
             root->left=NULL;
             p.second = l.second;
         }
         if(cr){
             p.second->right = r.first;
             p.second->left=NULL;
             p.second =  r.second;
             
         }
         return p;
         
             
                     
     }
    void flatten(TreeNode* root) {
    pair<TreeNode*,TreeNode*> p=    help(root);
        
    }
};