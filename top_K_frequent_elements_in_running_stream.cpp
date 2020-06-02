#include<bits/stdc++.h>
using namespace std;
struct mycmp
    {
      bool operator()(pair<int,int> a,pair<int,int> b) const{
        if(a.first!=b.first)
			return a.first>b.first;
		return a.second<b.second;
      }
      
    };
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		set<pair<int,int>,mycmp> s;
		map<int,int> m;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			// if already present, update its frequency
			if(m.count(x)){
				auto it = s.find({m[x],x});
				int val = it->second;
				int freq = ++m[val];
				s.erase(it);
				s.insert({freq,val});
			}
			// otherwise make an entry
			else{
				m[x] = 1;
				s.insert({1,x});
			}
			auto it = s.begin();
			int el = k;
			while(it!=s.end() && el>0){
				cout<<it->second<<" ";
				it++;
				el--;
			}
		
		}
		cout<<endl;
	
	}
	return 0;
}