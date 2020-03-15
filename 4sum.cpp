class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> ans;
        if(nums.size()<4)
            return ans;
        sort(nums.begin(),nums.end());
       
        for(int i=0;i<nums.size()-3;i++){
            if(i>0)
                if(nums[i]==nums[i-1])
                    continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1)
                    if(nums[j]==nums[j-1])
                        continue;
                int s,e;
                s=j+1;
                e=nums.size()-1;
                while(s<e){
                    if(nums[i]+nums[j]+nums[s]+nums[e]>target)
                        e--;
                    else if(nums[i]+nums[j]+nums[s]+nums[e]<target)
                        s++;
                    else{
                        ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                        s++;
                        e--;
                        while(nums[s]==nums[s-1] && s<e)
                            s++;
                        while(nums[e]==nums[e+1] && e>s)
                            e--;
                    }
                }
            }
        }
        return ans;
        
    }
};