#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
bool canbealloc(int t,int *a,int n,int s){
    int i = 0;
    ll sum = 0;
    while(i<n){
        if(sum+a[i]>t){
            sum=a[i];
            s--;
        }
        else
            sum+=a[i];
        i++;
    }
    if(s>=0)
        return true;
    else return false;
}
int main() {
 int t;
 cin>>t;
 while(t--){
    int n,s;
    cin>>n>>s;
    int *a = new int[n];
    ll sum = 0;
    for(int i=0;i<n;i++)
        cin>>a[i],sum+=a[i];
    ll l,h,m;
    l = a[0];
    h = sum;
    ll ans = INT_MAX;
    while(l<h){
        m = (l+h)/2;
        if(canbealloc(m,a,n,s))
            h = m-1,ans = m;
        else
            l = m+1;
    }
    cout<<ans<<endl;
 }
return 0;
}
