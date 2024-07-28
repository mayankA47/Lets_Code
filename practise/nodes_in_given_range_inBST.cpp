
// space O(1)
// Time O(n)

int getCountOfNode(Node *root, int l, int h)
{
   int ans = 0;
   Node *ptr = root;
   while(ptr!=NULL){
       if(ptr->data>=l && ptr->data<=h)
        ans++;
       if(ptr->data<=l)
        ptr = ptr->right;
       else if(ptr->data>h)
        ptr = ptr->left;
       else{
           if(ptr->left){
           Node *nptr = ptr->left;
           while(nptr->right!=NULL && nptr->right!=ptr)
            nptr = nptr->right;
            
           if(nptr->right==ptr){
            nptr->right = NULL;
            if(ptr->data>=l && ptr->data<=h)
                ans--;

            ptr = ptr->right;
           }
           else
            nptr->right = ptr,ptr = ptr->left;
           }
           else
            ptr = ptr->right;
       }
   }
   return ans;
}
