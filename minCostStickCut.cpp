class Solution {
public:
   
    int solve(vector<int>&a,int l,int h,int s,int e,vector<vector<int>> &dp){
        if(s>e)
            return 0;
        else if(s==e)
            return h-l;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int ans = INT_MAX;
        for(int i=s;i<=e;i++){
            ans = min(ans,h-l+solve(a,l,a[i],s,i-1,dp)+solve(a,a[i],h,i+1,e,dp));
        }
        return dp[s][e] = ans;
        
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(105,vector<int>(105,-1));
      return solve(cuts,0,n,0,cuts.size()-1,dp);
    }
};