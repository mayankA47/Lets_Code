/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   
    Node* copyRandomList(Node* head) {
    if(!head)
        return head;
    // create new nodes
    Node *ptr = head;
    while(ptr){
        Node *tmp = new Node(ptr->val);
        tmp->next = ptr->next;
        ptr->next = tmp;
        ptr = tmp->next;
    }
    // map random pointer
    ptr = head;
    while(ptr){
        Node *tmp = ptr->next;
        if(ptr->random)
            tmp->random = ptr->random->next;
        ptr = tmp->next;
    }
    //separate
    ptr = head;
    Node *clone = head->next;
    while(ptr!=NULL){
        Node *tmp = ptr->next;
        ptr->next = tmp->next;
        ptr = tmp->next;
        if(ptr)
            tmp->next = ptr->next;
        else
            tmp->next = NULL;
    }
    return clone;
    }
};
