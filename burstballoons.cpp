class Solution {
public:
    int dp[505][505];
    int burstballoons(int l,int r,vector<int> &a){
        if(r-l==1)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        for(int i=l+1;i<r;i++)
            dp[l][r] = max(dp[l][r],a[l]*a[i]*a[r]+burstballoons(l,i,a)+burstballoons(i,r,a));
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        vector<int> temp(nums.size()+2);
        temp[0]=temp[nums.size()+1]=1;
        for(int i=0;i<nums.size();i++)
            temp[i+1]=nums[i];
        return burstballoons(0,nums.size()+1,temp);
    }
};