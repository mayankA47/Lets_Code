//lets implement segment tree
#include <bits/stdc++.h>
using namespace std;

void buildTree(int *tree,int index,int *a,int s,int e){
	/* Parameters-> tree - pointer to segment tree
					index - current index for segment tree
					a,s,e - array,start and end of array whose tree
					is buildTree 			*/
	//base case-leaf node
	if(s==e)
	{
		tree[index] = a[s];
		return;
	}
	int m = (s+e)/2;
	//call for left and right 
	buildTree(tree,2*index,a,s,m);
	buildTree(tree,2*index+1,a,m+1,e);
	// mark value for current index

	// here building segment tree to answer minimum query
	tree[index] = min(tree[2*index],tree[2*index+1]);
}

// for query taking start index and end index as qe & qs
// s & e are start and end index of original array
int query(int *tree,int index,int qs,int qe,int s,int e){
	//check for non overlap
	if(qs>e || qe<s)
		return INT_MAX;

	//check for complete overlap
	if(s>=qs && e<=qe)
		return tree[index];

	//hence partial overlap so call for left and right
	int m = (s+e)/2;
	int leftAns = query(tree,2*index,qs,qe,s,m);
	int rightAns = query(tree,2*index+1,qs,qe,m+1,e);

	return min(leftAns,rightAns);
}

//update for range or one element--ue & us are update start & end index
void update(int *tree,int index,int us,int ue,int increment,int s,int e){

	//check for non-overlap
	if(us>e || ue<s)
		return;

	//check if leaf node
	if(s==e)
	{
		tree[index]+=increment;
		return;
	}

	//no complete/partial check
	//direct call update for left and right parts
	int m = (s+e)/2;
	update(tree,2*index,us,ue,increment,s,m);
	update(tree,2*index+1,us,ue,increment,m+1,e);
	//update for current index
	tree[index] = min(tree[2*index],tree[2*index+1]);

}

int main(){
	int n;
	cin>>n;
	int *a = new int [n];
	for(int i=0;i<n;i++) cin>>a[i];

	//build segment tree
	int *tree = new int[4*n+10]; //4n+1 is approx size for segment tree 
	buildTree(tree,1,a,0,n-1);	

	//check the segment tree formed
/*	for(int i=1;i<20;i++)
		cout<<tree[i]<<","; */

	//query
	update(tree,1,1,1,-10,0,n-1);
	int q;
	cin>>q;
	while(q--){
		int qs,qe;
		cin>>qs>>qe;
		cout<<query(tree,1,qs,qe,0,n-1)<<endl;

	}	


	return 0;
}
/* segment tree takes O(n) for buildTree,
	O(log(n)) for query and single element update (when us==ue),
	O(n) for range update 		*/