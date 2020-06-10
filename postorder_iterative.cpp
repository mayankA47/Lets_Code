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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1,s2;
        TreeNode* cur;
        if(root)
            s1.push(root);
        while(!s1.empty()){
            cur = s1.top();
            s2.push(cur);
            s1.pop();
            if(cur->left)
                s1.push(cur->left);
            if(cur->right)
                s1.push(cur->right);
        }
        vector<int> ans;
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
        
    }
};