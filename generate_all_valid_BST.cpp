/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<TreeNode*> solve(int s,int e){
    vector<TreeNode*> ans;
    if(s>e)
    {
        ans.push_back(NULL);
        return ans;
    }
    for(int i=s;i<=e;i++){
        
        vector<TreeNode*> l = solve(s,i-1);
        vector<TreeNode*> r = solve(i+1,e);
        for(auto le:l){
            for(auto ri:r){
                TreeNode* root = new TreeNode(i);
                root->left = le;
                root->right = ri;
                ans.push_back(root);
            }
        }
    }
    return ans;
}
vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return solve(1,A);
    
    
}
