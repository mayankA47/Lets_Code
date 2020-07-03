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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *current = root;
        int ans = 0;
        //Inorder Morris Traversal
        while(current){
            //No left subtree --> simply move to right
            if(current->left==NULL){
                k--;
                if(k==0)
                    ans = current->val;
                current = current->right;
            }
            //Otherwie find inorder predecessor and establish link so that we may come back later
            else{
                TreeNode *pre = current->left;
                while(pre->right!=NULL && pre->right!=current){
                    pre = pre->right;
                }
                //Establish link and go left
                if(pre->right==NULL){
                    pre->right = current;
                    current = current->left;
                }
                //Left subtree already visited --> destroy link and move right
                else{
                    k--;
                    if(k==0)
                        ans = current->val;
                    pre->right = NULL;
                    current = current->right;
                }
            }
        }
        return ans;
        
    }
};