class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        unordered_map<ll, set<pair<int,int>>> hash;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                ll currentSum = nums[i] + nums[j];
                ll difference = target - currentSum;
                for (auto &pair: hash[difference]) {
                    vector<int> quadruple = {pair.first, pair.second, nums[i], nums[j]};
                    sort(quadruple.begin(), quadruple.end());
                    ans.insert(quadruple);
                }                
            }
            // add pair sums in hashmap, this is done after jth loop to ensure 
            // quadruples actually contains different elements.
            for (int k = 0; k < i; k++) {
                ll currentSum = nums[k] + nums[i];
                hash[currentSum].insert({nums[k], nums[i]});
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};