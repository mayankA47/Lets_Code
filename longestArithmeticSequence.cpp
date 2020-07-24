class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size()<=2)
            return A.size();
        unordered_map<int,unordered_map<int,int>> dp;
        int ans = 2;
        for(int i=1;i<A.size();i++){
            for(int j=0;j<i;j++){
                dp[i][A[i]-A[j]] = max(dp[j][A[i]-A[j]]+1,2);
                ans = max(ans,dp[i][A[i]-A[j]]);
            }
        }
        return ans;
        
    }
};