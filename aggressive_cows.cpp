#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
bool isvalid(int m,ll *a,int n,int c){
    int i=1;
    int last = 0;
    c--;
    while(i<n){
        if(a[i]-a[last]>=m)
            last=i,c--;
        if(c==0)
            break;
        i++;
    }
    if(c<=0)
        return true;
    else
        return false;

}
int main() {
    int t;
    cin>>t;
    while(t--){
 int n,c;
 cin>>n>>c;
 ll *a = new ll[n];
 for(int i=0;i<n;i++)
    cin>>a[i];
sort(a,a+n);
if(c>2){
    ll l,h,m;
    l = a[0];
    h = a[n-1];
    ll ans = -1;
    while(l<=h){
        m = (l+h)/2;
        if(isvalid(m,a,n,c))
            ans = m, l = m+1;
        else
            h = m-1;
    }
    cout<<ans<<endl;
}
else
cout<<a[n-1]-a[0]<<endl;
delete []a;
}
return 0;
}
