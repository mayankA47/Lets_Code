    #include <bits/stdc++.h>
    #define pb push_back
    #define ll long long
    #define mp make_pair
    #define ff first
    #define ss second 
    using namespace std;
     ll books,lib,days;
     ll score[100005];
     ll dscore[100005];
     vector<vector<int > > result;
     class library{
     public:
        ll n,t,m,id,bookscore;
        pair<ll,ll>  *bid;
        void init(ll a,ll b,ll c,ll d){
            n=a;
            t=b;
            m=c;
            id=d;
            bid = new pair<ll,ll>[n];
            for(int i=0;i<n;i++)
                cin>>bid[i].ss,bid[i].ff=score[bid[i].ss];
            sort(bid,bid+n);
            bookscore = getscore(0);

        }
        void printbooks(int idx){
            vector<int> ans;
           // ans.reserve(n);
            int cnt=0;
            for(int i=n-1;i>=0;i--)
            if(dscore[bid[i].ss]>0)
                result[2*idx+1].pb(bid[i].ss),dscore[bid[i].ss]=0,cnt++;
            result[2*idx].pb(cnt);
        }
        ll getscore(bool z=1){
            ll ans = 0;
            for(int i=0;i<n;i++){
                ans += score[bid[i].ss];
                if(z)
                score[bid[i].ss] = 0;
            }
            return ans;
        }
     };  
     bool mycompare(library a, library b){
        return a.bookscore > b.bookscore;
     }
     bool maxcomp(pair<ll,ll> a,pair<ll,ll> b){
        return a.ff>b.ff;
     }
    int main(int argc, char const *argv[])
    {
       
       result.reserve(200010);
        cin>>books>>lib>>days;
        for(int i=0;i<books;i++)
            cin>>score[i];
        for(int i=0;i<books;i++)
            dscore[i]=score[i];

        library libs[lib];
       // library dup[lib];
        for(int i=0;i<lib;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            libs[i].init(a,b,c,i);

        }
        sort(libs,libs + lib,mycompare);

        vector<pair<ll, int> > ans;
        ans.reserve(lib);
        for(int i=0;i<lib;i++){
            ans[i].ss = i;
            ans[i].ff = libs[i].getscore();
        }
        sort(ans.begin(),ans.end(),maxcomp);
        int libr=0;
        for(int i=0;i<lib;i++){
           // cout<<libs[i].id<<" "<<libs[i].n<<endl;
            //library temp = ans[i].ss;
            int cid = ans[i].ss;
            //cout<<libs[cid].id<<" ";
            result[2*i].pb(libs[cid].id);
            libs[cid].printbooks(i);
            if(result[2*i][1]>0)
                libr++;
        }
        cout<<libr<<endl;
        for(int i=0;i<lib;i++){
            if(result[2*i][1]>0){
                cout<<result[2*i][0]<<" "<<result[2*i][1]<<endl;
                for(int j=0;j<result[2*i+1].size();j++)
                    cout<<result[2*i+1][j]<<" ";
                cout<<endl;
            }
        }

        return 0;
    }