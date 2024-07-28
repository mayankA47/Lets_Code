//Pairing Problem Hackerblock
#include<bits/stdc++.h>
using namespace std;
struct dsu
{
	vector<int> parent,size;
	//initialise
	int total_components;
	void init(int n)
	{
		parent.resize(n);
		size.resize(n);
		for(int h=0;h<n;h++)
		{
			parent[h]=h;
		}
		for(int h=0;h<n;h++)
		{
			size[h]=1;
		}
		total_components=n;
	}
	int get_superparent(int x)
	{
		if(parent[x]==x)
			return x;
		//Path Compression
		return parent[x]=get_superparent(parent[x]);
	}
	void unite(int x,int y)//union is a keyword
	{
		int superparent_x=get_superparent(x);
		int superparent_y=get_superparent(y);
		//While merging,Size of SuperParent = size[current] + size[Parent].
		//We will make size of current = 0.
		if(superparent_x!=superparent_y)
		{
			parent[superparent_x]=superparent_y;
			total_components--;//While merging 2 components,one total_component is reduced. 
			size[superparent_y]+=size[superparent_x];
			size[superparent_x]=0;
		}
	}
}G;
int main()
{

	int n,m;
	cin>>n>>m;
	G.init(n);
	for(int y=0;y<m;y++)
	{
		int i,j;
		cin>>i>>j;
		G.unite(i,j);
	}
	//Now,All elements are in their connected components.
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		int superparent_i=G.get_superparent(i);
		ans+=(n-G.size[superparent_i]);
	}
	cout<<ans/2<<endl;
}
