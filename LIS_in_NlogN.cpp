#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long int 
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             9e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define from(i,n)       for(int i=0;i<(int)n;i++)
#define from_j(i,j,n)   for(int i=j;i<(int)n;i++)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    c_p_c();
   
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
    cin>>a[i];
/* the idea is that let for i and j 
      (j<i) and a[j]>a[i] but dp[j]<dp[i]
      then jth index is of no use as it is always better to choose
      ith index for upcoming elements

      we use some data-structure maintaining this relation:
       a[i]< a[i+1]< a[i+2]....
      dp[i]<dp[i+1]<dp[i+2]....

      where dp[i] denotes LIS length ending at a[i].

*/
   int dp[n];
   dp[0]=1;
   int ans = 1;
   map<int,int> m;
   m[a[0]] = 1;

   for(int i=1;i<n;i++){
      // initailize 
      dp[i] = 1;

      //search for smaller element
      auto it = m.lower_bound(a[i]);
      if(it!=m.begin()){ // if smaller exists

        it--;  // smaller element will be previous as we use lowerbound
        dp[i] += it->second;  // update DP
      }

      it = m.lower_bound(a[i]);  // its time to delete those elements where element is large but its DP is small
      while(it!=m.end() && it->second<=dp[i]){
         auto temp = it;
         temp++;
         m.erase(it);
         it = temp;
      }

      m[a[i]] = dp[i];  // insert current element
      ans = max(ans,dp[i]);
   }

   cout<<ans;

    return 0;
}