/*This is a function problem.You only need to complete the function given below*/
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    if(head==NULL)
    return -1;
    Node *slow,*fast;
    slow=head;
    fast=head->next;
    while(fast){
        if(fast->next)
        fast=fast->next->next;
        else
        fast=NULL;
        slow=slow->next;
    }
    return slow->data;
}