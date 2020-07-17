//IN THE NAME OF KRISHNA
#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int              long long 
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
#define ALL(a)          a.begin(),a.end()
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
 
vi createSubsetsum(vi &v){
    int n = v.size();
    vi ans;
  //  cout<<n<<endl;
    for(int i=0;i<(1LL<<n);i++){

        int sum = 0;
        int j = 0;
        int mask = i;
        while(mask>0){
            if(mask&1)
                sum += v[j];
            mask = mask>>1;
            j++;
        }
        ans.pb(sum);
    }

    return ans;
}
int32_t main()
{
    c_p_c();
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> x,y;
    if(n<=17){
        int z;
        for(int i=0;i<n;i++){
            cin>>z;
            x.pb(z);
        }
       // cout<<x.size()<<endl;
        x = createSubsetsum(x);
        int ans = 0;
        for(int i=0;i<x.size();i++){
          //  cout<<x[i]<<",";
            if(x[i]>=a && x[i]<=b)
                ans++;
        }
       
        cout<<ans;
        return 0;
    }
    int n1,n2,z;
    n1 = n/2;
    n2 = n-n1;
    //int z;
    for(int i=0;i<n1;i++){
            cin>>z;
            x.pb(z);
        }
    for(int i=0;i<n2;i++){

            cin>>z;
            y.pb(z);
        }

    x = createSubsetsum(x);
    y = createSubsetsum(y);
    int ans = 0;
    sort(ALL(y));
    for(int i=0;i<x.size();i++){
        int l = a-x[i];
        int h = b-x[i];
        ans += (upper_bound(ALL(y),h) - lower_bound(ALL(y),l));
    }
    cout<<ans;
// cerr << "proc time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
    return 0;
}
