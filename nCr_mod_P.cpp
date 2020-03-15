#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define inf 100000
#define mod 998244353 
using namespace std;
ll fact[200005];
ll mul(ll a,ll b){
    return ((a%mod)*(b%mod))%mod;
}
void factorial(){
    fact[0]=1;
    for(ll i=1;i<=200001;i++)
        fact[i] = mul(fact[i-1],i);
}
ll power(ll a,ll b){
    if(b==0)
        return 1;
    ll ans = power(a,b/2);
    if(b%2)
        return mul(a,mul(ans,ans));
    return mul(ans,ans);
}
ll inv(ll a){
    // a^-1%P = a^(P-2) when P is prime
    return power(a,mod-2);
}
ll c(ll n,ll r){
    return mul(fact[n],inv(mul(fact[r],fact[n-r])));
}

int main(int argc, char const *argv[])
{
    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    factorial();
    if(n<=2)
        cout<<0;
    else{
        ll ans = mul(mul(c(m,n-1),n-2),power(2,n-3));
        cout<<ans;
    }

    return 0;
}