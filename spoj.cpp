#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define inf 100000
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int a[n+1],b[m+1];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int j=0;j<m;j++)
		cin>>b[j];
	b[m]=a[n]=0;
	int lx[44000]={0};
	int ly[44000]={0};
	bool vis[44000]={0};
	set<int> sx,sy;
	for(int i=0;i<n;i++){
		if(a[i]&&!vis[i])
		{
			vis[i]=1;
			int len=0;
			int j=i;
			while(a[j]&&j<n)
				len++,vis[j++]=1;
			lx[len]++;
			sx.insert(len);
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<m;i++){
		if(b[i]&&!vis[i])
		{
			vis[i]=1;
			int len=0;
			int j=i;
			while(b[j]&&j<m)
				len++,vis[j++]=1;
			ly[len]++;
			sy.insert(len);
		}
	}

	ll ans = 0;
	for(auto i:sx){
		ll cur=0;
		for(auto j:sy){
			cur=0;
			for(int p=1;p<=sqrt(k);p++){
				if(k%p==0){
					if(p<=i && (k/p)<=j)
						cur += (i-p+1)*(j-(k/p)+1)*ly[j];
					if(p<=j && (k/p)<=i)
						cur += (j-p+1)*(i-(k/p)+1)*ly[j];

				}
			}
			ans += cur*lx[i];
		}
		
	}
	cout<<ans;

	return 0;
}