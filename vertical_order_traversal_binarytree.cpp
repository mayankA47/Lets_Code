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
    map<int,vector<pair<int,int>>> m;
    void helper(TreeNode *root,int l,int d){
        if(!root)
            return;
        m[l].push_back({d,root->val});
        helper(root->left,l-1,d+1);
        helper(root->right,l+1,d+1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        m.clear();
        helper(root,0,0);
        vector<vector<int>> ans;
        for(auto i:m){
           sort(i.second.begin(),i.second.end());
            vector<int> temp;
            for(auto j:i.second)
                temp.push_back(j.second);
            ans.push_back(temp);
        }
        return ans;
    }
};