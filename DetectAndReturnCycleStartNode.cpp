/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       if(head==NULL)
           return NULL;
        ListNode *slow,*fast;
        slow=fast=head;
        bool cycle=false;
        while(fast!=NULL){
            if(fast->next)
                fast=fast->next->next;
            else
            {
                fast=NULL;
                break;
            }
            slow=slow->next;
            if(slow==fast)
            {
                cycle=true;
                break;
            }
        }
        if(!cycle)
            return NULL;
        slow=head;
        //to break cycle, set next of previous of fast as NULL
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};