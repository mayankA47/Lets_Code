/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // inorder encoding 
    void encoder(TreeNode *root, string &encode){
        if(!root){
            encode += "null,";
            return;
        }
        encode += to_string(root->val) + ",";
        encoder(root->left,encode);
        encoder(root->right,encode);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encode;
        encoder(root, encode);
        return encode;
    }

    TreeNode *decoder(string data,int &i){
        if(i>=data.length())
            return NULL;
        //extract current num
        //check if null
        if(data[i]=='n'){
            i+=5;
            return NULL;
        }
        // check if -ve
        int mul = 1;
        if(data[i]=='-')
            i++, mul = -1;
        string s;
        while(i<data.length() and data[i]!=',')
            s+=data[i++];
        i++;
        TreeNode *cur = new TreeNode(mul*stoi(s));
        cur->left = decoder(data,i);
        cur->right = decoder(data,i);
        return cur;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        TreeNode *root = decoder(data,start);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));