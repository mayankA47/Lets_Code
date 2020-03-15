  bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
       // return BSThelper(root,-99999999999,99999999999);
        long long ul,ll;
        ul = 99999999999;
        ll = -99999999999;
        stack<pair<TreeNode*,pair<long long,long long> > > s;
        s.push(make_pair(root,make_pair(ll,ul)));
        bool ans = true;
        while(!s.empty() && ans){
            pair<TreeNode*,pair<long long,long long> > ptr = s.top();
            s.pop();
            TreeNode *node = ptr.first;
            int curval = (ptr.first)->val;
            ll = ptr.second.first;
            ul = ptr.second.second;
            if(ll>=curval || ul<=curval)
                ans = false;
            if(node->left)
            {
                s.push(make_pair(node->left,make_pair(ll,curval)));
            }
            if(node->right)
                s.push(make_pair(node->right,make_pair(curval,ul)));
            
        }
               return ans;
        
    }