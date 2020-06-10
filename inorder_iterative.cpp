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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur){
            //go extreme left
            while(cur){
                s.push(cur);
                cur=cur->left;
            }
            cur = s.top();
            s.pop();
            //print this
            ans.push_back(cur->val);
            //do same for right subtree of current
            cur = cur->right;
            
        }
        return ans;
        
    }
};