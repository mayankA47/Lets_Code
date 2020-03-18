#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node(int val){
         next=NULL; data=val;
    }
    int data;
    node* next;
};
int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	node *head,*ptr,*ahead;
	head = ahead = NULL;
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		if(head==NULL){
			head = new node(val);
			ptr = head;
		}
		else{
			ptr->next = new node(val);
			ptr = ptr->next;
		}
	}
	node *ans;

	int m;
	cin>>m;

	for(int i=0;i<m;i++){
		int val;
		cin>>val;
		if(ahead==NULL){
			ahead = new node(val);
			ptr = ahead;
		}
		else{
			ptr->next = new node(val);
			ptr = ptr->next;
		}
	}
	
	int i,j;
	i=j=0;
	ans=NULL;
	while(i<n && j<m){
		if(head->data > ahead->data){
			if(ans==NULL){
			ans = new node(ahead->data);
			ahead = ahead->next;
			ptr = ans;
		}
		else{
			ptr->next = new node(ahead->data);
			ahead = ahead->next;
			ptr = ptr->next;
		}
		j++;
		}
		else{
			if(ans==NULL){
			ans = new node(head->data);
			head = head->next;
			ptr = ans;
		}
		else{
			ptr->next = new node(head->data);
			head =head->next;
			ptr = ptr->next;
		}
		i++;
		}
	}

	while(i<n){
		ptr->next = new node(head->data);
		head = head->next;
			ptr = ptr->next;
			i++;
	}

	while(j<m){
		ptr->next = new node(ahead->data);
		ahead = ahead->next;
			ptr = ptr->next;
			j++;
	}

	while(ans){
		cout<<ans->data<<" ";
		ans= ans->next;
	}
	cout<<endl;
}
	return 0;
}