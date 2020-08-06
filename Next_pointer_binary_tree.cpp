/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode *c,*n,*p;
    p = n = NULL;
    c = A;
    if(A && A->left)
        n = A->left;
    else if(A && A->right)
        n = A->right;
    while(c){
        TreeLinkNode *cc = c;
        while(p && c){
            if(!n && c->left)
                n = c->left;
            if(!n && c->right)
                n = c->right;
           if(p->left && c!=p->left)
            c->next = p->left,c = c->next;
            
            if(!n && c->left)
                n = c->left;
            if(!n && c->right)
                n = c->right;
            if(p->right && c!=p->right)
            c->next = p->right,c = c->next;
            p = p->next;
        }
            p = cc;
            c = n;
            n = NULL;
    }
    
}
// Another easy pyhton sol - Thanks to LeetCode
class Solution:
    
    def processChild(self, childNode, prev, leftmost):
        if childNode:
            
            # If the "prev" pointer is alread set i.e. if we
            # already found atleast one node on the next level,
            # setup its next pointer
            if prev:
                prev.next = childNode
            else:    
                # Else it means this child node is the first node
                # we have encountered on the next level, so, we
                # set the leftmost pointer
                leftmost = childNode
            prev = childNode 
        return prev, leftmost
    
    def connect(self, root: 'Node') -> 'Node':
        
        if not root:
            return root
        
        # The root node is the only node on the first level
        # and hence its the leftmost node for that level
        leftmost = root
        
        # We have no idea about the structure of the tree,
        # so, we keep going until we do find the last level.
        # The nodes on the last level won't have any children
        while leftmost:
            
            # "prev" tracks the latest node on the "next" level
            # while "curr" tracks the latest node on the current
            # level.
            prev, curr = None, leftmost
            
            # We reset this so that we can re-assign it to the leftmost
            # node of the next level. Also, if there isn't one, this
            # would help break us out of the outermost loop.
            leftmost = None
            
            # Iterate on the nodes in the current level using
            # the next pointers already established.
            while curr:
                
                # Process both the children and update the prev
                # and leftmost pointers as necessary.
                prev, leftmost = self.processChild(curr.left, prev, leftmost)
                prev, leftmost = self.processChild(curr.right, prev, leftmost)
                
                # Move onto the next node.
                curr = curr.next
                
        return root 
