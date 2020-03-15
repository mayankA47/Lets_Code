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
    
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        //preorder is used - root--root->left--root->right
        flatten(root->left);
        flatten(root->right);
        TreeNode* ptr = root->left;
        if(ptr){
        while(ptr->right)
            ptr = ptr->right;
        ptr->right = root->right;
        root->right = root->left;
        root->left=NULL;
        }
        return;
    
        
        
    }
};