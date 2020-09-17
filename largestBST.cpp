/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    class info{
        public:
        int maxBST, minval, maxval;
        bool isBST;
        info(bool isBST_, int maxBST_, int minval_, int maxval_){
            isBST = isBST_;
            maxBST = maxBST_;
            minval = minval_;
            maxval = maxval_;
        }
    };
    info getinfo(TreeNode *root){
        if(root==NULL){
            return info(1, 0, INT_MAX, INT_MIN);  //NULL is a BST of size 0.
        }
        info left = getinfo(root->left);
        info right = getinfo(root->right);
        
        if(left.isBST && right.isBST){
            if(left.maxval<root->val && root->val<=right.minval){
                //current tree is also a BST
                return info(1, left.maxBST + right.maxBST + 1, left.minval==INT_MAX?root->val:left.minval, right.maxval==INT_MIN?root->val:right.maxval);
            }
        }
        //current tree is not a BST, so return max subtree size which is a BST, choose any values for maxval & minval(as they are now irrelevant).    
        return info(0, max(left.maxBST,right.maxBST), 0, 0);
    }
    int largestBSTSubtree(TreeNode* root) {
        info root_info = getinfo(root);
        return root_info.maxBST;
    }
};
