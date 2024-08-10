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
class BSTIterator {
public:
    /*
    Use a stack to keep all nodes of interest. 
    Idea is in order traversal. For a top element in stack, it's sure that 
    left subtree is already covered. Now use current (top) and then right becomes 
    the node of interest.

    For next():
        Return the element with stack top. Also need to update 
        the stack, go to top's right and keep on adding left to stack.

    */
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root -> left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        TreeNode* cur = top -> right;

        while (cur) {
            s.push(cur);
            cur = cur -> left;
        }

        return top -> val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */