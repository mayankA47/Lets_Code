/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
    if(head==NULL)
    return;
     //check whether cycle exists
     Node *slow,*fast;
     slow=head;
     fast=head;
     bool cyclic=false;
     while(fast){
        if(fast->next)
        fast=fast->next->next;
        else
        break;
        slow=slow->next;
        if(slow==fast){
            cyclic=true;
            break;
        }
     }
     if(!cyclic)
     return;
     slow=head;
     Node *ptr=fast;
     while(slow!=fast){
         slow=slow->next;
         ptr=fast;
         fast=fast->next;
     }
     ptr->next=NULL;
     
}