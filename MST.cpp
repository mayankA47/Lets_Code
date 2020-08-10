//HARE KRISHNA HARE RAM
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
class edge{
public:
    int u,v,w;
    edge(int s,int e,int d){
        u = s;
        v = e;
        w = d;
    }
};
struct compare
{
    bool operator()(edge const &a,edge const &b){
        return a.w>b.w;
    }
};
class DSU{
public:
    int *par,*sz;
    DSU(int n){
        par = new int[n];
        sz = new int[n];
        for(int i=0;i<n;i++)
            par[i]=i,sz[i]=1;
    }
    int getsuperparent(int x){
        //path compression
        if(par[x]!=x)
            par[x] = getsuperparent(par[x]);
        return par[x];
    }
    void unite(int a,int b){
        int superparenta = getsuperparent(a);
        int superparentb = getsuperparent(b);
        //union by rank
        if(sz[a]<sz[b]){
            par[superparenta] = superparentb;
            sz[superparentb] += sz[superparenta];
            sz[superparenta] = 0;
        }
        else{
            par[superparentb] = superparenta;
            sz[superparenta] += sz[superparentb];
            sz[superparentb] = 0;
        }
    }

};
int32_t main()
{
    c_p_c();
    
    int n,m;
    cin>>n>>m;
    DSU g(n);
    priority_queue<edge,vector<edge>,compare> pq;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge E(a,b,c);
        pq.push(E);

    }
    int ans = 0;
    while(!pq.empty()){
        edge a = pq.top();
        pq.pop();
        //check cycle
        if(g.getsuperparent(a.u)==g.getsuperparent(a.v))
            continue;
        ans += a.w;
        g.unite(a.u,a.v);
    }
    cout<<ans;


    
 cerr << "proc time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
    return 0;
}
