class Solution {
public:
    void subsets(vector<vector<int>> &ans,int i,vector<int> &a,vector<int> &nums){
        if(i==nums.size())
        {
            ans.push_back(a);
            return;
        }
        a.push_back(nums[i]);
        subsets(ans,i+1,a,nums);
        a.pop_back();
        subsets(ans,i+1,a,nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        subsets(ans,0,a,nums);
        return ans;
        
    }
};