/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    pair<Node*,Node*> getLL(Node *root){
        pair<Node*,Node*> cur;
        cur.first = cur.second = root;
        if(root->left){
            pair<Node*,Node*> l = getLL(root->left);
            cur.first = l.first;
            l.second->right = root;
            root->left = l.second;
        }
        if(root->right){
            pair<Node*,Node*> r = getLL(root->right);
            cur.second->right = r.first;
            r.first->left = cur.second;
            cur.second = r.second;
        }
        return cur;
    }
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return root;
        pair<Node*,Node*> LL = getLL(root);
        LL.second->right = LL.first;
        LL.first->left = LL.second;
        return LL.first;
    }
};
