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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head,*ptr,*ans;
        head=ans=NULL;
       
        int cur = INT_MAX;
        int cnt = 0;
        while(cnt<lists.size()){
            cnt=0;
            cur = INT_MAX;
            ptr = NULL;
            //get next node
            for(auto i:lists){
                if(i){
                    if(i->val < cur)
                        cur = i->val,ptr = i;
                    
                }
                else
                    cnt++;
            }
            //increment that node
            if(ptr)
            for(int i=0;i<lists.size();i++){
                if(ptr==lists[i]){
                    lists[i] = lists[i]->next;
                    break;
                }
            }
            //add to answer
            if(head==NULL)
                head = ptr,ans= ptr;
            else
                head->next = ptr,head = head->next;
                
        }
        return ans;
        
    }
};