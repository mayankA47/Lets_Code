#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second
using namespace std;

void solve(string &s,int i)
{
	if(s[i]=='\0'){
		cout<<s<<endl;
		return ;
	}
	for(int j=i;j<s.length();j++)
		if(s[i]==s[j] && i!=j)
			continue;
		else
		{
			swap(s[i],s[j]);
			solve(s,i+1);
			swap(s[i],s[j]);
		}

}

int main(int argc, char const *argv[])
{
	
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	string s;
	cin>>s;
	cout<<"All permutations are:\n";
	solve(s,0);




	
	return 0;
}