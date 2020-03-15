#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define inf 100000
#define mod 998244353 
using namespace std;
    int n,h,l,r;
    int dp[2002][2002];
int solve(int *a,int i,int t){
    if(i==n)
        return 0;
    if(dp[i][t]!=-1)
        return dp[i][t];
    int a1 = (t+a[i])%h;
    
    int a2 = (t+a[i]-1)%h;
    
 //   cout<<"check for "<<a1<<","<<a2<<endl;
    int q1,q2;
    q1=q2=0;
    if(l<=a1 && r>=a1)
        q1 = 1+solve(a,i+1,a1);
    else
        q1 = solve(a,i+1,a1);

    if(l<=a2 && r>=a2)
        q2 = 1+solve(a,i+1,a2);
    else
        q2 = solve(a,i+1,a2);
    return dp[i][t] = max(q1,q2);

}
int main(int argc, char const *argv[])
{
    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
   
    cin>>n>>h>>l>>r;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(a,0,0);
    return 0;
}