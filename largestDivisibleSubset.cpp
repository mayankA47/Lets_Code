class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()<=1)
            return nums;
        vector<pair<int,int>> dp(nums.size(),{1,-1});
        sort(nums.begin(),nums.end());
        int maxlen = 0;
        int maxlenid = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i].first<dp[j].first+1){
                        dp[i].first = dp[j].first+1;
                        dp[i].second = j;
                    }
                }
            }
            if(maxlen<dp[i].first)
                maxlen=dp[i].first,maxlenid=i;
        }
        int curid = maxlenid;
        while(curid!=-1){
            ans.push_back(nums[curid]);
            curid = dp[curid].second;
        }
        return ans;
    }
};